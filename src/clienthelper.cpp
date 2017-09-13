#include <ciso646>
#include <fstream>

#include "clienthelper.hpp"

#include <google/androidpublisher_api/android_publisher_service.h>
#include <googleapis/client/auth/oauth2_authorization.h>
#include <googleapis/client/auth/oauth2_service_authorization.h>
#include <googleapis/client/transport/curl_http_transport.h>
#include <googleapis/client/transport/http_authorization.h>

#include <QDebug>

using Self = ClientHelper;

Self::ClientHelper() {}
Self::~ClientHelper() {}

void Self::reset() {
    config_.reset();
    flow_.reset();
    credential_.reset();
    service_.reset();
}

void Self::resetConfig() {
    config_.reset(new googleapis::client::HttpTransportLayerConfig());
}

void Self::resetFlow(googleapis::client::HttpTransport* transport) {
    flow_.reset(new googleapis::client::OAuth2ServiceAccountFlow(transport));
}

void Self::resetCredential() {
    credential_ = std::make_unique<googleapis::client::OAuth2Credential>();
}

void Self::resetService(googleapis::client::HttpTransport* transport) {
    service_.reset(
        new google_androidpublisher_api::AndroidPublisherService(transport));
}

googleapis::client::HttpTransportLayerConfig* Self::getConfig() {
    return config_.get();
}

googleapis::client::OAuth2AuthorizationFlow* Self::getFlow() {
    return flow_.get();
}

googleapis::client::OAuth2Credential* Self::getCredential() {
    return credential_.get();
}

google_androidpublisher_api::AndroidPublisherService* Self::getService() {
    return service_.get();
}

googleapis::util::Status Self::startUp(const std::string& secretFilePath) {
    // Set up HttpTransportLayer.
    resetConfig();
    getConfig()->ResetDefaultTransportFactory(
        new googleapis::client::CurlHttpTransportFactory(getConfig()));

    getConfig()->mutable_default_transport_options()->set_cacerts_path(
        googleapis::client::HttpTransportOptions::kDisableSslVerification);

    // Set up OAuth 2.0 flow for getting credentials to access personal data.
    googleapis::util::Status status;
    auto transport = getConfig()->NewDefaultTransport(std::addressof(status));
    if (not status.ok()) {
        return status;
    }

    resetFlow(transport);

    string json(
        std::istreambuf_iterator<char>(std::ifstream(secretFilePath).rdbuf()),
        std::istreambuf_iterator<char>());
    status = getFlow()->InitFromJson(json);
    if (not status.ok()) {
        return status;
    }

    getFlow()->set_default_scopes(
        google_androidpublisher_api::AndroidPublisherService::SCOPES::
            ANDROIDPUBLISHER);

    // Set up OAuth 2.0 credential.
    resetCredential();
    getCredential()->set_flow(getFlow());

    transport = getConfig()->NewDefaultTransport(std::addressof(status));
    if (not status.ok()) {
        return status;
    }

    // Sets up Android Publisher service.
    resetService(transport);

    return status;
}

googleapis::util::Status
Self::iap_get(const std::string& packageName, const std::string& sku,
              google_androidpublisher_api::InAppProduct* data) {
    std::unique_ptr<
        google_androidpublisher_api::InappproductsResource_GetMethod>
        method(getService()->get_inappproducts().NewGetMethod(
            getCredential(), packageName, sku));
    return method->ExecuteAndParseResponse(data);
}

googleapis::util::Status
Self::iap_list(const std::string& packageName,
               google_androidpublisher_api::InappproductsListResponse* data) {
    std::unique_ptr<
        google_androidpublisher_api::InappproductsResource_ListMethod>
        method(getService()->get_inappproducts().NewListMethod(getCredential(),
                                                               packageName));
    // https://developers.google.com/drive/v3/web/performance#patch
    // https://developers.google.com/google-apps/tasks/performance
    method->set_fields("inappproduct(listings,packageName,sku,status)");
    return method->ExecuteAndParseResponse(data);
}

googleapis::util::Status
Self::iap_patch(const std::string& packageName, const std::string& sku,
                const google_androidpublisher_api::InAppProduct& content,
                google_androidpublisher_api::InAppProduct* data) {
    std::unique_ptr<
        google_androidpublisher_api::InappproductsResource_PatchMethod>
        method(getService()->get_inappproducts().NewPatchMethod(
            getCredential(), packageName, sku, content));
    method->set_fields("listings,packageName,sku,status");
    return method->ExecuteAndParseResponse(data);
}

googleapis::util::Status
Self::iap_update(const std::string& packageName, const std::string& sku,
                 const google_androidpublisher_api::InAppProduct& content,
                 google_androidpublisher_api::InAppProduct* data) {
    std::unique_ptr<
        google_androidpublisher_api::InappproductsResource_UpdateMethod>
        method(getService()->get_inappproducts().NewUpdateMethod(
            getCredential(), packageName, sku, content));
    return method->ExecuteAndParseResponse(data);
}

googleapis::util::Status
Self::reviews_list(const std::string& packageName,
                   google_androidpublisher_api::ReviewsListResponse* data) {
    std::unique_ptr<google_androidpublisher_api::ReviewsResource_ListMethod>
        method(getService()->get_reviews().NewListMethod(getCredential(),
                                                         packageName));
    return method->ExecuteAndParseResponse(data);
}
