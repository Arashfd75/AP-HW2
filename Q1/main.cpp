#include<iostream>
#include"Map.h"
// compatible with windows
int main(){
    int n;
    std::cin >> n;
    Map map1{n};
    std::cout<<"0"<<std::endl;
	std::cout << "map :" << std::endl;
    map1.showMap();
    std::cout<<"a"<<std::endl;
	map1.findRoute1();
    std::cout<<"b"<<std::endl;
    map1.findRoute();
    std::cout<<"c"<<std::endl;
    map1.showRoute();
    std::cout<<"d"<<std::endl;
    return 0;
}