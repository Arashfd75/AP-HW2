class Map {
    public:
    Map(int);
    ~Map();
    void showMap();
    void findRoute();
    void showRoute();
    int n;
    int** map;
    int* route;
};