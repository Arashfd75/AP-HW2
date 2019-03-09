#include"transaction.h"
#include<fstream>
#include<iostream>
#include<vector>
#include<string>

transaction::transaction(std::string Day, std::string Product_id, std::string Customer_id){
    day = Day;
    product_id = Product_id;      //constructor
    customer_id = Customer_id;
}

void transaction::calCount(std::vector<transaction>& new_trans){
    //static std::string temp_id{" "};
    static std::ofstream fout{"dbnew.txt"};
    std::vector <std::string> temp_ProductId, temp_customerId;
    bool flagCustomer{true}, flagProduct{true};
    for(size_t i{},x{}; i < new_trans.size(); i+=x) // different days
    {
        x = 0;
        temp_customerId.clear();
        temp_ProductId.clear();
        std::string theDay{new_trans[i].day};
        for(size_t j = i; j < new_trans.size(); j++) //rikhtan data i om 
        {       
            if(new_trans[j].day == theDay) //aya dar haman ruz hastim ?
            {
                for(size_t m = 0; m < temp_customerId.size(); m++) //duplicate or not
                {
                    if(new_trans[j].customer_id == temp_customerId[m])
                    {
                        flagCustomer = false;
                        break; //no need to continue the loop
                    }
                }
                if(flagCustomer == true) //if it is not duplicated
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
                if(flagProduct == true) //if is not duplicated
                {
                    temp_ProductId.push_back(new_trans[j].product_id);
                }
                flagProduct = true;
            }
        }   // below we write new information in file (dbnew)
        fout << "[" << theDay << "]" << temp_ProductId.size() << " " << temp_customerId.size() << std::endl;
    }
}