#ifndef DT_HEADER
#define DT_HEADER

#include <chrono>

inline double dt(){
    static auto t_prev = std::chrono::high_resolution_clock::now();
    auto t_curr = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = t_curr - t_prev;
    t_prev = t_curr;
    return duration.count();
};

#endif // DT_HEADER

