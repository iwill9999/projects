#include <iostream>
#include <vector>
#include <stack>
#include <set>
#include <map>
#include "algorithm"
#include "queue"
#include "unordered_map"
#include "unordered_set"

using namespace std;

int compare(int a, int b) {
    //<是升序，>是降序
    return a < b;
}
int Joseph(int n,int m){
    if (n==1) return 0;
    else return (Joseph(n-1,m)+m) % n;
}

int main() {

    vector<int> arr{2, 4, 5, 6, 7};
    arr.push_back(1);
    arr.push_back(9);
    arr.push_back(8);
    // arr.end() 是数组最后一个元素的后一个位置， 是一个空值
    for (vector<int>::iterator p = arr.begin(); p != arr.end(); p++) {
        cout << *p;
    }
    cout << endl;
    //排序 #include algorithm comp是按自己写的函数来排序
    sort(arr.begin(), arr.end(), compare);
    for (vector<int>::iterator p = arr.begin(); p != arr.end(); p++) {
        cout << *p;
    }
    cout << endl;

    /*//nth是第k小的地址，把它放到盖房的位置上，左边的元素都小于等于它，有变得元素都大于等于它
    nth_element(arr.begin(), arr.begin() + 3, arr.end());
    for (vector<int>::iterator p = arr.begin(); p != arr.end(); p++) {
        cout << *p;
    }
    cout << endl;*/
    //一般用来二分查找,二分查找要求数组是有序的，返回指向第一个大于等于val的位置
    vector<int>::iterator a = lower_bound(arr.begin(), arr.end(), 2);
    cout << a - arr.begin(); //两个迭代器相减是表示之间的距离 -begin就表示下标位置
    cout << endl;
    //同理找第一个大于(对比lower_bound没有等于)val值得位置
    vector<int>::iterator b = upper_bound(arr.begin(), arr.end(), 2);
    cout << b - arr.begin() << endl;

    //栈
    stack<int> stk;
    //队列
    queue<int> q;
    //集合 不重复
    set<int> set;
    //多重集合
    multiset<int> multiset;
    //对
    pair<int, string> pr{1, "zhang"};
    //map  multimap可以有重复
    map<string, int> student;
    student["小明"] = 120;

    cout << student["小明"];

    //unordered_map unordered_set 是基于哈希的 比map 和set快

  /*   数据范围及运算结果均在1e9内时，可以令 const int INF = 0x3f3f3f3f,表示无穷大值
     并且可以用 memset(arr,INF,sizeof(arr)) 令数组初始化无穷大。

*/

  int result = Joseph(10,4);
  cout << result+1;

  //全排列
  vector<int> v;
    for (int i = 0; i < 10; ++i) {
        v.push_back(i);
    }
    do {
        for(vector<int>::iterator it = v.begin();it != v.end();it++){
            cout << *it;
        }
        cout << endl;
        //next_permutation自动排列 知道全部排列完成
    }while(next_permutation(v.begin(),v.end()));




    return 0;
}
