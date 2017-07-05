#ifndef HEADER
#define HEADER

#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string/classification.hpp>
#include <string>
#include <vector>

using namespace std;

struct Header {
  string header;
  string value;
};

vector <Header> parseHeaders(string headers) {
  vector<Header> headersVectorized;

  if (headers.length()) {
    vector <string> SplitVec;
    split( SplitVec, headers, boost::is_any_of("\n"), boost::token_compress_on );

    for (string& row : SplitVec) {
      size_t found = row.find(":");
      if (found != string::npos) {
        vector <string> ParsedRow;
        split( ParsedRow, row, boost::is_any_of(":"), boost::token_compress_on );

        struct Header header;
        header.header = ParsedRow[0];
        header.value = ParsedRow[1];
        headersVectorized.push_back(header);
      }
    }
  }

  return headersVectorized;
}

#endif
