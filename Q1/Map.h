class Map {
    public:
    Map(int);
    ~Map();
    void showMap();
	void findRoute1();
    void findRoute();
    void showRoute();
    int n;
	int** map{new int*[n]};
	char** routeM{new char*[n]};
	char** routeM1{new char*[n]};
    int* route;
	int* route1;
};