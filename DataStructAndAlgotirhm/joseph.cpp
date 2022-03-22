//
// Created by 杰 on 2022/3/10.
//约瑟夫环
//

#include "iostream"
#include "list"
using namespace std;

//m是总人数，n是出队的数
int joseph(int n , int m){
    list<int> a; //定义一个整形的list容器
    for (int i = 0; i < m; ++i) {
        a.push_back(i);//用尾插法
    }

    list<int> ::iterator it = a.begin();//list容器的其实迭代器
    while(a.size()>1){
        for (int i = 0; i < n; ++i) {
            it++;
            if (it == a.end()){  //end是指向最后一个元素的下一个位置，约瑟夫是循环问题
                it = a.begin();
            }
        }
        list<int> ::iterator It = ++it; //看下一个是否为end
        if (It == a.end()){
            It = a.begin();
        }
        a.erase(--it);
        it = It;
    }
    cout << *it; //此时list里面只剩一个了

}

int main(){

    joseph(3,10);
    return 0;
}
