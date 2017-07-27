#include <iostream>
#include <utility>
#include <string>

/*
template<typename T, typename... Args, template<typename, typename...> class Tclass>
std::ostream& operator<<(std::ostream &out, const Tclass<T, Args...> &c) {
    out << "{";
    for (auto p=c.begin(), end=c.end(); p != end; ++p) {
        out << *p;
        if (p+1 != end) {
            out << ", ";
        }
    }
    out << "}";
    return out;
}

template<>
std::ostream& operator<<(std::ostream &out, const std::string &c) {
    out << "{";
    for (auto p=c.begin(), end=c.end(); p != end; ++p) {
        out << *p;
        if (p+1 != end) {
            out << ", ";
        }
    }
    out << "}";
    return out;
}
*/
/*
template<typename T, typename Args, template<typename, typename> class Tclass>
std::ostream& operator<<(std::ostream &out, const Tclass<T, Args> &c) {
    out << "{";
    for (auto p=c.begin(), end=c.end(); p != end;) {
        out << *p;
        ++p;
        if (p != end) {
            out << ", ";
        }
    }
    out << "}";
    return out;
}
*/

template<typename T, typename U>
std::ostream& operator<<(std::ostream &out, const std::pair<T, U> &p) {
    out << '[' << p.first << ", " << p.second << "]";
    return out;
}

/*
template<typename T, typename U>
std::ostream& operator<<(std::ostream &out, const std::map<T, U> &c) {
    out << "{";
    for (auto p=c.begin(), end=c.end(); p != end;) {
        out << *p;
        ++p;
        if (p != end) {
            out << ", ";
        }
    }
    out << "}";
    return out;
}
*/

template <class charT, class traits, class T, class... Args, template<typename, typename...> class Tclass>
  std::basic_ostream<charT,traits>& operator<< (std::basic_ostream<charT,traits>& out, const Tclass<T, Args...>& c) {
      out << "{";
      for (auto p=c.begin(), end=c.end(); p != end;) {
          out << *p;
          ++p;
          if (p != end) {
              out << ", ";
          }
      }
      out << "}";
      return out;
}

/*
template<typename T>
std::ostream& print(std::ostream &out, T const &val) {
  return (out << val << " ");
}

template<typename T1, typename T2>
std::ostream& print(std::ostream &out, std::pair<T1, T2> const &val) {
  return (out << "{" << val.first << " " << val.second << "} ");
}

template<template<typename, typename...> class TT, typename... Args>
std::ostream& operator<<(std::ostream &out, TT<Args...> const &cont) {
  for(auto&& elem : cont) print(out, elem);
  return out;
}*/
