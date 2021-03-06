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
//   ListingsListResponse
// Documentation:
//   https://developers.google.com/android-publisher

#include "google/androidpublisher_api/listings_list_response.h"
#include <string>
#include "googleapis/client/data/jsoncpp_data.h"
#include "googleapis/strings/stringpiece.h"

#include "google/androidpublisher_api/listing.h"


#include <string>
#include "googleapis/strings/strcat.h"

namespace google_androidpublisher_api {
using namespace googleapis;


// Object factory method (static).
ListingsListResponse* ListingsListResponse::New() {
  return new client::JsonCppCapsule<ListingsListResponse>;
}

// Standard immutable constructor.
ListingsListResponse::ListingsListResponse(const Json::Value& storage)
  : client::JsonCppData(storage) {
}

// Standard mutable constructor.
ListingsListResponse::ListingsListResponse(Json::Value* storage)
  : client::JsonCppData(storage) {
}

// Standard destructor.
ListingsListResponse::~ListingsListResponse() {
}

// Properties.

const client::JsonCppArray<Listing > ListingsListResponse::get_listings() const {
   const Json::Value& storage = Storage("listings");
   return client::JsonValueToCppValueHelper<client::JsonCppArray<Listing > >(storage);
}

client::JsonCppArray<Listing > ListingsListResponse::mutable_listings() {
  Json::Value* storage = MutableStorage("listings");
  return client::JsonValueToMutableCppValueHelper<client::JsonCppArray<Listing > >(storage);
}
}  // namespace google_androidpublisher_api
