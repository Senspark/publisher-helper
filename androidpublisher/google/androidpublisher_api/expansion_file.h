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
#ifndef  GOOGLE_ANDROIDPUBLISHER_API_EXPANSION_FILE_H_
#define  GOOGLE_ANDROIDPUBLISHER_API_EXPANSION_FILE_H_

#include "googleapis/base/integral_types.h"
#include "googleapis/base/macros.h"
#include "googleapis/client/data/jsoncpp_data.h"
#include "googleapis/strings/stringpiece.h"

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
class ExpansionFile : public client::JsonCppData {
 public:
  /**
   * Creates a new default instance.
   *
   * @return Ownership is passed back to the caller.
   */
  static ExpansionFile* New();

  /**
   * Standard constructor for an immutable data object instance.
   *
   * @param[in] storage  The underlying data storage for this instance.
   */
  explicit ExpansionFile(const Json::Value& storage);

  /**
   * Standard constructor for a mutable data object instance.
   *
   * @param[in] storage  The underlying data storage for this instance.
   */
  explicit ExpansionFile(Json::Value* storage);

  /**
   * Standard destructor.
   */
  virtual ~ExpansionFile();

  /**
   * Returns a string denoting the type of this data object.
   *
   * @return <code>google_androidpublisher_api::ExpansionFile</code>
   */
  const StringPiece GetTypeName() const {
    return StringPiece("google_androidpublisher_api::ExpansionFile");
  }

  /**
   * Determine if the '<code>fileSize</code>' attribute was set.
   *
   * @return true if the '<code>fileSize</code>' attribute was set.
   */
  bool has_file_size() const {
    return Storage().isMember("fileSize");
  }

  /**
   * Clears the '<code>fileSize</code>' attribute.
   */
  void clear_file_size() {
    MutableStorage()->removeMember("fileSize");
  }


  /**
   * Get the value of the '<code>fileSize</code>' attribute.
   */
  int64 get_file_size() const {
    const Json::Value& storage = Storage("fileSize");
    return client::JsonValueToCppValueHelper<int64 >(storage);
  }

  /**
   * Change the '<code>fileSize</code>' attribute.
   *
   * If set this field indicates that this APK has an Expansion File uploaded to
   * it: this APK does not reference another APK's Expansion File. The field's
   * value is the size of the uploaded Expansion File in bytes.
   *
   * @param[in] value The new value.
   */
  void set_file_size(int64 value) {
    client::SetJsonValueFromCppValueHelper<int64 >(
      value, MutableStorage("fileSize"));
  }

  /**
   * Determine if the '<code>referencesVersion</code>' attribute was set.
   *
   * @return true if the '<code>referencesVersion</code>' attribute was set.
   */
  bool has_references_version() const {
    return Storage().isMember("referencesVersion");
  }

  /**
   * Clears the '<code>referencesVersion</code>' attribute.
   */
  void clear_references_version() {
    MutableStorage()->removeMember("referencesVersion");
  }


  /**
   * Get the value of the '<code>referencesVersion</code>' attribute.
   */
  int32 get_references_version() const {
    const Json::Value& storage = Storage("referencesVersion");
    return client::JsonValueToCppValueHelper<int32 >(storage);
  }

  /**
   * Change the '<code>referencesVersion</code>' attribute.
   *
   * If set this APK's Expansion File references another APK's Expansion File.
   * The file_size field will not be set.
   *
   * @param[in] value The new value.
   */
  void set_references_version(int32 value) {
    client::SetJsonValueFromCppValueHelper<int32 >(
      value, MutableStorage("referencesVersion"));
  }

 private:
  void operator=(const ExpansionFile&);
};  // ExpansionFile
}  // namespace google_androidpublisher_api
#endif  // GOOGLE_ANDROIDPUBLISHER_API_EXPANSION_FILE_H_
