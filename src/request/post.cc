#ifndef POST
#define POST

#include "../encode/encode.cc"
#include "../encode/params.cc"

namespace post {
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

  Response post(string& url, vector< Param<string> >& params) {
    CURL *curl;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_ALL);

    curl = curl_easy_init();

    Response response;
    response.url = url;
    response.body = fetchResponse;

    if (curl) {
      curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
      curl_easy_setopt(curl, CURLOPT_POSTFIELDS, encode(params).c_str());

      res = curl_easy_perform(curl);

      if (res != CURLE_OK) {
        raiseCurlCode(res);
      } else {
        int response_code;
        curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);

        response.status = response_code;
        response.headers = parseHeaders(headers);
      }

      curl_easy_cleanup(curl);
    }
    curl_global_cleanup();

    return response;
    }
}

#endif
