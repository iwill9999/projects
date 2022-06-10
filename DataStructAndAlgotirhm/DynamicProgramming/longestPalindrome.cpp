/*
给你一个字符串 s，找到 s 中最长的回文子串。

示例 1：
输入：s = "babad"
输出："bab"
解释："aba" 同样是符合题意的答案。
*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

//暴力求解
string first(string a){
    string res = "";
    string str = "";
    for (int i = 0; i < a.size(); ++i) {
        for (int j = i; j < a.size(); ++j) {
            str += a[j];
            string temp = str;
            reverse(temp.begin(),temp.end());
            if (str == temp){
                res = temp.size()>res.size() ? temp:res;
            }
        }
        str = "";
    }
    return res;
}

//动态规划




int main(){
    cout << "hello " << endl;
    cout <<first("abcacba");
    return 0;
}
