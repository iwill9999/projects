/*
 * 比赛时，先站在左上角的写着“从”字的格子里，可以横向或纵向跳到相邻的格子里
 * 但不能跳到对角的格子或其它位置。一直要跳到“华”字结束。
 * 要求跳过的路线刚好构成“从我做起振兴中华”这句话。
 */

#include <iostream>
#include <vector>
#include <sstream>

using namespace std;
int matrix[4][5] = {1, 2, 3, 4, 5,
                    2, 3, 4, 5, 6,
                    3, 4, 5, 6, 7,
                    4, 5, 6, 7, 8};
bool visit[4][5];
int ans=0;
string str;

void dfs(string b) {
    str+=b;
    if (str.length() == 8) {
        if (str.compare("12345678"))ans++;
        return;
    }
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (!visit[i][j]) {
                visit[i][j]= true;
                stringstream ss;
                string b;
                ss << matrix[i][j];
                ss >>b;
                dfs(b);
                visit[i][j] = false;
                str.pop_back();
            }
        }
    }


}

int main() {
    dfs("");
    cout << ans;


    return 0;
}

