//
// Created by 杰 on 2022/3/19.
//问题描述
//某涉密单位下发了某种票据，并要在年终全部收回。
//每张票据有唯一的ID号。全年所有票据的ID号是连续的，但ID的开始数码是随机选定的。
//因为工作人员疏忽，在录入ID号的时候发生了一处错误，造成了某个ID断号，另外一个ID重号。
//你的任务是通过编程，找出断号的ID和重号的ID。
//假设断号不可能发生在最大和最小号。
//输入格式
//要求程序首先输入一个整数N(N<100)表示后面数据行数。
//接着读入N行数据。
//每行数据长度不等，是用空格分开的若干个（不大于100个）正整数（不大于100000），请注意行内和行末可能有多余的空格，你的程序需要能处理这些空格。
//每个整数代表一个ID号。
//输出格式
//要求程序输出1行，含两个整数m n，用空格分隔。
//其中，m表示断号ID，n表示重号ID
//
#include<iostream>
#include<sstream>
#include<algorithm>
const int N=100010;
int n,a[N],res1,res2;

using namespace std;

int main(){
    int cnt;
    cin>>cnt;
    getchar();    //手动忽略第一行
    while(cnt--){  //读入cnt行
        string line;  //输入一行加回车
        getline(cin,line); //读入每一行line
        stringstream ssin(line);   //字符流化
        while(ssin>>a[n++]); //存入int数组中，也相当于string转化为int型，n为小标，就正常那种
    }
    sort(a,a+n);
    for(int i=1;i<n;i++){               //从1（第二个）开始查
        if(a[i]==a[i-1])res1=a[i];
        else if(a[i]>=a[i-1]+2)res2=a[i]-1;
    }
    cout<<res2<<' '<<res1<<endl;

    return 0;
}

