/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef mozilla_dom_SVGGraphicsElement_h
#define mozilla_dom_SVGGraphicsElement_h

#include "mozilla/dom/SVGTests.h"
#include "mozilla/dom/SVGTransformableElement.h"

namespace mozilla {
namespace dom {

typedef SVGTransformableElement SVGGraphicsElementBase;

class SVGGraphicsElement : public SVGGraphicsElementBase, public SVGTests {
 protected:
  explicit SVGGraphicsElement(
      already_AddRefed<mozilla::dom::NodeInfo>&& aNodeInfo);
  ~SVGGraphicsElement() = default;

 public:
  // interfaces:
  NS_DECL_ISUPPORTS_INHERITED

  bool IsFocusableInternal(int32_t* aTabIndex, bool aWithMouse) override;
  SVGElement* AsSVGElement() final { return this; }

 protected:
  // returns true if focusability has been definitively determined otherwise
  // false
  bool IsSVGFocusable(bool* aIsFocusable, int32_t* aTabIndex);

  template <typename T>
  bool IsInLengthInfo(const nsAtom* aAttribute, const T& aLengthInfos) const {
    for (auto const& e : aLengthInfos) {
      if (e.mName == aAttribute) {
        return true;
      }
    }
    return false;
  }
};

}  // namespace dom
}  // namespace mozilla

#endif  // mozilla_dom_SVGGraphicsElement_h
