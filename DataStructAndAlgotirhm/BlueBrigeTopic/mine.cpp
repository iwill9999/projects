//
// Created by 杰 on 2022/3/27.
//



/*
 * 第一层 放1个煤球
 * 第二层 3个煤球
 * 第三层 6个
 * 第四层 10个
 * 问共一百层 多少个煤球
 */

#include<iostream>

using namespace std;

int f(int level){
    if (level == 1) return 1;
    else return level + f(level-1);

}

int main(){

   int sum = 0;
    for (int i = 1; i <= 100; ++i) {
        sum += f(i);
    }
    cout << sum <<endl;

    return 0;
}