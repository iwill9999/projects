/*
给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度
我们使用两个指针表示字符串中的某个子串（或窗口）的左右边界，其中左指针代表着上文中「枚举子串的起始位置」，而右指针即rk,
在每一步的操作中，我们会将左指针向右移动一格，表示 我们开始枚举下一个字符作为起始位置，然后我们可以不断地向右移动右指针，
但需要保证这两个指针对应的子串中没有重复的字符。
在移动结束后，这个子串就对应着 以左指针开始的，不包含重复字符的最长子串。我们记录下这个子串的长度；
在枚举结束后，我们找到的最长的子串的长度即为答案。
。*/

#include <iostream>
#include <unordered_set>
#include <set>

using namespace std;

int lengthOfLongestSubstring(string s) {
    int ans=0;
    int n = s.size();
    //滑动窗口右下标，起始为-1 相当于在字符串的左边界的左侧，还没有开始移动
    int rt = -1;
    //哈希集合，记录每个字符是否出现过
    unordered_set<char> occ;
    for (int i = 0; i < n; ++i) {
        if (i != 0) {
            //左指针向右移动一格，移除一个字符
            occ.erase(s[i - 1]);
        }
        //右指针向右一个且这个字符在集合里没有出现过
        while (rt + 1 < n && !occ.count(s[rt + 1])) {
            occ.insert(s[rt + 1]);
            rt++;
        }
        ans = max(ans,rt - i +1);
    }
    return ans;
}


int main() {

    //set容器底层由二叉树实现，所有元素会在插入时自动排序
    //set不能有重复元素，multiset可以有重复
    set<int> s;
    s.insert(1);
    for (set<int>::iterator it = s.begin(); it != s.end(); it++) {
        //遍历
    }
    //unordered_set 不会自动排序 是基于哈希的 速度比set快
    cout << lengthOfLongestSubstring("abcdabc");

    return 0;
}
