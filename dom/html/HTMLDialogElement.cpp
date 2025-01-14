/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "mozilla/dom/HTMLDialogElement.h"
#include "mozilla/dom/HTMLDialogElementBinding.h"
#include "mozilla/dom/HTMLUnknownElement.h"
#include "mozilla/StaticPrefs_dom.h"

// Expand NS_IMPL_NS_NEW_HTML_ELEMENT(Dialog) with pref check
nsGenericHTMLElement* NS_NewHTMLDialogElement(
    already_AddRefed<mozilla::dom::NodeInfo>&& aNodeInfo,
    mozilla::dom::FromParser aFromParser) {
  RefPtr<mozilla::dom::NodeInfo> nodeInfo(aNodeInfo);
  auto* nim = nodeInfo->NodeInfoManager();
  if (!mozilla::dom::HTMLDialogElement::IsDialogEnabled()) {
    return new (nim) mozilla::dom::HTMLUnknownElement(nodeInfo.forget());
  }

  return new (nim) mozilla::dom::HTMLDialogElement(nodeInfo.forget());
}

namespace mozilla {
namespace dom {

HTMLDialogElement::~HTMLDialogElement() = default;

NS_IMPL_ELEMENT_CLONE(HTMLDialogElement)

bool HTMLDialogElement::IsDialogEnabled() {
  return StaticPrefs::dom_dialog_element_enabled();
}

void HTMLDialogElement::Close(
    const mozilla::dom::Optional<nsAString>& aReturnValue) {
  if (!Open()) {
    return;
  }
  if (aReturnValue.WasPassed()) {
    SetReturnValue(aReturnValue.Value());
  }
  ErrorResult ignored;
  SetOpen(false, ignored);
  ignored.SuppressException();

  RemoveFromTopLayerIfNeeded();

  RefPtr<AsyncEventDispatcher> eventDispatcher = new AsyncEventDispatcher(
      this, NS_LITERAL_STRING("close"), CanBubble::eNo);
  eventDispatcher->PostDOMEvent();
}

void HTMLDialogElement::Show() {
  if (Open()) {
    return;
  }
  ErrorResult ignored;
  SetOpen(true, ignored);
  ignored.SuppressException();
}

bool HTMLDialogElement::IsInTopLayer() const {
  return State().HasState(NS_EVENT_STATE_MODAL_DIALOG);
}

void HTMLDialogElement::RemoveFromTopLayerIfNeeded() {
  if (!IsInTopLayer()) {
    return;
  }
  auto predictFunc = [&](Element* element) { return element == this; };

  DebugOnly<Element*> removedElement = OwnerDoc()->TopLayerPop(predictFunc);
  MOZ_ASSERT(removedElement == this);
  RemoveStates(NS_EVENT_STATE_MODAL_DIALOG);
}

void HTMLDialogElement::UnbindFromTree(bool aNullParent) {
  RemoveFromTopLayerIfNeeded();
  nsGenericHTMLElement::UnbindFromTree(aNullParent);
}

void HTMLDialogElement::ShowModal(ErrorResult& aError) {
  if (!IsInComposedDoc() || Open()) {
    aError.Throw(NS_ERROR_DOM_INVALID_STATE_ERR);
    return;
  }

  if (!IsInTopLayer() && OwnerDoc()->TopLayerPush(this)) {
    AddStates(NS_EVENT_STATE_MODAL_DIALOG);
  }

  SetOpen(true, aError);
  aError.SuppressException();
}

JSObject* HTMLDialogElement::WrapNode(JSContext* aCx,
                                      JS::Handle<JSObject*> aGivenProto) {
  return HTMLDialogElement_Binding::Wrap(aCx, this, aGivenProto);
}

}  // namespace dom
}  // namespace mozilla
