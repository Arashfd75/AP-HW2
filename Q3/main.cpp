#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include"transaction.h"

int main(){
    std::vector <transaction>input;
    std::ifstream fin{"db.txt"};
    char temp;
    std::string date, Time, product_id, customer_id;
    while(!fin.eof())
    {
        fin >> temp >> date >> Time;
        Time.pop_back();
        fin >> product_id >> customer_id;
        transaction temp{date ,product_id, customer_id}; 
        input.push_back(temp);
    }
    //std::cout<<"input size : " << input.size();
    input[0].calCount(input);
    //transaction::func1();
    fin.close();
    return 0;
}
