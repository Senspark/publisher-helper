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
#ifndef  GOOGLE_ANDROIDPUBLISHER_API_DEVELOPER_COMMENT_H_
#define  GOOGLE_ANDROIDPUBLISHER_API_DEVELOPER_COMMENT_H_

#include <string>
#include "googleapis/base/macros.h"
#include "googleapis/client/data/jsoncpp_data.h"
#include "googleapis/strings/stringpiece.h"

#include "google/androidpublisher_api/timestamp.h"

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
class DeveloperComment : public client::JsonCppData {
 public:
  /**
   * Creates a new default instance.
   *
   * @return Ownership is passed back to the caller.
   */
  static DeveloperComment* New();

  /**
   * Standard constructor for an immutable data object instance.
   *
   * @param[in] storage  The underlying data storage for this instance.
   */
  explicit DeveloperComment(const Json::Value& storage);

  /**
   * Standard constructor for a mutable data object instance.
   *
   * @param[in] storage  The underlying data storage for this instance.
   */
  explicit DeveloperComment(Json::Value* storage);

  /**
   * Standard destructor.
   */
  virtual ~DeveloperComment();

  /**
   * Returns a string denoting the type of this data object.
   *
   * @return <code>google_androidpublisher_api::DeveloperComment</code>
   */
  const StringPiece GetTypeName() const {
    return StringPiece("google_androidpublisher_api::DeveloperComment");
  }

  /**
   * Determine if the '<code>lastModified</code>' attribute was set.
   *
   * @return true if the '<code>lastModified</code>' attribute was set.
   */
  bool has_last_modified() const {
    return Storage().isMember("lastModified");
  }

  /**
   * Clears the '<code>lastModified</code>' attribute.
   */
  void clear_last_modified() {
    MutableStorage()->removeMember("lastModified");
  }


  /**
   * Get a reference to the value of the '<code>lastModified</code>' attribute.
   */
  const Timestamp get_last_modified() const;

  /**
   * Gets a reference to a mutable value of the '<code>lastModified</code>'
   * property.
   *
   * The last time at which this comment was updated.
   *
   * @return The result can be modified to change the attribute value.
   */
  Timestamp mutable_lastModified();

  /**
   * Determine if the '<code>text</code>' attribute was set.
   *
   * @return true if the '<code>text</code>' attribute was set.
   */
  bool has_text() const {
    return Storage().isMember("text");
  }

  /**
   * Clears the '<code>text</code>' attribute.
   */
  void clear_text() {
    MutableStorage()->removeMember("text");
  }


  /**
   * Get the value of the '<code>text</code>' attribute.
   */
  const StringPiece get_text() const {
    const Json::Value& v = Storage("text");
    if (v == Json::Value::null) return StringPiece("");
    return StringPiece(v.asCString());
  }

  /**
   * Change the '<code>text</code>' attribute.
   *
   * The content of the comment, i.e. reply body.
   *
   * @param[in] value The new value.
   */
  void set_text(const StringPiece& value) {
    *MutableStorage("text") = value.data();
  }

 private:
  void operator=(const DeveloperComment&);
};  // DeveloperComment
}  // namespace google_androidpublisher_api
#endif  // GOOGLE_ANDROIDPUBLISHER_API_DEVELOPER_COMMENT_H_
