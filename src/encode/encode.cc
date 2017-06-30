#ifndef ENCODE
#define ENCODE

#include "./params.cc"
#include <string>

string encode(Param<string> p) {
  return p.name + "&" + p.value;
}

string encode(Param<int> p) {
  return p.name + "&" + std::to_string(p.value);
}

string encode(Param<float> p) {
  return p.name + "&" + std::to_string(p.value);
}

string encode(Param<double> p) {
  return p.name + "&" + std::to_string(p.value);
}

string encode(Param<bool> p) {
  return p.name + "&" + std::to_string(p.value);
}

string encode(Param<char> p) {
  return p.name + "&" + std::to_string(p.value);
}

string encode(vector < Param <string> > params) {
  string result = "";
  for (auto& param : params) {
    result += encode(param);
  }
  return result;
}

#endif
