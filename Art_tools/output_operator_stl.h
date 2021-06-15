#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <sstream>


template<class Collection>
std::string Join (const Collection& c, std::string d){
  std::stringstream ss;
  bool first = true;
  for (const auto& i: c) {
    if(!first) 
      ss << d;
    first = false;
    ss << i;
  }
  return ss.str();
}

template<class T>
std::ostream& operator<<(std::ostream& os, std::vector<T>& v){
  return os << "[" << Join(v, ",") << "]";
}

template<class K, class V>
std::ostream& operator<< (std::ostream& os, const std::map<K, V>& map){ 
  return os << "{ " << Join(map, ", ") << " }"; 
}

template<class first, class second>
std::ostream& operator<<(std::ostream& os, const std::pair<first,second>& p){
  return os << "(" << p.first <<':'<<p.second << ")";
};

