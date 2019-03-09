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
    while(!fin.eof()) //read file till the end and make objects
    {
        fin >> temp >> date >> Time; 
        Time.pop_back();
        fin >> product_id >> customer_id;
        transaction temp{date ,product_id, customer_id}; 
        input.push_back(temp);
    }
    input[0].calCount(input); //calculate the count of customers and products
    fin.close();
    return 0;
}
