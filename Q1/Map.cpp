#include"Map.h"
#include<iostream>
#include<cstdlib>

    Map::Map(int N){
        srand(time(0));
        n = N;
        route = new int[2*n];
        // 2-d array
        map = new int*[n];
        for(int i = 0; i < n; i++)
        {
            map[i] = new int[n];
        }
    
        for(int i = 0; i < 2 * n; i++)
        {
            route[i] = -1; //demostrate end of the array
        }
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)  //random array
            {
                map[i][j] = (rand()%100)+1;
            }
            
        }
    }
    void Map::showMap(){
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                std::cout << map[i][j] << "   ";
            }
        std::cout << std::endl;
        }
    }
    void Map::findRoute(){
        int x{},y{},sum{},min,i{2};
        route[0] = 0;
        route[1] = 0;
        while(!(x == n-1 && y == n-1))
        {
            int temp_x{x}, temp_y{y};
            if (y == n-1)
            {
                min = abs(map[y][x] - map[y][x + 1]);
                temp_x = x + 1;
                temp_y = y;
                i++;
                route[2 * i] = x;
                route[2 * i + 1] = y;
                sum += min;
                x = temp_x;
                y = temp_y;
                std::cout<<"paEn-g"<<std::endl;
                continue;
            }
            if (x == n-1)
            {
                min = abs(map[x][y] - map[y+1][x]);
                temp_y = y + 1;
                temp_x = x;
                i++;
                route[2 * i] = x;
                route[2 * i + 1] = y;
                sum += min;
                x = temp_x;
                y = temp_y;
                std::cout<<"rast-g"<<std::endl;
                continue;
            }
            
            min = abs(map[y][x] - map[y][x + 1]);
            temp_x = x+1;
            temp_y = y;
            std::cout<<"rast"<<std::endl;

            if(abs(map[y][x] - map[y + 1][x]) < min){
                min = abs(map[y][x] - map[y + 1][x]);
                temp_x = x;
                temp_y = y+1;
                std::cout<<"paEn"<<std::endl;
            }

            if(abs(map[y][x] - map[y + 1][x + 1]) < min){
                min =  abs(map[y][x] - map[y + 1][x + 1]);
                temp_x = x+1;
                temp_y = y+1;
                std::cout<<"orib"<<std::endl;
            }
            i++;
            route[2 * i] = x;
            route[2 * i + 1] = y;
            sum += min;
            std::cout<<"sum = "<<sum<<std::endl;
            x = temp_x;
            y = temp_y;

        }
        std::cout << "sum of distance is : " << sum;
    }
    void Map::showRoute(){
        int route_itr{};
        for(int i = 0; i < 2*n; i++)
        {
            for(int j = 0; j < 2*n; j++)
            {
                if(route[2 * route_itr] == -1)
                    break;
                //std::cout << route[i*n + j] << std::endl;
                if(route[2 * route_itr] == i && route[2 * route_itr + 1] == j )
                {
                    std::cout << " + ";
                }
                else 
                    std::cout << " - ";               
            
                std::cout << std::endl;
                if(route[2 * route_itr] == -1)
                    break;
                route_itr++;
            }
        }
    }
    Map::~Map(){
        for(int i = 0; i < n; i++)
        {
            delete[] map[i];
        }
        delete[] map;
        delete[] route;
    }
    
    
    