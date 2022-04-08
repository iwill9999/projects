#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>

using namespace std;
bool v[15];

bool judge(int a,long int b){
    memset(v,false,sizeof(v));
    while(a){
        if(!v[a%10]){
            v[a%10]=true;
        }else{
            return false;
        }
        a /= 10;
    }
    while(b){
        if(!v[b%10]){
            v[b%10]=true;
        }else{
            return false;
        }
        b/=10;
    }
    return true;
}


int main(){

    for(int i = 10;i<=100;i++){
        if(judge(pow(i,2),pow(i,3))) cout << i <<endl;
    }

    return 0;
} 