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
#ifndef  GOOGLE_CALENDAR_API_CALENDAR_LIST_ENTRY_H_
#define  GOOGLE_CALENDAR_API_CALENDAR_LIST_ENTRY_H_

#include <string>
#include "googleapis/base/macros.h"
#include "googleapis/client/data/jsoncpp_data.h"
#include "googleapis/strings/stringpiece.h"

#include "google/calendar_api/calendar_notification.h"
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
class CalendarListEntry : public client::JsonCppData {
 public:
  /**
   * The notifications that the authenticated user is receiving for this
   * calendar.
   *
   * @ingroup DataObject
   */
  class CalendarListEntryNotificationSettings : public client::JsonCppData {
   public:
    /**
     * Creates a new default instance.
     *
     * @return Ownership is passed back to the caller.
     */
    static CalendarListEntryNotificationSettings* New();

    /**
     * Standard constructor for an immutable data object instance.
     *
     * @param[in] storage  The underlying data storage for this instance.
     */
    explicit CalendarListEntryNotificationSettings(const Json::Value& storage);

    /**
     * Standard constructor for a mutable data object instance.
     *
     * @param[in] storage  The underlying data storage for this instance.
     */
    explicit CalendarListEntryNotificationSettings(Json::Value* storage);

    /**
     * Standard destructor.
     */
    virtual ~CalendarListEntryNotificationSettings();

    /**
     * Returns a string denoting the type of this data object.
     *
     * @return
     * <code>google_calendar_api::CalendarListEntryNotificationSettings</code>
     */
    const StringPiece GetTypeName() const {
      return StringPiece("google_calendar_api::CalendarListEntryNotificationSettings");
    }

    /**
     * Determine if the '<code>notifications</code>' attribute was set.
     *
     * @return true if the '<code>notifications</code>' attribute was set.
     */
    bool has_notifications() const {
      return Storage().isMember("notifications");
    }

    /**
     * Clears the '<code>notifications</code>' attribute.
     */
    void clear_notifications() {
      MutableStorage()->removeMember("notifications");
    }


    /**
     * Get a reference to the value of the '<code>notifications</code>'
     * attribute.
     */
    const client::JsonCppArray<CalendarNotification > get_notifications() const;

    /**
     * Gets a reference to a mutable value of the '<code>notifications</code>'
     * property.
     *
     * The list of notifications set for this calendar.
     *
     * @return The result can be modified to change the attribute value.
     */
    client::JsonCppArray<CalendarNotification > mutable_notifications();

   private:
    void operator=(const CalendarListEntryNotificationSettings&);
  };  // CalendarListEntryNotificationSettings
  /**
   * Creates a new default instance.
   *
   * @return Ownership is passed back to the caller.
   */
  static CalendarListEntry* New();

  /**
   * Standard constructor for an immutable data object instance.
   *
   * @param[in] storage  The underlying data storage for this instance.
   */
  explicit CalendarListEntry(const Json::Value& storage);

  /**
   * Standard constructor for a mutable data object instance.
   *
   * @param[in] storage  The underlying data storage for this instance.
   */
  explicit CalendarListEntry(Json::Value* storage);

  /**
   * Standard destructor.
   */
  virtual ~CalendarListEntry();

  /**
   * Returns a string denoting the type of this data object.
   *
   * @return <code>google_calendar_api::CalendarListEntry</code>
   */
  const StringPiece GetTypeName() const {
    return StringPiece("google_calendar_api::CalendarListEntry");
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
   * The effective access role that the authenticated user has on the calendar.
   * Read-only. Possible values are:
   * <dl>
   * <dt>"freeBusyReader"
   * <dd>Provides read access to free/busy information.
   * <dt>"reader"
   * <dd>Provides read access to the calendar. Private events will appear to
   * users with reader access, but event details will be hidden.
   * <dt>"writer"
   * <dd>Provides read and write access to the calendar. Private events will
   * appear to users with writer access, and event details will be visible.
   * <dt>"owner"
   * <dd>Provides ownership of the calendar. This role has all of the
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
   * Determine if the '<code>backgroundColor</code>' attribute was set.
   *
   * @return true if the '<code>backgroundColor</code>' attribute was set.
   */
  bool has_background_color() const {
    return Storage().isMember("backgroundColor");
  }

  /**
   * Clears the '<code>backgroundColor</code>' attribute.
   */
  void clear_background_color() {
    MutableStorage()->removeMember("backgroundColor");
  }


  /**
   * Get the value of the '<code>backgroundColor</code>' attribute.
   */
  const StringPiece get_background_color() const {
    const Json::Value& v = Storage("backgroundColor");
    if (v == Json::Value::null) return StringPiece("");
    return StringPiece(v.asCString());
  }

  /**
   * Change the '<code>backgroundColor</code>' attribute.
   *
   * The main color of the calendar in the hexadecimal format "#0088aa". This
   * property supersedes the index-based colorId property. To set or change this
   * property, you need to specify colorRgbFormat=true in the parameters of the
   * insert, update and patch methods. Optional.
   *
   * @param[in] value The new value.
   */
  void set_background_color(const StringPiece& value) {
    *MutableStorage("backgroundColor") = value.data();
  }

  /**
   * Determine if the '<code>colorId</code>' attribute was set.
   *
   * @return true if the '<code>colorId</code>' attribute was set.
   */
  bool has_color_id() const {
    return Storage().isMember("colorId");
  }

  /**
   * Clears the '<code>colorId</code>' attribute.
   */
  void clear_color_id() {
    MutableStorage()->removeMember("colorId");
  }


  /**
   * Get the value of the '<code>colorId</code>' attribute.
   */
  const StringPiece get_color_id() const {
    const Json::Value& v = Storage("colorId");
    if (v == Json::Value::null) return StringPiece("");
    return StringPiece(v.asCString());
  }

  /**
   * Change the '<code>colorId</code>' attribute.
   *
   * The color of the calendar. This is an ID referring to an entry in the
   * calendar section of the colors definition (see the colors endpoint). This
   * property is superseded by the backgroundColor and foregroundColor
   * properties and can be ignored when using these properties. Optional.
   *
   * @param[in] value The new value.
   */
  void set_color_id(const StringPiece& value) {
    *MutableStorage("colorId") = value.data();
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
   * The default reminders that the authenticated user has for this calendar.
   *
   * @return The result can be modified to change the attribute value.
   */
  client::JsonCppArray<EventReminder > mutable_defaultReminders();

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
   * Get the value of the '<code>deleted</code>' attribute.
   */
  bool get_deleted() const {
    const Json::Value& storage = Storage("deleted");
    return client::JsonValueToCppValueHelper<bool >(storage);
  }

  /**
   * Change the '<code>deleted</code>' attribute.
   *
   * Whether this calendar list entry has been deleted from the calendar list.
   * Read-only. Optional. The default is False.
   *
   * @param[in] value The new value.
   */
  void set_deleted(bool value) {
    client::SetJsonValueFromCppValueHelper<bool >(
      value, MutableStorage("deleted"));
  }

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
   * Description of the calendar. Optional. Read-only.
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
   * ETag of the resource.
   *
   * @param[in] value The new value.
   */
  void set_etag(const StringPiece& value) {
    *MutableStorage("etag") = value.data();
  }

  /**
   * Determine if the '<code>foregroundColor</code>' attribute was set.
   *
   * @return true if the '<code>foregroundColor</code>' attribute was set.
   */
  bool has_foreground_color() const {
    return Storage().isMember("foregroundColor");
  }

  /**
   * Clears the '<code>foregroundColor</code>' attribute.
   */
  void clear_foreground_color() {
    MutableStorage()->removeMember("foregroundColor");
  }


  /**
   * Get the value of the '<code>foregroundColor</code>' attribute.
   */
  const StringPiece get_foreground_color() const {
    const Json::Value& v = Storage("foregroundColor");
    if (v == Json::Value::null) return StringPiece("");
    return StringPiece(v.asCString());
  }

  /**
   * Change the '<code>foregroundColor</code>' attribute.
   *
   * The foreground color of the calendar in the hexadecimal format "#ffffff".
   * This property supersedes the index-based colorId property. To set or change
   * this property, you need to specify colorRgbFormat=true in the parameters of
   * the insert, update and patch methods. Optional.
   *
   * @param[in] value The new value.
   */
  void set_foreground_color(const StringPiece& value) {
    *MutableStorage("foregroundColor") = value.data();
  }

  /**
   * Determine if the '<code>hidden</code>' attribute was set.
   *
   * @return true if the '<code>hidden</code>' attribute was set.
   */
  bool has_hidden() const {
    return Storage().isMember("hidden");
  }

  /**
   * Clears the '<code>hidden</code>' attribute.
   */
  void clear_hidden() {
    MutableStorage()->removeMember("hidden");
  }


  /**
   * Get the value of the '<code>hidden</code>' attribute.
   */
  bool get_hidden() const {
    const Json::Value& storage = Storage("hidden");
    return client::JsonValueToCppValueHelper<bool >(storage);
  }

  /**
   * Change the '<code>hidden</code>' attribute.
   *
   * Whether the calendar has been hidden from the list. Optional. The default
   * is False.
   *
   * @param[in] value The new value.
   */
  void set_hidden(bool value) {
    client::SetJsonValueFromCppValueHelper<bool >(
      value, MutableStorage("hidden"));
  }

  /**
   * Determine if the '<code>id</code>' attribute was set.
   *
   * @return true if the '<code>id</code>' attribute was set.
   */
  bool has_id() const {
    return Storage().isMember("id");
  }

  /**
   * Clears the '<code>id</code>' attribute.
   */
  void clear_id() {
    MutableStorage()->removeMember("id");
  }


  /**
   * Get the value of the '<code>id</code>' attribute.
   */
  const StringPiece get_id() const {
    const Json::Value& v = Storage("id");
    if (v == Json::Value::null) return StringPiece("");
    return StringPiece(v.asCString());
  }

  /**
   * Change the '<code>id</code>' attribute.
   *
   * Identifier of the calendar.
   *
   * @param[in] value The new value.
   */
  void set_id(const StringPiece& value) {
    *MutableStorage("id") = value.data();
  }

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
   * Type of the resource ("calendar#calendarListEntry").
   *
   * @param[in] value The new value.
   */
  void set_kind(const StringPiece& value) {
    *MutableStorage("kind") = value.data();
  }

  /**
   * Determine if the '<code>location</code>' attribute was set.
   *
   * @return true if the '<code>location</code>' attribute was set.
   */
  bool has_location() const {
    return Storage().isMember("location");
  }

  /**
   * Clears the '<code>location</code>' attribute.
   */
  void clear_location() {
    MutableStorage()->removeMember("location");
  }


  /**
   * Get the value of the '<code>location</code>' attribute.
   */
  const StringPiece get_location() const {
    const Json::Value& v = Storage("location");
    if (v == Json::Value::null) return StringPiece("");
    return StringPiece(v.asCString());
  }

  /**
   * Change the '<code>location</code>' attribute.
   *
   * Geographic location of the calendar as free-form text. Optional. Read-only.
   *
   * @param[in] value The new value.
   */
  void set_location(const StringPiece& value) {
    *MutableStorage("location") = value.data();
  }

  /**
   * Determine if the '<code>notificationSettings</code>' attribute was set.
   *
   * @return true if the '<code>notificationSettings</code>' attribute was set.
   */
  bool has_notification_settings() const {
    return Storage().isMember("notificationSettings");
  }

  /**
   * Clears the '<code>notificationSettings</code>' attribute.
   */
  void clear_notification_settings() {
    MutableStorage()->removeMember("notificationSettings");
  }


  /**
   * Get a reference to the value of the '<code>notificationSettings</code>'
   * attribute.
   */
  const CalendarListEntryNotificationSettings get_notification_settings() const {
     const Json::Value& storage = Storage("notificationSettings");
    return client::JsonValueToCppValueHelper<CalendarListEntryNotificationSettings >(storage);
  }

  /**
   * Gets a reference to a mutable value of the
   * '<code>notificationSettings</code>' property.
   *
   * The notifications that the authenticated user is receiving for this
   * calendar.
   *
   * @return The result can be modified to change the attribute value.
   */
  CalendarListEntryNotificationSettings mutable_notificationSettings() {
    Json::Value* storage = MutableStorage("notificationSettings");
    return client::JsonValueToMutableCppValueHelper<CalendarListEntryNotificationSettings >(storage);
  }

  /**
   * Determine if the '<code>primary</code>' attribute was set.
   *
   * @return true if the '<code>primary</code>' attribute was set.
   */
  bool has_primary() const {
    return Storage().isMember("primary");
  }

  /**
   * Clears the '<code>primary</code>' attribute.
   */
  void clear_primary() {
    MutableStorage()->removeMember("primary");
  }


  /**
   * Get the value of the '<code>primary</code>' attribute.
   */
  bool get_primary() const {
    const Json::Value& storage = Storage("primary");
    return client::JsonValueToCppValueHelper<bool >(storage);
  }

  /**
   * Change the '<code>primary</code>' attribute.
   *
   * Whether the calendar is the primary calendar of the authenticated user.
   * Read-only. Optional. The default is False.
   *
   * @param[in] value The new value.
   */
  void set_primary(bool value) {
    client::SetJsonValueFromCppValueHelper<bool >(
      value, MutableStorage("primary"));
  }

  /**
   * Determine if the '<code>selected</code>' attribute was set.
   *
   * @return true if the '<code>selected</code>' attribute was set.
   */
  bool has_selected() const {
    return Storage().isMember("selected");
  }

  /**
   * Clears the '<code>selected</code>' attribute.
   */
  void clear_selected() {
    MutableStorage()->removeMember("selected");
  }


  /**
   * Get the value of the '<code>selected</code>' attribute.
   */
  bool get_selected() const {
    const Json::Value& storage = Storage("selected");
    return client::JsonValueToCppValueHelper<bool >(storage);
  }

  /**
   * Change the '<code>selected</code>' attribute.
   *
   * Whether the calendar content shows up in the calendar UI. Optional. The
   * default is False.
   *
   * @param[in] value The new value.
   */
  void set_selected(bool value) {
    client::SetJsonValueFromCppValueHelper<bool >(
      value, MutableStorage("selected"));
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
   * Determine if the '<code>summaryOverride</code>' attribute was set.
   *
   * @return true if the '<code>summaryOverride</code>' attribute was set.
   */
  bool has_summary_override() const {
    return Storage().isMember("summaryOverride");
  }

  /**
   * Clears the '<code>summaryOverride</code>' attribute.
   */
  void clear_summary_override() {
    MutableStorage()->removeMember("summaryOverride");
  }


  /**
   * Get the value of the '<code>summaryOverride</code>' attribute.
   */
  const StringPiece get_summary_override() const {
    const Json::Value& v = Storage("summaryOverride");
    if (v == Json::Value::null) return StringPiece("");
    return StringPiece(v.asCString());
  }

  /**
   * Change the '<code>summaryOverride</code>' attribute.
   *
   * The summary that the authenticated user has set for this calendar.
   * Optional.
   *
   * @param[in] value The new value.
   */
  void set_summary_override(const StringPiece& value) {
    *MutableStorage("summaryOverride") = value.data();
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
   * The time zone of the calendar. Optional. Read-only.
   *
   * @param[in] value The new value.
   */
  void set_time_zone(const StringPiece& value) {
    *MutableStorage("timeZone") = value.data();
  }

 private:
  void operator=(const CalendarListEntry&);
};  // CalendarListEntry
}  // namespace google_calendar_api
#endif  // GOOGLE_CALENDAR_API_CALENDAR_LIST_ENTRY_H_
