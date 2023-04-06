#include <iostream>
#include "boost/format.hpp"

#define LOG_INFO(...)              \
        log_info(__FUNCTION__, __LINE__, __VA_ARGS__);  

template<typename F, typename L, typename P, typename... Args>
void log_info(const F& f, const L& l, const P& p, const Args&... args) {
    std::cout << boost::format("[%1%@%2%]: ") % f % l;
    boost::format fmt(p);
    (void) std::initializer_list<int>{([&] {fmt % args;}(), 0)...};
    std::cout << fmt.str() << std::endl;
}