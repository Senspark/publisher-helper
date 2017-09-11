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

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   Calendar API (calendar/v3)
// Generated from:
//   Version: v3
//   Revision: 20170507
// Generated by:
//    Tool: google-apis-code-generator 1.5.1
//     C++: 0.1.4
#ifndef  GOOGLE_CALENDAR_API_FREE_BUSY_GROUP_H_
#define  GOOGLE_CALENDAR_API_FREE_BUSY_GROUP_H_

#include <string>
#include "googleapis/base/macros.h"
#include "googleapis/client/data/jsoncpp_data.h"
#include "googleapis/strings/stringpiece.h"

#include "google/calendar_api/error.h"

namespace Json {
class Value;
}  // namespace Json

namespace google_calendar_api {
using namespace googleapis;

/**
 * No description provided.
 *
 * @ingroup DataObject
 */
class FreeBusyGroup : public client::JsonCppData {
 public:
  /**
   * Creates a new default instance.
   *
   * @return Ownership is passed back to the caller.
   */
  static FreeBusyGroup* New();

  /**
   * Standard constructor for an immutable data object instance.
   *
   * @param[in] storage  The underlying data storage for this instance.
   */
  explicit FreeBusyGroup(const Json::Value& storage);

  /**
   * Standard constructor for a mutable data object instance.
   *
   * @param[in] storage  The underlying data storage for this instance.
   */
  explicit FreeBusyGroup(Json::Value* storage);

  /**
   * Standard destructor.
   */
  virtual ~FreeBusyGroup();

  /**
   * Returns a string denoting the type of this data object.
   *
   * @return <code>google_calendar_api::FreeBusyGroup</code>
   */
  const StringPiece GetTypeName() const {
    return StringPiece("google_calendar_api::FreeBusyGroup");
  }

  /**
   * Determine if the '<code>calendars</code>' attribute was set.
   *
   * @return true if the '<code>calendars</code>' attribute was set.
   */
  bool has_calendars() const {
    return Storage().isMember("calendars");
  }

  /**
   * Clears the '<code>calendars</code>' attribute.
   */
  void clear_calendars() {
    MutableStorage()->removeMember("calendars");
  }


  /**
   * Get a reference to the value of the '<code>calendars</code>' attribute.
   */
  const client::JsonCppArray<string > get_calendars() const {
     const Json::Value& storage = Storage("calendars");
    return client::JsonValueToCppValueHelper<client::JsonCppArray<string > >(storage);
  }

  /**
   * Gets a reference to a mutable value of the '<code>calendars</code>'
   * property.
   *
   * List of calendars' identifiers within a group.
   *
   * @return The result can be modified to change the attribute value.
   */
  client::JsonCppArray<string > mutable_calendars() {
    Json::Value* storage = MutableStorage("calendars");
    return client::JsonValueToMutableCppValueHelper<client::JsonCppArray<string > >(storage);
  }

  /**
   * Determine if the '<code>errors</code>' attribute was set.
   *
   * @return true if the '<code>errors</code>' attribute was set.
   */
  bool has_errors() const {
    return Storage().isMember("errors");
  }

  /**
   * Clears the '<code>errors</code>' attribute.
   */
  void clear_errors() {
    MutableStorage()->removeMember("errors");
  }


  /**
   * Get a reference to the value of the '<code>errors</code>' attribute.
   */
  const client::JsonCppArray<Error > get_errors() const;

  /**
   * Gets a reference to a mutable value of the '<code>errors</code>' property.
   *
   * Optional error(s) (if computation for the group failed).
   *
   * @return The result can be modified to change the attribute value.
   */
  client::JsonCppArray<Error > mutable_errors();

 private:
  void operator=(const FreeBusyGroup&);
};  // FreeBusyGroup
}  // namespace google_calendar_api
#endif  // GOOGLE_CALENDAR_API_FREE_BUSY_GROUP_H_
