#include<iostream>
#include"libVec.h"
#include"libArr.h"
#include<iomanip>
#include<ctime>


template<typename T1, typename T2> 
double runTime(T1 task_ptr,T2 collection, int n);    
    
int main(){
    std::cout << std::setw(8) << 'n' << "  ";
    std::cout << std::setw(10) << "libVec(ms)" << "  "; 
    std::cout << std::setw(10) << "libArr(ms)" << std::endl;
    int n{1};
    for(size_t i{}; i < 6; i++)
    {
        libVec vec;
        double libVec_runTime{runTime(&libVec::counter, vec, n)}; 
        libArr arr;
        double libArr_runTime{runTime(&libArr::counter, arr, n)}; 
        std::cout << std::setw(8) << n << "  ";
        std::cout << std::setw(10) << libVec_runTime << "  "; 
        std::cout << std::setw(10) << libArr_runTime << std::endl;

        n *= 10;
    }

    return 0;
}

template<typename T1, typename T2> 
double runTime(T1 task_ptr,T2 collection, int n)
{
    long start_s{clock()};

    (collection.*task_ptr)(n);

    long stop_s{clock()};   
    double clock_number{static_cast<double>(stop_s - start_s)};
    double clock_per_milisecond{static_cast<double>(CLOCKS_PER_SEC) / 1000.0};
    return clock_number / clock_per_milisecond;
}