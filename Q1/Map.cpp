#include"Map.h"
#include<iostream>
#include <ctime>
#include<cstdlib>

    Map::Map(int N){
        srand(time(0));
        n = N;
        route = new int[2 * n];
		route1 = new int[2 * n];
        // 2-d array
		for(int i = 0; i < n; i++)
        {
            map[i] = new int[n];
        }
		for (int i = 0; i < n; i++)
		{
			routeM[i] = new char[n];
		}
		for (int i = 0; i < n; i++)
		{
			routeM1[i] = new char[n];
		}
		for(int i = 0; i < 4 * n; i++)
        {
            route[i] = -1; //initializing 
        }
        for (int i = 0; i < 4 * n; i++)
		{
			route1[i] = -1; //initializing 
		}
		
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)  //creating random array for map
            {
                map[i][j] = (rand()%100)+1;
            }   
        }
	
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)  //creating for showing the route random array
			{
				routeM[i][j] = '-';
			}
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)  //creating for showing the route random array
			{
				routeM1[i][j] = '-';
			}
		}
    }
    void Map::showMap(){ //shows the map
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                std::cout << map[i][j] << "   ";
            }
        std::cout << std::endl;
        }
    }

    void Map::findRoute1(){ //finding the route without diameter move
        int x{},y{},sum{},min,i{1};
        route1[0] = 0;
        route1[1] = 0;
        while(!(x == n - 1 && y == n - 1))
        {
            int temp_x{x}, temp_y{y};
            if (y == n - 1) // if there is no more column for searching
            {
                min = abs(map[y][x] - map[y][x + 1]);
                temp_x = x + 1;
                temp_y = y;
                x = temp_x;
                y = temp_y;
                route1[2 * i] = x;
                route1[2 * i + 1] = y;
				i++;
                sum += min;
                
                continue;
            }

            if (x == n - 1) //if there is no more row for searching
            {
                min = abs(map[y][x] - map[y+1][x]);
                temp_y = y + 1;
                temp_x = x;
				x = temp_x;
				y = temp_y;
				route1[2 * i] = x;
				route1[2 * i + 1] = y;
				i++;
				sum += min;
                continue;
            }
            
            min = abs(map[y][x] - map[y][x + 1]); //temporarily moves to right 
            temp_x = x + 1;
            temp_y = y;

            if(abs(map[y][x] - map[y + 1][x]) < min){ //tests if moving to down is cheaper or not too choose it
                min = abs(map[y][x] - map[y + 1][x]);
                temp_x = x;
                temp_y = y + 1;
            }

			x = temp_x;
            y = temp_y;
            route1[2 * i] = x;
            route1[2 * i + 1] = y;
			i++;
            sum += min;
        }
        std::cout << "sum of distance without diameter is : " << sum << std::endl;
    }

	void Map::findRoute() { //finding the route with diameter move
		int x{}, y{}, sum{}, min, i{ 1 };
		route[0] = 0;
		route[1] = 0;
		while (!(x == n - 1 && y == n - 1))
		{
			int temp_x{ x }, temp_y{ y };
			if (y == n - 1)// if there is no more column for searching
			{
				min = abs(map[y][x] - map[y][x + 1]);
				temp_x = x + 1;
				temp_y = y;
				x = temp_x;
				y = temp_y;
				route[2 * i] = x;
				route[2 * i + 1] = y;
				i++;
				sum += min;

				continue;
			}
			if (x == n - 1)// if there is no more row for searching
			{
				min = abs(map[y][x] - map[y + 1][x]);
				temp_y = y + 1;
				temp_x = x;
				x = temp_x;
				y = temp_y;
				route[2 * i] = x;
				route[2 * i + 1] = y;
				i++;
				sum += min;
				
				continue;
			}

			min = abs(map[y][x] - map[y][x + 1]);//temporarily moves to right
			temp_x = x + 1;
			temp_y = y;

			if (abs(map[y][x] - map[y + 1][x]) < min) { //tests if moving to down is cheaper or not too choose it
				min = abs(map[y][x] - map[y + 1][x]);
				temp_x = x;
				temp_y = y + 1;
			}

			if (abs(map[y][x] - map[y + 1][x + 1]) < min) { //tests if moving to down right is cheaper or not too choose it
				min = abs(map[y][x] - map[y + 1][x + 1]);
				temp_x = x + 1;
				temp_y = y + 1;
			}

			x = temp_x;
			y = temp_y;
			route[2 * i] = x;
			route[2 * i + 1] = y;
			i++;
			sum += min;
		}
		std::cout << "sum of distance with diameter is : " << sum << std::endl;
	}

    void Map::showRoute(){
		//printing the rout without diameter move
		std::cout << "the route without diameter moves" <<std::endl;
        for(int j = 0; j < 2*n ; j++)
        {
            if(route1[2 * j] == -1)
                break;
			routeM1[route1[2 * j + 1]][route1[2 * j]] = '+';
        }
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				std::cout << routeM1[i][j] << "   ";
			}
			std::cout << std::endl;
		}
		// printing route with diameter move
		std::cout << "the route with diameter moves" << std::endl;
		for (int j = 0; j < 2 * n; j++)
		{
			if (route[2 * j] == -1)
				break;
			routeM[route[2 * j + 1]][route[2 * j]] = '+';
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				std::cout << routeM[i][j] << "   ";
			}
			std::cout << std::endl;
		}
    }
    Map::~Map(){
        for(int i = 0; i < n; i++)
        {
            delete[] map[i];
			delete[] routeM[i];
			delete[] routeM1[i];
        }
        delete[] map;
		delete[] routeM;
        delete[] route;
		delete[] routeM1;
		delete[] route1;
    }
    
    
    