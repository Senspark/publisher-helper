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
#ifndef  GOOGLE_CALENDAR_API_EVENTS_H_
#define  GOOGLE_CALENDAR_API_EVENTS_H_

#include <string>
#include "googleapis/base/macros.h"
#include "googleapis/client/data/jsoncpp_data.h"
#include "googleapis/client/util/date_time.h"
#include "googleapis/strings/stringpiece.h"

#include "google/calendar_api/event.h"
#include "google/calendar_api/event_reminder.h"

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
class Events : public client::JsonCppData {
 public:
  /**
   * Creates a new default instance.
   *
   * @return Ownership is passed back to the caller.
   */
  static Events* New();

  /**
   * Standard constructor for an immutable data object instance.
   *
   * @param[in] storage  The underlying data storage for this instance.
   */
  explicit Events(const Json::Value& storage);

  /**
   * Standard constructor for a mutable data object instance.
   *
   * @param[in] storage  The underlying data storage for this instance.
   */
  explicit Events(Json::Value* storage);

  /**
   * Standard destructor.
   */
  virtual ~Events();

  /**
   * Returns a string denoting the type of this data object.
   *
   * @return <code>google_calendar_api::Events</code>
   */
  const StringPiece GetTypeName() const {
    return StringPiece("google_calendar_api::Events");
  }

  /**
   * Determine if the '<code>accessRole</code>' attribute was set.
   *
   * @return true if the '<code>accessRole</code>' attribute was set.
   */
  bool has_access_role() const {
    return Storage().isMember("accessRole");
  }

  /**
   * Clears the '<code>accessRole</code>' attribute.
   */
  void clear_access_role() {
    MutableStorage()->removeMember("accessRole");
  }


  /**
   * Get the value of the '<code>accessRole</code>' attribute.
   */
  const StringPiece get_access_role() const {
    const Json::Value& v = Storage("accessRole");
    if (v == Json::Value::null) return StringPiece("");
    return StringPiece(v.asCString());
  }

  /**
   * Change the '<code>accessRole</code>' attribute.
   *
   * The user's access role for this calendar. Read-only. Possible values are:
   * <dl>
   * <dt>"none"
   * <dd>The user has no access.
   * <dt>"freeBusyReader"
   * <dd>The user has read access to free/busy information.
   * <dt>"reader"
   * <dd>The user has read access to the calendar. Private events will appear to
   * users with reader access, but event details will be hidden.
   * <dt>"writer"
   * <dd>The user has read and write access to the calendar. Private events will
   * appear to users with writer access, and event details will be visible.
   * <dt>"owner"
   * <dd>The user has ownership of the calendar. This role has all of the
   * permissions of the writer role with the additional ability to see and
   * manipulate ACLs.
   * </dl>
   *
   *
   * @param[in] value The new value.
   */
  void set_access_role(const StringPiece& value) {
    *MutableStorage("accessRole") = value.data();
  }

  /**
   * Determine if the '<code>defaultReminders</code>' attribute was set.
   *
   * @return true if the '<code>defaultReminders</code>' attribute was set.
   */
  bool has_default_reminders() const {
    return Storage().isMember("defaultReminders");
  }

  /**
   * Clears the '<code>defaultReminders</code>' attribute.
   */
  void clear_default_reminders() {
    MutableStorage()->removeMember("defaultReminders");
  }


  /**
   * Get a reference to the value of the '<code>defaultReminders</code>'
   * attribute.
   */
  const client::JsonCppArray<EventReminder > get_default_reminders() const;

  /**
   * Gets a reference to a mutable value of the '<code>defaultReminders</code>'
   * property.
   *
   * The default reminders on the calendar for the authenticated user. These
   * reminders apply to all events on this calendar that do not explicitly
   * override them (i.e. do not have reminders.useDefault set to True).
   *
   * @return The result can be modified to change the attribute value.
   */
  client::JsonCppArray<EventReminder > mutable_defaultReminders();

  /**
   * Determine if the '<code>description</code>' attribute was set.
   *
   * @return true if the '<code>description</code>' attribute was set.
   */
  bool has_description() const {
    return Storage().isMember("description");
  }

  /**
   * Clears the '<code>description</code>' attribute.
   */
  void clear_description() {
    MutableStorage()->removeMember("description");
  }


  /**
   * Get the value of the '<code>description</code>' attribute.
   */
  const StringPiece get_description() const {
    const Json::Value& v = Storage("description");
    if (v == Json::Value::null) return StringPiece("");
    return StringPiece(v.asCString());
  }

  /**
   * Change the '<code>description</code>' attribute.
   *
   * Description of the calendar. Read-only.
   *
   * @param[in] value The new value.
   */
  void set_description(const StringPiece& value) {
    *MutableStorage("description") = value.data();
  }

  /**
   * Determine if the '<code>etag</code>' attribute was set.
   *
   * @return true if the '<code>etag</code>' attribute was set.
   */
  bool has_etag() const {
    return Storage().isMember("etag");
  }

  /**
   * Clears the '<code>etag</code>' attribute.
   */
  void clear_etag() {
    MutableStorage()->removeMember("etag");
  }


  /**
   * Get the value of the '<code>etag</code>' attribute.
   */
  const StringPiece get_etag() const {
    const Json::Value& v = Storage("etag");
    if (v == Json::Value::null) return StringPiece("");
    return StringPiece(v.asCString());
  }

  /**
   * Change the '<code>etag</code>' attribute.
   *
   * ETag of the collection.
   *
   * @param[in] value The new value.
   */
  void set_etag(const StringPiece& value) {
    *MutableStorage("etag") = value.data();
  }

  /**
   * Determine if the '<code>items</code>' attribute was set.
   *
   * @return true if the '<code>items</code>' attribute was set.
   */
  bool has_items() const {
    return Storage().isMember("items");
  }

  /**
   * Clears the '<code>items</code>' attribute.
   */
  void clear_items() {
    MutableStorage()->removeMember("items");
  }


  /**
   * Get a reference to the value of the '<code>items</code>' attribute.
   */
  const client::JsonCppArray<Event > get_items() const;

  /**
   * Gets a reference to a mutable value of the '<code>items</code>' property.
   *
   * List of events on the calendar.
   *
   * @return The result can be modified to change the attribute value.
   */
  client::JsonCppArray<Event > mutable_items();

  /**
   * Determine if the '<code>kind</code>' attribute was set.
   *
   * @return true if the '<code>kind</code>' attribute was set.
   */
  bool has_kind() const {
    return Storage().isMember("kind");
  }

  /**
   * Clears the '<code>kind</code>' attribute.
   */
  void clear_kind() {
    MutableStorage()->removeMember("kind");
  }


  /**
   * Get the value of the '<code>kind</code>' attribute.
   */
  const StringPiece get_kind() const {
    const Json::Value& v = Storage("kind");
    if (v == Json::Value::null) return StringPiece("");
    return StringPiece(v.asCString());
  }

  /**
   * Change the '<code>kind</code>' attribute.
   *
   * Type of the collection ("calendar#events").
   *
   * @param[in] value The new value.
   */
  void set_kind(const StringPiece& value) {
    *MutableStorage("kind") = value.data();
  }

  /**
   * Determine if the '<code>nextPageToken</code>' attribute was set.
   *
   * @return true if the '<code>nextPageToken</code>' attribute was set.
   */
  bool has_next_page_token() const {
    return Storage().isMember("nextPageToken");
  }

  /**
   * Clears the '<code>nextPageToken</code>' attribute.
   */
  void clear_next_page_token() {
    MutableStorage()->removeMember("nextPageToken");
  }


  /**
   * Get the value of the '<code>nextPageToken</code>' attribute.
   */
  const StringPiece get_next_page_token() const {
    const Json::Value& v = Storage("nextPageToken");
    if (v == Json::Value::null) return StringPiece("");
    return StringPiece(v.asCString());
  }

  /**
   * Change the '<code>nextPageToken</code>' attribute.
   *
   * Token used to access the next page of this result. Omitted if no further
   * results are available, in which case nextSyncToken is provided.
   *
   * @param[in] value The new value.
   */
  void set_next_page_token(const StringPiece& value) {
    *MutableStorage("nextPageToken") = value.data();
  }

  /**
   * Determine if the '<code>nextSyncToken</code>' attribute was set.
   *
   * @return true if the '<code>nextSyncToken</code>' attribute was set.
   */
  bool has_next_sync_token() const {
    return Storage().isMember("nextSyncToken");
  }

  /**
   * Clears the '<code>nextSyncToken</code>' attribute.
   */
  void clear_next_sync_token() {
    MutableStorage()->removeMember("nextSyncToken");
  }


  /**
   * Get the value of the '<code>nextSyncToken</code>' attribute.
   */
  const StringPiece get_next_sync_token() const {
    const Json::Value& v = Storage("nextSyncToken");
    if (v == Json::Value::null) return StringPiece("");
    return StringPiece(v.asCString());
  }

  /**
   * Change the '<code>nextSyncToken</code>' attribute.
   *
   * Token used at a later point in time to retrieve only the entries that have
   * changed since this result was returned. Omitted if further results are
   * available, in which case nextPageToken is provided.
   *
   * @param[in] value The new value.
   */
  void set_next_sync_token(const StringPiece& value) {
    *MutableStorage("nextSyncToken") = value.data();
  }

  /**
   * Determine if the '<code>summary</code>' attribute was set.
   *
   * @return true if the '<code>summary</code>' attribute was set.
   */
  bool has_summary() const {
    return Storage().isMember("summary");
  }

  /**
   * Clears the '<code>summary</code>' attribute.
   */
  void clear_summary() {
    MutableStorage()->removeMember("summary");
  }


  /**
   * Get the value of the '<code>summary</code>' attribute.
   */
  const StringPiece get_summary() const {
    const Json::Value& v = Storage("summary");
    if (v == Json::Value::null) return StringPiece("");
    return StringPiece(v.asCString());
  }

  /**
   * Change the '<code>summary</code>' attribute.
   *
   * Title of the calendar. Read-only.
   *
   * @param[in] value The new value.
   */
  void set_summary(const StringPiece& value) {
    *MutableStorage("summary") = value.data();
  }

  /**
   * Determine if the '<code>timeZone</code>' attribute was set.
   *
   * @return true if the '<code>timeZone</code>' attribute was set.
   */
  bool has_time_zone() const {
    return Storage().isMember("timeZone");
  }

  /**
   * Clears the '<code>timeZone</code>' attribute.
   */
  void clear_time_zone() {
    MutableStorage()->removeMember("timeZone");
  }


  /**
   * Get the value of the '<code>timeZone</code>' attribute.
   */
  const StringPiece get_time_zone() const {
    const Json::Value& v = Storage("timeZone");
    if (v == Json::Value::null) return StringPiece("");
    return StringPiece(v.asCString());
  }

  /**
   * Change the '<code>timeZone</code>' attribute.
   *
   * The time zone of the calendar. Read-only.
   *
   * @param[in] value The new value.
   */
  void set_time_zone(const StringPiece& value) {
    *MutableStorage("timeZone") = value.data();
  }

  /**
   * Determine if the '<code>updated</code>' attribute was set.
   *
   * @return true if the '<code>updated</code>' attribute was set.
   */
  bool has_updated() const {
    return Storage().isMember("updated");
  }

  /**
   * Clears the '<code>updated</code>' attribute.
   */
  void clear_updated() {
    MutableStorage()->removeMember("updated");
  }


  /**
   * Get the value of the '<code>updated</code>' attribute.
   */
  client::DateTime get_updated() const {
    const Json::Value& storage = Storage("updated");
    return client::JsonValueToCppValueHelper<client::DateTime >(storage);
  }

  /**
   * Change the '<code>updated</code>' attribute.
   *
   * Last modification time of the calendar (as a RFC3339 timestamp). Read-only.
   *
   * @param[in] value The new value.
   */
  void set_updated(client::DateTime value) {
    client::SetJsonValueFromCppValueHelper<client::DateTime >(
      value, MutableStorage("updated"));
  }

 private:
  void operator=(const Events&);
};  // Events
}  // namespace google_calendar_api
#endif  // GOOGLE_CALENDAR_API_EVENTS_H_
