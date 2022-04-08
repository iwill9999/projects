//
// Created by 杰 on 2022/4/1.
//
#include <iostream>
#include <vector>
#include<algorithm>
#include <string>

using namespace std;

int main(){
    vector<string> v;
    string poker = "223344AA"; //初始序列要是最小序列，这样使用next_permutation才会得到全排列。ASCII码 数字<大写字母<小写字母
    do {
        unsigned beginA =  poker.find("A",0); //unsigned int 简写为 unsigned
        unsigned endA = poker.find("A",beginA+1); //在poker中查找A ，查找地址为beginA的下一个地址，找到返回A的地址
        unsigned begin2 = poker.find("2",0);
        unsigned end2 = poker.find("2",begin2+1);
        unsigned begin3 = poker.find("3",0);
        unsigned end3 = poker.find("3",begin3+1);
        unsigned begin4 = poker.find("4",0);
        unsigned end4 = poker.find("4",begin4+1);
        if (endA - beginA == 2 && end2 - begin2 == 3 && end3 -begin3 == 4 && end4 - begin4 == 5){
            v.push_back(poker);
        }
    }while(next_permutation(poker.begin(),poker.end()));

    sort(v.begin(),v.end());
    cout << *(v.begin()); //数组字典序列小的那个
    return 0;
}
