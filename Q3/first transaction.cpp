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
    }
}

void transaction::calCount(std::vector<transaction>& new_trans){
    //static std::string temp_id{" "};
    std::vector <std::string> temp_ProductId, temp_customerId;
    int k{};
    for(size_t j{}; j < new_trans.size();j=j+1+k){
        k=0;
        std::cout<<"into second for "<<new_trans[j].product_id<<std::endl;
        for(size_t i{j + 1}; i < new_trans.size(); i++)
        {
        //if(temp_day != new_trans[i].day)
            if(new_trans[j].day == new_trans[i].day)
            {
                bool flagProduct{true}, flagCustomer{true};
                k++;
                std::cout<<"first if : "<<i<<std::endl;
                temp_ProductId.push_back(new_trans[i-1].product_id);
                temp_customerId.push_back(new_trans[i-1].customer_id);
                for(size_t i = 0; i < temp_customerId.size(); i++)
                {
                    std::cout<<temp_customerId[i]<<"  ";  //show temp
                }
                std::cout<<std::endl;
                if(temp_ProductId.size() >= 2)
                {
                    for(size_t i{}; i < temp_ProductId.size()-1; i++)
                    {
                        if(temp_ProductId[i] == temp_ProductId[temp_ProductId.size()-1] && temp_ProductId.size() >= 2)
                        {
                            flagProduct = false;  //new transaction product is repeated
                            temp_ProductId.pop_back();
                            std::cout<<"flagProduct = false"<<std::endl;
                        }
                    }
                }

                if(temp_customerId.size() >= 2)
                {
                    for(size_t i{}; i < temp_customerId.size()-1; i++)
                    {
                        if(temp_customerId[i] == temp_customerId[temp_customerId.size()-1] && temp_customerId.size() >= 2)
                        {
                            flagCustomer = false;//new transaction customer is
                            temp_customerId.pop_back();
                            std::cout<<"flagCustomer = false"<<std::endl;
                        }
                    }
                }
                
                //std::cout<<"temp_id = "<<temp_id<<"  "<<"newtrans[i]"<<new_trans[i].product_id<<std::endl;
                if(new_trans[j].product_id != new_trans[i].product_id && flagProduct )
                {
                    std::cout<<"second if count   "<<std::endl;
                    new_trans[j].product_count ++;
                    //std::cout << "product_count ++" << product_id << std::endl;
                }
                flagProduct = true;
                if(new_trans[j].customer_id != new_trans[i].customer_id && flagCustomer)
                {
                    std::cout<<"second if costumer"<<std::endl;
                    new_trans[j].customer_count ++;   
                }
                flagCustomer = true;
            }
            else
            {
                temp_customerId.clear();
                temp_ProductId.clear();
                break;
            }
            //temp_id = new_trans[i].product_id;
        }
    }
    
}
