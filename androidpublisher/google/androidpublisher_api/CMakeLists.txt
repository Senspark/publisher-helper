# This is a CMake file for Google Play Developer API v2
# using the Google APIs Client Library for C++.
#
# See http://google.github.io/google-api-cpp-client/latest/start/get_started
# for more information about what to do with this file.

project (google_androidpublisher_api)

# These sources assume that the CMakeLists.txt in ../.. added itself to
# the include directories so that include paths are specified explicitly
# with the directory #include "google/androidpublisher_api/..."
add_library(google_androidpublisher_api STATIC
            apk.cc
            apk_binary.cc
            apk_listing.cc
            apk_listings_list_response.cc
            apks_add_externally_hosted_request.cc
            apks_add_externally_hosted_response.cc
            apks_list_response.cc
            app_details.cc
            app_edit.cc
            comment.cc
            deobfuscation_file.cc
            deobfuscation_files_upload_response.cc
            developer_comment.cc
            device_metadata.cc
            entitlement.cc
            entitlements_list_response.cc
            expansion_file.cc
            expansion_files_upload_response.cc
            externally_hosted_apk.cc
            externally_hosted_apk_uses_permission.cc
            image.cc
            images_delete_all_response.cc
            images_list_response.cc
            images_upload_response.cc
            in_app_product.cc
            in_app_product_listing.cc
            inappproducts_batch_request.cc
            inappproducts_batch_request_entry.cc
            inappproducts_batch_response.cc
            inappproducts_batch_response_entry.cc
            inappproducts_insert_request.cc
            inappproducts_insert_response.cc
            inappproducts_list_response.cc
            inappproducts_update_request.cc
            inappproducts_update_response.cc
            listing.cc
            listings_list_response.cc
            month_day.cc
            page_info.cc
            price.cc
            product_purchase.cc
            prorate.cc
            review.cc
            review_reply_result.cc
            reviews_list_response.cc
            reviews_reply_request.cc
            reviews_reply_response.cc
            season.cc
            subscription_deferral_info.cc
            subscription_purchase.cc
            subscription_purchases_defer_request.cc
            subscription_purchases_defer_response.cc
            testers.cc
            timestamp.cc
            token_pagination.cc
            track.cc
            tracks_list_response.cc
            user_comment.cc
            voided_purchase.cc
            voided_purchases_list_response.cc
            android_publisher_service.cc)
target_link_libraries(google_androidpublisher_api googleapis_http)
target_link_libraries(google_androidpublisher_api googleapis_internal)
target_link_libraries(google_androidpublisher_api googleapis_jsoncpp)
target_link_libraries(google_androidpublisher_api googleapis_utils)
