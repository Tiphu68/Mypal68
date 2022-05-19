/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "nsCache.h"
#include "nsCacheUtils.h"
#include "nsThreadUtils.h"

using namespace mozilla;

class nsDestroyThreadEvent : public Runnable {
 public:
  explicit nsDestroyThreadEvent(nsIThread* thread)
      : mozilla::Runnable("nsDestroyThreadEvent"), mThread(thread) {}
  NS_IMETHOD Run() override {
    mThread->Shutdown();
    return NS_OK;
  }

 private:
  nsCOMPtr<nsIThread> mThread;
};

nsShutdownThread::nsShutdownThread(nsIThread* aThread)
    : mozilla::Runnable("nsShutdownThread"),
      mMonitor("nsShutdownThread.mMonitor"),
      mShuttingDown(false),
      mThread(aThread) {}

nsresult nsShutdownThread::Shutdown(nsIThread* aThread) {
  nsresult rv;
  RefPtr<nsDestroyThreadEvent> ev = new nsDestroyThreadEvent(aThread);
  rv = NS_DispatchToMainThread(ev);
  if (NS_FAILED(rv)) {
    NS_WARNING("Dispatching event in nsShutdownThread::Shutdown failed!");
  }
  return rv;
}

nsresult nsShutdownThread::BlockingShutdown(nsIThread* aThread) {
  nsresult rv;

  RefPtr<nsShutdownThread> st = new nsShutdownThread(aThread);
  nsCOMPtr<nsIThread> workerThread;

  rv = NS_NewNamedThread("thread shutdown", getter_AddRefs(workerThread));
  if (NS_FAILED(rv)) {
    NS_WARNING("Can't create nsShutDownThread worker thread!");
    return rv;
  }

  {
    Monitor2AutoLock mon(st->mMonitor);
    rv = workerThread->Dispatch(st, NS_DISPATCH_NORMAL);
    if (NS_FAILED(rv)) {
      NS_WARNING(
          "Dispatching event in nsShutdownThread::BlockingShutdown failed!");
    } else {
      st->mShuttingDown = true;
      while (st->mShuttingDown) {
        mon.Wait();
      }
    }
  }

  return Shutdown(workerThread);
}

NS_IMETHODIMP
nsShutdownThread::Run() {
  Monitor2AutoLock mon(mMonitor);
  mThread->Shutdown();
  mShuttingDown = false;
  mon.Signal();
  return NS_OK;
}