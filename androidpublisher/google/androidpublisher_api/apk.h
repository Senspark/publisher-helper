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
#ifndef  GOOGLE_ANDROIDPUBLISHER_API_APK_H_
#define  GOOGLE_ANDROIDPUBLISHER_API_APK_H_

#include "googleapis/base/integral_types.h"
#include "googleapis/base/macros.h"
#include "googleapis/client/data/jsoncpp_data.h"
#include "googleapis/strings/stringpiece.h"

#include "google/androidpublisher_api/apk_binary.h"

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
class Apk : public client::JsonCppData {
 public:
  /**
   * Creates a new default instance.
   *
   * @return Ownership is passed back to the caller.
   */
  static Apk* New();

  /**
   * Standard constructor for an immutable data object instance.
   *
   * @param[in] storage  The underlying data storage for this instance.
   */
  explicit Apk(const Json::Value& storage);

  /**
   * Standard constructor for a mutable data object instance.
   *
   * @param[in] storage  The underlying data storage for this instance.
   */
  explicit Apk(Json::Value* storage);

  /**
   * Standard destructor.
   */
  virtual ~Apk();

  /**
   * Returns a string denoting the type of this data object.
   *
   * @return <code>google_androidpublisher_api::Apk</code>
   */
  const StringPiece GetTypeName() const {
    return StringPiece("google_androidpublisher_api::Apk");
  }

  /**
   * Determine if the '<code>binary</code>' attribute was set.
   *
   * @return true if the '<code>binary</code>' attribute was set.
   */
  bool has_binary() const {
    return Storage().isMember("binary");
  }

  /**
   * Clears the '<code>binary</code>' attribute.
   */
  void clear_binary() {
    MutableStorage()->removeMember("binary");
  }


  /**
   * Get a reference to the value of the '<code>binary</code>' attribute.
   */
  const ApkBinary get_binary() const;

  /**
   * Gets a reference to a mutable value of the '<code>binary</code>' property.
   *
   * Information about the binary payload of this APK.
   *
   * @return The result can be modified to change the attribute value.
   */
  ApkBinary mutable_binary();

  /**
   * Determine if the '<code>versionCode</code>' attribute was set.
   *
   * @return true if the '<code>versionCode</code>' attribute was set.
   */
  bool has_version_code() const {
    return Storage().isMember("versionCode");
  }

  /**
   * Clears the '<code>versionCode</code>' attribute.
   */
  void clear_version_code() {
    MutableStorage()->removeMember("versionCode");
  }


  /**
   * Get the value of the '<code>versionCode</code>' attribute.
   */
  int32 get_version_code() const {
    const Json::Value& storage = Storage("versionCode");
    return client::JsonValueToCppValueHelper<int32 >(storage);
  }

  /**
   * Change the '<code>versionCode</code>' attribute.
   *
   * The version code of the APK, as specified in the APK's manifest file.
   *
   * @param[in] value The new value.
   */
  void set_version_code(int32 value) {
    client::SetJsonValueFromCppValueHelper<int32 >(
      value, MutableStorage("versionCode"));
  }

 private:
  void operator=(const Apk&);
};  // Apk
}  // namespace google_androidpublisher_api
#endif  // GOOGLE_ANDROIDPUBLISHER_API_APK_H_
