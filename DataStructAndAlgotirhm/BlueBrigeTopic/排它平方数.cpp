/*小明正看着 203879 这个数字发呆。
原来，203879 * 203879 = 41566646641
这有什么神奇呢？仔细观察，203879 是个6位数，并且它的每个数上的数字都是不同的，并且它平方后的所有数位上都不出现组成它自身的数字。
具有这样特点的6位数还有一个，请你找出它！
再归纳一下筛选要求：
1. 6位正整数
2. 每个数位上的数字不同
3. 其平方数的每个数位不含原数字的任何组成数位*/

#include <iostream>
#include <cmath>
#include <set>
#include <cstring>

using namespace std;

bool judge(long long a, long long b) {
    bool v[15];
    //将数组初始化全False
    memset(v, false, sizeof(v));
    while (a) {
        if (!v[a % 10]){
            v[a%10]= true;
            a /= 10;
        }else {
        return false;
        }
    }
    while(b){
        if (v[b%10]) return false;
        b/=10;
    }
    return true;
}

int main() {

    for (int i = 123456; i <=987654 ; ++i) {
        if (i == 203879) continue;
        if (judge(i, pow(i,2))){
            cout << i << endl;
        }
    }

    return 0;
}
