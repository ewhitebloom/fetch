#ifndef FETCH
#define FETCH

#include <curl/curl.h>
#include "./header.cc"
#include "./request/get.cc"
#include "./request/post.cc"
#include <iostream>
#include "./response.cc"
#include <vector>
#include "./encode/params.cc"

namespace Fetch {

  Response fetch(string url) {
      return get::get(url);
  }

  Response fetch(string url, string method, vector< Param<string> > params) {
    if (method == "GET") {
      return get::get(url);
    } else if (method == "POST") {
      return post::post(url, params);
    } else {
      return get::get(url);
    }
  }

  Response fetch(string url, vector< Param<string> > params) {
    return post::post(url, params);
  }
}

#endif
