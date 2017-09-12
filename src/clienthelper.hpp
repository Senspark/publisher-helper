#ifndef CLIENTHELPER_HPP
#define CLIENTHELPER_HPP

#include <memory>

#include <google/androidpublisher_api/in_app_product.h>
#include <google/androidpublisher_api/inappproducts_list_response.h>
#include <google/androidpublisher_api/reviews_list_response.h>
#include <googleapis/util/status.h>

namespace googleapis {
namespace client {
class HttpTransport;
class HttpTransportLayerConfig;
class OAuth2AuthorizationFlow;
class OAuth2Credential;
} // namespace client
} // namespace googleapis

namespace google_androidpublisher_api {
class AndroidPublisherService;
} // namespace google_androidpublisher_api

class ClientHelper {
public:
    ClientHelper();
    ~ClientHelper();

    googleapis::util::Status startUp(const std::string& secretFilePath);

    googleapis::util::Status
    iap_get(const std::string& packageName, const std::string& sku,
            google_androidpublisher_api::InAppProduct* data);

    googleapis::util::Status
    iap_list(const std::string& packageName,
             google_androidpublisher_api::InappproductsListResponse* data);

    googleapis::util::Status
    iap_update(const std::string& packageName, const std::string& sku,
               const google_androidpublisher_api::InAppProduct& content,
               google_androidpublisher_api::InAppProduct* data);

    googleapis::util::Status
    reviews_list(const std::string& packageName,
                 google_androidpublisher_api::ReviewsListResponse* data);

private:
    void resetConfig();
    void resetFlow(googleapis::client::HttpTransport* transport);
    void resetCredential();
    void resetService(googleapis::client::HttpTransport* transport);
    googleapis::client::HttpTransportLayerConfig* getConfig();
    googleapis::client::OAuth2AuthorizationFlow* getFlow();
    googleapis::client::OAuth2Credential* getCredential();
    google_androidpublisher_api::AndroidPublisherService* getService();

    std::unique_ptr<googleapis::client::OAuth2Credential> credential_;
    std::unique_ptr<googleapis::client::HttpTransportLayerConfig> config_;
    std::unique_ptr<googleapis::client::OAuth2AuthorizationFlow> flow_;
    std::unique_ptr<google_androidpublisher_api::AndroidPublisherService>
        service_;
};

#endif // CLIENTHELPER_HPP
