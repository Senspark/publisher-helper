// Copyright 2010 Google Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License"); you may not
// use this file except in compliance with the License. You may obtain a copy of
// the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
// WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the
// License for the specific language governing permissions and limitations under
// the License.

// This code was generated by google-apis-code-generator 1.5.1
//   Build date: 2017-02-15 17:18:02 UTC
//   on: 2017-08-09, 13:29:24 UTC
//   C++ generator version: 0.1.4

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   Google Play Developer API (androidpublisher/v2)
// Generated from:
//   Version: v2
//   Revision: 45
// Generated by:
//    Tool: google-apis-code-generator 1.5.1
//     C++: 0.1.4
#ifndef  GOOGLE_ANDROIDPUBLISHER_API_PRORATE_H_
#define  GOOGLE_ANDROIDPUBLISHER_API_PRORATE_H_

#include "googleapis/base/macros.h"
#include "googleapis/client/data/jsoncpp_data.h"
#include "googleapis/strings/stringpiece.h"

#include "google/androidpublisher_api/month_day.h"
#include "google/androidpublisher_api/price.h"

namespace Json {
class Value;
}  // namespace Json

namespace google_androidpublisher_api {
using namespace googleapis;

/**
 * No description provided.
 *
 * @ingroup DataObject
 */
class Prorate : public client::JsonCppData {
 public:
  /**
   * Creates a new default instance.
   *
   * @return Ownership is passed back to the caller.
   */
  static Prorate* New();

  /**
   * Standard constructor for an immutable data object instance.
   *
   * @param[in] storage  The underlying data storage for this instance.
   */
  explicit Prorate(const Json::Value& storage);

  /**
   * Standard constructor for a mutable data object instance.
   *
   * @param[in] storage  The underlying data storage for this instance.
   */
  explicit Prorate(Json::Value* storage);

  /**
   * Standard destructor.
   */
  virtual ~Prorate();

  /**
   * Returns a string denoting the type of this data object.
   *
   * @return <code>google_androidpublisher_api::Prorate</code>
   */
  const StringPiece GetTypeName() const {
    return StringPiece("google_androidpublisher_api::Prorate");
  }

  /**
   * Determine if the '<code>defaultPrice</code>' attribute was set.
   *
   * @return true if the '<code>defaultPrice</code>' attribute was set.
   */
  bool has_default_price() const {
    return Storage().isMember("defaultPrice");
  }

  /**
   * Clears the '<code>defaultPrice</code>' attribute.
   */
  void clear_default_price() {
    MutableStorage()->removeMember("defaultPrice");
  }


  /**
   * Get a reference to the value of the '<code>defaultPrice</code>' attribute.
   */
  const Price get_default_price() const;

  /**
   * Gets a reference to a mutable value of the '<code>defaultPrice</code>'
   * property.
   *
   * Default price cannot be zero and must be less than the full subscription
   * price. Default price is always in the developer's Checkout merchant
   * currency. Targeted countries have their prices set automatically based on
   * the default_price.
   *
   * @return The result can be modified to change the attribute value.
   */
  Price mutable_defaultPrice();

  /**
   * Determine if the '<code>start</code>' attribute was set.
   *
   * @return true if the '<code>start</code>' attribute was set.
   */
  bool has_start() const {
    return Storage().isMember("start");
  }

  /**
   * Clears the '<code>start</code>' attribute.
   */
  void clear_start() {
    MutableStorage()->removeMember("start");
  }


  /**
   * Get a reference to the value of the '<code>start</code>' attribute.
   */
  const MonthDay get_start() const;

  /**
   * Gets a reference to a mutable value of the '<code>start</code>' property.
   *
   * Defines the first day on which the price takes effect.
   *
   * @return The result can be modified to change the attribute value.
   */
  MonthDay mutable_start();

 private:
  void operator=(const Prorate&);
};  // Prorate
}  // namespace google_androidpublisher_api
#endif  // GOOGLE_ANDROIDPUBLISHER_API_PRORATE_H_
