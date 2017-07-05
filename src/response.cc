#ifndef RESPONSE
#define RESPONSE

#include "./header.cc"
#include <string>
#include <vector>

using namespace std;

class Response {
  public:
    string body;
    int status;
    bool ok () {
      return this -> status == 200;
    }
    string url;
    string statusText;
    vector<Header> headers;
    string text() {
      // TODO: parse body into text.
      return this -> body;
    };
    string json() {
      // b = this -> body;
      // return parseJSON(b);
      return "";
    };
};

#endif
