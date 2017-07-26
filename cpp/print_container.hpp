#include <iostream>
#include <utility>
#include <string>

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

template<typename T, typename U>
std::ostream& operator<<(std::ostream &out, const std::pair<T, U> &p) {
    out << '[' << p.first << ", " << p.second << "]";
    return out;
}
