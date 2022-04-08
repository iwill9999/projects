#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

vector<int> v;

int main(){
    for(int j = 0;j<10;j++){
        v.push_back(2021);
    }

    bool flag = false;
    for(int i=1;i<=20210;i++){
        int k=i;
        while(k){
            if(v[k%10]==0){
                flag = true;
                break;
            }else{
                v[k%10]--;
                k/=10;
            }
        }
        if(flag){
            cout<< i-1<<endl;
            break;
        }
    }

    return 0;
} 