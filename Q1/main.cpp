#include<iostream>
#include"Map.h"

int main(){
    int n;
    std::cin >> n;
    Map map1{n};
    //std::cout << map1.map[2][2] << std::endl;
    map1.showMap();
    map1.findRoute();
    map1.showRoute();
    return 0;
}