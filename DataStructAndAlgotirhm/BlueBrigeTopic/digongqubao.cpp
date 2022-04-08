#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;

int ans = 0;
int n,m,k;
int a[20][20];


void dfs(int x,int y, bool judge ,int sum,int maxn){
    if (x == n || y==m){
        return ;
    }
    if(sum == k){
        ans++;
        return;
    }
    if(judge&&a[x][y]>maxn){
        sum++;
    }
    if(x ==n-1&& y == m-1){
        if(sum == k)ans++;
        return;
    }
    maxn = max(maxn,a[x][y]);
    dfs(x + 1,y,true,sum,maxn);
    dfs(x ,y+1,true,sum,maxn);
    //dfs(x + 1,y,false,sum,maxn);
    //dfs(x ,y+1,false,sum,maxn);
    return ;
}


int main(){

    cin >> m >> n >>k;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            cin >> a[i][j];
        }
    }
    dfs(0,0,1,0,0);
    cout << ans << endl;



    return 0;
} 