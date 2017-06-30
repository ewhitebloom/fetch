#include "./fetch.cc"
#include "./response.cc"

using namespace Fetch;

int main () {

  // Response res = fetch("https://www.google.com");
  //
  // cout << "Status: " << res.status << endl;
  //
  // for (auto& header : res.headers) {
  //   cout << header.header << ": " << header.value << endl;
  // }
  //
  // Response response = fetch("https://www.nytimes.com");
  //
  // for (auto& header : response.headers) {
  //   cout << header.header << ": " << header.value << endl;
  // }


  Response r = fetch("https://www.google.com");

  cout << r.body << endl;

  return 0;
}
