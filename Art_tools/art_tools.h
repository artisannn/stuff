#ifndef ART_TOOLS_H
#define ART_TOOLS_H
#include <string>
#include <signal.h>
#include <unistd.h>
#include <typeinfo>
#include <cxxabi.h>
#include <iostream>
#include <vector>
#include <list>


/******************** Helper functions ********************/
template<class T>
void print_size(T mat, std::string name){
    std::cout << name+": [" << mat.rows() <<"x" << mat.cols()<<"]"<< std::endl;
}

template<class T>
void print_mat(T mat, std::string name){
    std::cout << name << std::endl << mat << std::endl;
}

void inline print_line(std::string name){
    std::cout << name << std::endl ;
}

// to pretty print the type of the object
template<class T>
std::string type(T& object){
  return abi::__cxa_demangle(typeid(object).name(), 0, 0, 0);
}

template <class T> int sign(T val) {
    return (T(0) < val) - (val < T(0));
}

template <class T> 
std::ostream& operator<<(std::ostream& os, const std::vector<T>& v) 
{ 
    os << "["; 
    for (auto& i : v) { 
        os << i << ", "; 
    } 
    os << "\b\b]\n"; 
    return os; 
} 
template <class T> 
std::ostream& operator<<(std::ostream& os, const std::list<T>& v) 
{ 
    os << "["; 
    for (auto& i : v) { 
        os << i << ", "; 
    } 
    os << "\b\b]\n"; 
    return os; 
} 
/******************** Helper functions ********************/
#endif
