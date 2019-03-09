#include"libVec.h"
#include<vector>

    int libVec::counter(int n){
    std::vector <int> input(n);
    int sum{};
        for(size_t i = 0; i < n; i++)
        {
            input[i] = i;
            sum += input[i];
        }
    return sum;    
    }

