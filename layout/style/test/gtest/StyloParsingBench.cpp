/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "gtest/gtest.h"
#include "gtest/MozGTestBench.h"
#include "nsString.h"
#include "ExampleStylesheet.h"
#include "ServoBindings.h"
#include "mozilla/Encoding.h"
#include "mozilla/NullPrincipalURI.h"
#include "mozilla/css/SheetParsingMode.h"
#include "mozilla/net/ReferrerPolicy.h"
#include "nsCSSValue.h"

using namespace mozilla;
using namespace mozilla::css;
using namespace mozilla::dom;
using namespace mozilla::net;

// Bug 1436018 - Disable Stylo microbenchmark on Windows
#if !defined(_WIN32) && !defined(_WIN64)

#  define PARSING_REPETITIONS 20
#  define SETPROPERTY_REPETITIONS (1000 * 1000)
#  define GETPROPERTY_REPETITIONS (1000 * 1000)

static void ServoParsingBench(const StyleUseCounters* aCounters) {
  auto css = AsBytes(MakeStringSpan(EXAMPLE_STYLESHEET));
  nsCString cssStr;
  cssStr.Append(css);
  ASSERT_EQ(Encoding::UTF8ValidUpTo(css), css.Length());

  RefPtr<URLExtraData> data = new URLExtraData(
      NullPrincipalURI::Create(), nullptr,
      NullPrincipal::CreateWithoutOriginAttributes(), mozilla::net::RP_Unset);
  for (int i = 0; i < PARSING_REPETITIONS; i++) {
    RefPtr<RawServoStyleSheetContents> stylesheet =
        Servo_StyleSheet_FromUTF8Bytes(
            nullptr, nullptr, nullptr, &cssStr, eAuthorSheetFeatures, data, 0,
            eCompatibility_FullStandards, nullptr, aCounters,
            StyleSanitizationKind::None, nullptr)
            .Consume();
  }
}

static void ServoSetPropertyByIdBench(const nsACString& css) {
  RefPtr<RawServoDeclarationBlock> block =
      Servo_DeclarationBlock_CreateEmpty().Consume();
  RefPtr<URLExtraData> data = new URLExtraData(
      NullPrincipalURI::Create(), nullptr,
      NullPrincipal::CreateWithoutOriginAttributes(), mozilla::net::RP_Unset);
  ASSERT_TRUE(IsUTF8(css));

  for (int i = 0; i < SETPROPERTY_REPETITIONS; i++) {
    Servo_DeclarationBlock_SetPropertyById(
        block, eCSSProperty_width, &css,
        /* is_important = */ false, data, ParsingMode::Default,
        eCompatibility_FullStandards, nullptr, {});
  }
}

static void ServoGetPropertyValueById() {
  RefPtr<RawServoDeclarationBlock> block =
      Servo_DeclarationBlock_CreateEmpty().Consume();
  RefPtr<URLExtraData> data = new URLExtraData(
      NullPrincipalURI::Create(), nullptr,
      NullPrincipal::CreateWithoutOriginAttributes(), mozilla::net::RP_Unset);
  NS_NAMED_LITERAL_CSTRING(css_, "10px");
  const nsACString& css = css_;
  Servo_DeclarationBlock_SetPropertyById(
      block, eCSSProperty_width, &css,
      /* is_important = */ false, data, ParsingMode::Default,
      eCompatibility_FullStandards, nullptr, {});

  for (int i = 0; i < GETPROPERTY_REPETITIONS; i++) {
    DOMString value_;
    nsAString& value = value_;
    Servo_DeclarationBlock_GetPropertyValueById(block, eCSSProperty_width,
                                                &value);
    ASSERT_TRUE(value.EqualsLiteral("10px"));
  }
}

MOZ_GTEST_BENCH(Stylo, Servo_StyleSheet_FromUTF8Bytes_Bench,
                [] { ServoParsingBench(nullptr); });

MOZ_GTEST_BENCH(Stylo, Servo_StyleSheet_FromUTF8Bytes_Bench_UseCounters, [] {
  UniquePtr<StyleUseCounters> counters = Servo_UseCounters_Create().Consume();
  ServoParsingBench(counters.get());
});

MOZ_GTEST_BENCH(Stylo, Servo_DeclarationBlock_SetPropertyById_Bench,
                [] { ServoSetPropertyByIdBench(NS_LITERAL_CSTRING("10px")); });

MOZ_GTEST_BENCH(Stylo,
                Servo_DeclarationBlock_SetPropertyById_WithInitialSpace_Bench,
                [] { ServoSetPropertyByIdBench(NS_LITERAL_CSTRING(" 10px")); });

MOZ_GTEST_BENCH(Stylo, Servo_DeclarationBlock_GetPropertyById_Bench,
                ServoGetPropertyValueById);

#endif