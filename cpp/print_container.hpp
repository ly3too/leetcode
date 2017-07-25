#include <iostream>
#include <utility>

template<typename T, typename... Args, template<typename, typename...> class Tclass>
std::ostream& operator<<(std::ostream &out, const Tclass<T, Args...> &c) {
    for (const auto &x : c) {
        out << x << " ";
    }
    return out;
}

template<typename T, typename U>
std::ostream& operator<<(std::ostream &out, const std::pair<T, U> &p) {
    out << '[' << p.first << ", " << p.second << "]";
    return out;
}
