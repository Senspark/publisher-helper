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
// Description:
//   Lets Android application developers access their Google Play accounts.
// Classes:
//   ApksListResponse
// Documentation:
//   https://developers.google.com/android-publisher

#include "google/androidpublisher_api/apks_list_response.h"
#include <string>
#include "googleapis/client/data/jsoncpp_data.h"
#include "googleapis/strings/stringpiece.h"

#include "google/androidpublisher_api/apk.h"


#include <string>
#include "googleapis/strings/strcat.h"

namespace google_androidpublisher_api {
using namespace googleapis;


// Object factory method (static).
ApksListResponse* ApksListResponse::New() {
  return new client::JsonCppCapsule<ApksListResponse>;
}

// Standard immutable constructor.
ApksListResponse::ApksListResponse(const Json::Value& storage)
  : client::JsonCppData(storage) {
}

// Standard mutable constructor.
ApksListResponse::ApksListResponse(Json::Value* storage)
  : client::JsonCppData(storage) {
}

// Standard destructor.
ApksListResponse::~ApksListResponse() {
}

// Properties.

const client::JsonCppArray<Apk > ApksListResponse::get_apks() const {
   const Json::Value& storage = Storage("apks");
   return client::JsonValueToCppValueHelper<client::JsonCppArray<Apk > >(storage);
}

client::JsonCppArray<Apk > ApksListResponse::mutable_apks() {
  Json::Value* storage = MutableStorage("apks");
  return client::JsonValueToMutableCppValueHelper<client::JsonCppArray<Apk > >(storage);
}
}  // namespace google_androidpublisher_api
