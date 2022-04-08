//
// 由4个不同的数字，组成的一个乘法算式，它们的乘积仍然由这4个数字组成。
//比如：
//210 x 6 = 1260
//8 x 473 = 3784
//27 x 81 = 2187
//都符合要求。
//如果满足乘法交换律的算式算作同一种情况，那么，包含上边已列出的3种情况，一共有多少种满足要求的算式。
//

#include <iostream>
#include <cstring>
#include <cmath>
#include <sstream>

using namespace std;


bool v[10];

bool judge(int r,int i,int j,int k,int l){
    memset(v,false,sizeof(v));
    v[i]= true;
    v[j]= true;
    v[k]= true;
    v[l]= true;
    while(r){
        if (v[r%10]){
            v[r%10]=false;
        } else{
            return false;
        }
        r /= 10;
    }
    return true;
}
int ans;
int main(){
    for (int i = 1; i <=9 ; ++i) {
        for (int j = 0; j <= 9; ++j) {
            if (i!=j){
                for (int k = 0; k <=9; ++k) {
                    if (i!=k&&j!=k){
                        for (int l = 0; l <=9; ++l) {
                            if (i!=l&&k!=l&&j!=l){
                                memset(v,false,sizeof(v));
                                int r1 = i*(j*100+k*10+l);
                                int r2 = (i*10+j)*(k*10+l);
                                int r3 = (i*100+j*10+k)*l;
                                if (1000<=r1&&r1<10000&&judge(r1,i,j,k,l)){
                                    cout << i << j << k << l << " "<<r1<<endl;
                                    ans++;
                                }if (1000<=r2&&r2<10000&&judge(r2,i,j,k,l)){
                                    cout << i << j << k << l << " "<<r2<<endl;
                                    ans++;
                                }if (1000<=r3&&r3<10000&&judge(r3,i,j,k,l)){
                                    cout << i << j << k << l << " "<<r3<<endl;
                                    ans++;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cout<< ans;
    return 0;
}