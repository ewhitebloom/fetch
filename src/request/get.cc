#ifndef GET
#define GET

#include <curl/curl.h>
#include "../header.cc"
#include <iostream>
#include "../response.cc"
#include <vector>

namespace get {

  string fetchResponse;
  string headers;

  size_t writeCallback(char* buf, size_t size, size_t nmemb, void* up)
  {
      for (int c = 0; c<size*nmemb; c++)
      {
          fetchResponse.push_back(buf[c]);
      }
      return size*nmemb;
  }

  static size_t header_callback(char *buffer, size_t size, size_t nitems, void *userdata)
  {
    for (int c = 0; c<size*nitems; c++)
    {
        headers.push_back(buffer[c]);
    }
    return nitems * size;
  }

  Response get(string url) {
    CURL* curl;
    CURLcode res;
    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();

    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, &writeCallback);
    curl_easy_setopt(curl, CURLOPT_HEADER, 1L);
    curl_easy_setopt(curl, CURLOPT_HEADERFUNCTION, header_callback);

    res = curl_easy_perform(curl);

    curl_easy_cleanup(curl);
    curl_global_cleanup();

    Response response;
    response.url = url;
    response.body = fetchResponse;

    if (res != CURLE_OK) {
      throw "Something went wrong.";
    } else {
      long response_code;
      curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);

      response.status = response_code;
      response.headers = parseHeaders(headers);
    }

    return response;
  }
}

#endif
