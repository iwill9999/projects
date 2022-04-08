/*
http://oj.ecustacm.cn/problem.php?id=1560
 */

#include <iostream>
#include <vector>

using namespace std;

int n ,x;
vector<int> v[10010];

int dfs(int node){

    int maxn = 0;

    for (int i = 0; i < v[node].size(); ++i) {
        maxn = max(maxn, dfs(v[node][i]));
    }
    return maxn + v[node].size();
}


int main(){

    cin >> n;
    for (int i = 2; i <=n ; ++i) {
        cin >> x;
        v[x].push_back(i);
    }
    cout << dfs(1) << endl;



    return 0;
}
