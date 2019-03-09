#include<string>
#include<vector>
class transaction;


class transaction{
public:
    transaction(std::string, std::string, std::string);
    void show();
    void calCount(std::vector<transaction>&);
private:
    std::string day, product_id, customer_id;
    int product_count{1},customer_count{1};
    static inline size_t numberOfDay{};
};
