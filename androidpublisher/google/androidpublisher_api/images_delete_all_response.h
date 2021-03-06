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
#ifndef  GOOGLE_ANDROIDPUBLISHER_API_IMAGES_DELETE_ALL_RESPONSE_H_
#define  GOOGLE_ANDROIDPUBLISHER_API_IMAGES_DELETE_ALL_RESPONSE_H_

#include "googleapis/base/macros.h"
#include "googleapis/client/data/jsoncpp_data.h"
#include "googleapis/strings/stringpiece.h"

#include "google/androidpublisher_api/image.h"

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
class ImagesDeleteAllResponse : public client::JsonCppData {
 public:
  /**
   * Creates a new default instance.
   *
   * @return Ownership is passed back to the caller.
   */
  static ImagesDeleteAllResponse* New();

  /**
   * Standard constructor for an immutable data object instance.
   *
   * @param[in] storage  The underlying data storage for this instance.
   */
  explicit ImagesDeleteAllResponse(const Json::Value& storage);

  /**
   * Standard constructor for a mutable data object instance.
   *
   * @param[in] storage  The underlying data storage for this instance.
   */
  explicit ImagesDeleteAllResponse(Json::Value* storage);

  /**
   * Standard destructor.
   */
  virtual ~ImagesDeleteAllResponse();

  /**
   * Returns a string denoting the type of this data object.
   *
   * @return <code>google_androidpublisher_api::ImagesDeleteAllResponse</code>
   */
  const StringPiece GetTypeName() const {
    return StringPiece("google_androidpublisher_api::ImagesDeleteAllResponse");
  }

  /**
   * Determine if the '<code>deleted</code>' attribute was set.
   *
   * @return true if the '<code>deleted</code>' attribute was set.
   */
  bool has_deleted() const {
    return Storage().isMember("deleted");
  }

  /**
   * Clears the '<code>deleted</code>' attribute.
   */
  void clear_deleted() {
    MutableStorage()->removeMember("deleted");
  }


  /**
   * Get a reference to the value of the '<code>deleted</code>' attribute.
   */
  const client::JsonCppArray<Image > get_deleted() const;

  /**
   * Gets a reference to a mutable value of the '<code>deleted</code>' property.
   * @return The result can be modified to change the attribute value.
   */
  client::JsonCppArray<Image > mutable_deleted();

 private:
  void operator=(const ImagesDeleteAllResponse&);
};  // ImagesDeleteAllResponse
}  // namespace google_androidpublisher_api
#endif  // GOOGLE_ANDROIDPUBLISHER_API_IMAGES_DELETE_ALL_RESPONSE_H_
