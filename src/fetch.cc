#ifndef FETCH
#define FETCH

#include <curl/curl.h>
#include "./header.cc"
#include "./request/get.cc"
#include "./request/post.cc"
#include <iostream>
#include "./response.cc"
#include <vector>

namespace Fetch {

  Response fetch(string url) {
      return get::get(url);
  }

  Response fetch(string url, string method) {
    if (method == "GET") {
      return get::get(url);
    } else if (method == "POST") {
      return post::post(url);
    } else {
      return get::get(url);
    }
  }
}

#endif
