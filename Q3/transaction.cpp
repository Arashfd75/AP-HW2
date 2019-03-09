#include"transaction.h"
#include<fstream>
#include<iostream>
#include<vector>
#include<string>

transaction::transaction(std::string Day, std::string Product_id, std::string Customer_id){
    day = Day;
    product_id = Product_id;
    customer_id = Customer_id;
}

void transaction::show(){
    static std::string temp_day{" "};
    static std::ofstream fout{"dbnew.txt"};
    if(temp_day != day)
    {
        std::cout << "day : " << day << "   ";
        std::cout << "product_id : " << product_id << "   ";
        std::cout << "product_count : " << product_count << "   ";
        std::cout << "customer_count : " << customer_count << "   ";
        std::cout << "customer_id : " << customer_id << std::endl;
        fout << "[" << day << "]" << product_count << " " << customer_count
         << std::endl;
        temp_day = day;
        numberOfDay++;
    }
}

void transaction::calCount(std::vector<transaction>& new_trans){
    //static std::string temp_id{" "};
    static std::ofstream fout{"dbnew.txt"};
    std::cout << "we are not in for : " <<numberOfDay<< std::endl;
    std::vector <std::string> temp_ProductId, temp_customerId;
    bool flagCustomer{true}, flagProduct{true};
    for(size_t i{},x{}; i < new_trans.size(); i+=x) // different days
    {
        std::cout<<"number of day : "<<numberOfDay<<std::endl;
        x = 0;
        temp_customerId.clear();
        temp_ProductId.clear();
        std::string theDay{new_trans[i].day};
        std::cout<<"theDay : "<<theDay<<std::endl;
        for(size_t j = i; j < new_trans.size(); j++) //rikhtan data i om 
        {       
            if(new_trans[j].day == theDay) //aya dar haman ruz hastim ?
            {
                for(size_t m = 0; m < temp_customerId.size(); m++) //duplicate or not
                {
                    if(new_trans[j].customer_id == temp_customerId[m])
                    {
                        flagCustomer = false;
                        break;
                    }
                }
                
                if(flagCustomer == true) //agar tekrari nabud
                {
                    temp_customerId.push_back(new_trans[j].customer_id);
                }
                flagCustomer = true; 
                x++; // number of transactions of a day
                for(size_t m = 0; m < temp_ProductId.size(); m++) //duplicate or not
                {
                    if(new_trans[j].product_id == temp_ProductId[m])
                    {
                        flagProduct = false;
                        break;
                    }
                }
                
                if(flagProduct == true) //agar tekrari nabud
                {
                    temp_ProductId.push_back(new_trans[j].product_id);
                }
                flagProduct = true;
            }
        }
        std::cout<<"x : "<<x<<std::endl;
        fout << "[" << theDay << "]" << temp_customerId.size() << " " << temp_ProductId.size() 
         << std::endl;

        std::cout << "the answer is : " << temp_customerId.size() << std::endl;
    }
    

}
/*
[2018-02-19 00:01] 099 1234
[2018-02-19 07:50] 099 5322
[2018-02-20 07:50] 124 1567
[2018-02-20 07:52] 123 1568
[2018-02-20 07:53] 125 1569*/