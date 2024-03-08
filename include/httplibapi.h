#ifndef HTTPLIBAPI_H
#define HTTPLIBAPI_H

size_t write_callback(void *contents, size_t size, size_t nmemb, std::string *output);

void make_request(std::string api_url);

#endif

