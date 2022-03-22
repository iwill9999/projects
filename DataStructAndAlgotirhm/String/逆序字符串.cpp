//
// Created by 杰 on 2022/3/12.
//
#include "iostream"
#include "string"
#include "algorithm"
using namespace std;

int main(){
    string str;
    //getline输入一行 直接输入cin>>str只能接收空格之前的字符串
    getline(cin,str);
    reverse(str.begin(),str.end());
    cout << str;
    return 0;
}