#include"libArr.h"
#include<iostream>

int libArr::counter(int n){
    int input[n];
    int sum{};
    for(size_t i = 0; i < n; i++)
    {
        input[i] = i;
        sum += input[i];
    }
    return sum;
}