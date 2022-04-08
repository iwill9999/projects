#include<iostream>
#include<string>
#include<unordered_set>

using namespace std;

int ans;

int judge(string str){
    int sum =0;
    unordered_set<char> s;
    for(int i =0;i<str.size();i++){
        if(!s.count(str[i])){
            s.insert(str[i]);
            sum++;
        }else{
            sum--;
        }
    }
    return sum;
}

int main(){
    string str;
    getline(cin,str);
    int k = str.size();
    for(int i = 0;i<str.size();i++){
        for(int j = i+1;j<str.size();j++){
            string subStr;
            subStr.append(str,i,j);
            ans += judge(subStr);
        }
    }
    ans = ans + k -1;
    cout << ans;

    return 0;
}