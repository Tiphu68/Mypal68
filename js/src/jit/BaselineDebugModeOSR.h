/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef jit_BaselineDebugModeOSR_h
#define jit_BaselineDebugModeOSR_h

#include "debugger/DebugAPI.h"
#include "jit/BaselineFrame.h"
#include "jit/BaselineIC.h"
#include "jit/BaselineJIT.h"
#include "jit/JSJitFrameIter.h"

namespace js {
namespace jit {

// Note that this file and the corresponding .cpp implement debug mode
// on-stack recompilation. This is to be distinguished from ordinary
// Baseline->Ion OSR, which is used to jump into compiled loops.

MOZ_MUST_USE bool RecompileOnStackBaselineScriptsForDebugMode(
    JSContext* cx, const DebugAPI::ExecutionObservableSet& obs,
    DebugAPI::IsObserving observing);

}  // namespace jit
}  // namespace js

#endif  // jit_BaselineDebugModeOSR_h
