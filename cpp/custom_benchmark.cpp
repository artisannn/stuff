// #include <iostream>
#include <fstream>
#include <chrono>
#include <cmath>

using namespace std;


double normalize_angle(double x){
//     if (x > abs(1000)){
//     cout<< CYAN_TEXT("***************** Angle more than 1000! *****************") << endl;
//     return -1;}

    while(x > M_PIl){
        x -= 2 * M_PIl;
    }
    while(x < -M_PIl){
        x += 2 * M_PIl;
    }
    return x;
};

int main(int argc, char** argv)
{
    std::ofstream f_results;

    f_results.open("f_results");

    long range_limit = 1e5L;
    for (long double i = -range_limit ; i < range_limit; i++){
        auto t1 = std::chrono::high_resolution_clock::now();
        double normalizedAngle =  normalize_angle(i);
        auto t2 = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>( t2 - t1 ).count();
        f_results << i << " " << duration << " ";
        // f_results << i << " " << 0.0 << " ";

        auto t3 = std::chrono::high_resolution_clock::now();
        double normalizedAngle2 = i - (floor((i + M_PIl)/(2*M_PIl)))*2*M_PIl;
        auto t4 = std::chrono::high_resolution_clock::now();
        auto duration2 = std::chrono::duration_cast<std::chrono::nanoseconds>( t4 - t3 ).count();
        f_results << duration2 << endl;
        // if (fabs(normalizedAngle - normalizedAngle2) >= 0.000001)
        //     f_results << "^^^Bad result!!!^^^ -> " << normalizedAngle<<" "<<normalizedAngle << endl;

    }
    return 0;
}
