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
#ifndef  GOOGLE_ANDROIDPUBLISHER_API_INAPPPRODUCTS_BATCH_REQUEST_ENTRY_H_
#define  GOOGLE_ANDROIDPUBLISHER_API_INAPPPRODUCTS_BATCH_REQUEST_ENTRY_H_

#include <string>
#include "googleapis/base/integral_types.h"
#include "googleapis/base/macros.h"
#include "googleapis/client/data/jsoncpp_data.h"
#include "googleapis/strings/stringpiece.h"

#include "google/androidpublisher_api/inappproducts_insert_request.h"
#include "google/androidpublisher_api/inappproducts_update_request.h"

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
class InappproductsBatchRequestEntry : public client::JsonCppData {
 public:
  /**
   * Creates a new default instance.
   *
   * @return Ownership is passed back to the caller.
   */
  static InappproductsBatchRequestEntry* New();

  /**
   * Standard constructor for an immutable data object instance.
   *
   * @param[in] storage  The underlying data storage for this instance.
   */
  explicit InappproductsBatchRequestEntry(const Json::Value& storage);

  /**
   * Standard constructor for a mutable data object instance.
   *
   * @param[in] storage  The underlying data storage for this instance.
   */
  explicit InappproductsBatchRequestEntry(Json::Value* storage);

  /**
   * Standard destructor.
   */
  virtual ~InappproductsBatchRequestEntry();

  /**
   * Returns a string denoting the type of this data object.
   *
   * @return
   * <code>google_androidpublisher_api::InappproductsBatchRequestEntry</code>
   */
  const StringPiece GetTypeName() const {
    return StringPiece("google_androidpublisher_api::InappproductsBatchRequestEntry");
  }

  /**
   * Determine if the '<code>batchId</code>' attribute was set.
   *
   * @return true if the '<code>batchId</code>' attribute was set.
   */
  bool has_batch_id() const {
    return Storage().isMember("batchId");
  }

  /**
   * Clears the '<code>batchId</code>' attribute.
   */
  void clear_batch_id() {
    MutableStorage()->removeMember("batchId");
  }


  /**
   * Get the value of the '<code>batchId</code>' attribute.
   */
  uint32 get_batch_id() const {
    const Json::Value& storage = Storage("batchId");
    return client::JsonValueToCppValueHelper<uint32 >(storage);
  }

  /**
   * Change the '<code>batchId</code>' attribute.
   * @param[in] value The new value.
   */
  void set_batch_id(uint32 value) {
    client::SetJsonValueFromCppValueHelper<uint32 >(
      value, MutableStorage("batchId"));
  }

  /**
   * Determine if the '<code>inappproductsinsertrequest</code>' attribute was
   * set.
   *
   * @return true if the '<code>inappproductsinsertrequest</code>' attribute was
   * set.
   */
  bool has_inappproductsinsertrequest() const {
    return Storage().isMember("inappproductsinsertrequest");
  }

  /**
   * Clears the '<code>inappproductsinsertrequest</code>' attribute.
   */
  void clear_inappproductsinsertrequest() {
    MutableStorage()->removeMember("inappproductsinsertrequest");
  }


  /**
   * Get a reference to the value of the
   * '<code>inappproductsinsertrequest</code>' attribute.
   */
  const InappproductsInsertRequest get_inappproductsinsertrequest() const;

  /**
   * Gets a reference to a mutable value of the
   * '<code>inappproductsinsertrequest</code>' property.
   * @return The result can be modified to change the attribute value.
   */
  InappproductsInsertRequest mutable_inappproductsinsertrequest();

  /**
   * Determine if the '<code>inappproductsupdaterequest</code>' attribute was
   * set.
   *
   * @return true if the '<code>inappproductsupdaterequest</code>' attribute was
   * set.
   */
  bool has_inappproductsupdaterequest() const {
    return Storage().isMember("inappproductsupdaterequest");
  }

  /**
   * Clears the '<code>inappproductsupdaterequest</code>' attribute.
   */
  void clear_inappproductsupdaterequest() {
    MutableStorage()->removeMember("inappproductsupdaterequest");
  }


  /**
   * Get a reference to the value of the
   * '<code>inappproductsupdaterequest</code>' attribute.
   */
  const InappproductsUpdateRequest get_inappproductsupdaterequest() const;

  /**
   * Gets a reference to a mutable value of the
   * '<code>inappproductsupdaterequest</code>' property.
   * @return The result can be modified to change the attribute value.
   */
  InappproductsUpdateRequest mutable_inappproductsupdaterequest();

  /**
   * Determine if the '<code>methodName</code>' attribute was set.
   *
   * @return true if the '<code>methodName</code>' attribute was set.
   */
  bool has_method_name() const {
    return Storage().isMember("methodName");
  }

  /**
   * Clears the '<code>methodName</code>' attribute.
   */
  void clear_method_name() {
    MutableStorage()->removeMember("methodName");
  }


  /**
   * Get the value of the '<code>methodName</code>' attribute.
   */
  const StringPiece get_method_name() const {
    const Json::Value& v = Storage("methodName");
    if (v == Json::Value::null) return StringPiece("");
    return StringPiece(v.asCString());
  }

  /**
   * Change the '<code>methodName</code>' attribute.
   * @param[in] value The new value.
   */
  void set_method_name(const StringPiece& value) {
    *MutableStorage("methodName") = value.data();
  }

 private:
  void operator=(const InappproductsBatchRequestEntry&);
};  // InappproductsBatchRequestEntry
}  // namespace google_androidpublisher_api
#endif  // GOOGLE_ANDROIDPUBLISHER_API_INAPPPRODUCTS_BATCH_REQUEST_ENTRY_H_
