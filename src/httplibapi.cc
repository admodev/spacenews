// System libs
#include <iostream>
#include <curl/curl.h>

// Project libs
#include "../include/httplibapi.h"

size_t write_callback(void *contents, size_t size, size_t nmemb, std::string *output) {
        output->append((char*)contents, size * nmemb);
        return size * nmemb;
}

void make_request(std::string api_url) {
        CURL *curl;
        CURLcode res;
        std::string url = api_url;

        curl = curl_easy_init();
        if(curl) {
                curl_easy_setopt(curl, CURLOPT_URL, url.c_str());

                std::string response;
                curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
                curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

                res = curl_easy_perform(curl);
                if(res != CURLE_OK) {
                        std::cerr << "Failed to perform request: " << curl_easy_strerror(res) << std::endl;
                } else {
                        std::cout << "Response: " << response << std::endl;
                }

                curl_easy_cleanup(curl);
        } else {
                std::cerr << "Failed to initialize curl" << std::endl;
        }
}
