// 图
/*
 * G = (V;E)
 * v与v之间是邻接关系(adjacency)
 * v与e之间是关联关系(incidence)
 * 树可以看为一个特殊的图
 * 若u和v的次序无所谓,则(u,v)为无向边
 * 反之 有向图(digraph)中均有有向边u,v 分别称作(u,v)的尾，头
 * B -> A A是边(A,B)的头 B是它的尾
 * 简单路径：不含重复节点的路径
 * 路径的起点和终点重合的称为环路
 * 有向无环图(DAG)
 * 欧拉环路：任何一个顶点出发，经过所有的边一次，而且恰好一次的环路
 * 无向图的邻接矩阵是对称的,对称的部分是冗余的
 *
 */
# include <iostream>
# include <algorithm>
# include <queue>
# include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};

using namespace std;




/*
 * DFS 深度优先搜素
 * 有路就一直往前走 用递归实现 类似树的前中后序遍历
 * DFS(s) 始自顶点s的深度优先搜索(Depth-First Search)
 * 访问顶点s
 * 若s尚有未被访问的邻居，则任取其一u，递归执行DFS(u)
 * 否则，返回
 *
 *
 *
 * BFS
 * 始自顶点s的广度优先搜素(Breadth-First-Search)：
 * 首先访问顶点s
 * 依次访问s所有尚未访问的邻接顶点
 * 依次访问他们尚未访问的邻接顶点
 * ......如此反复
 * 直至没有尚未访问的邻接顶点
 * 由近及远 用队列实现 类似树的层次遍历
 *
 *
 */

//判断两个相同的树
// 给你两棵二叉树的根节点 p 和 q ，编写一个函数来检验这两棵树是否相同。



bool isSameTreeDFS(TreeNode *p,TreeNode *q){
    if (p == nullptr && q == nullptr) return true;
    else if (p == nullptr || q == nullptr) return false;
    else if (p ->val != q -> val) return false;
    else return isSameTreeDFS(p -> left,q->left) && isSameTreeDFS(p->right,q->right);
}
/*
 * 也可以通过广度优先搜索判断两个二叉树是否相同。同样首先判断两个二叉树是否为空，如果两个二叉树都不为空，则从两个二叉树的根节点开始广度优先搜索。
使用两个队列分别存储两个二叉树的节点。初始时将两个二叉树的根节点分别加入两个队列。每次从两个队列各取出一个节点，进行如下比较操作。
比较两个节点的值，如果两个节点的值不相同则两个二叉树一定不同；
如果两个节点的值相同，则判断两个节点的子节点是否为空，如果只有一个节点的左子节点为空，或者只有一个节点的右子节点为空，则两个二叉树的结构不同，因此两个二叉树一定不同；
如果两个节点的子节点的结构相同，则将两个节点的非空子节点分别加入两个队列，子节点加入队列时需要注意顺序，如果左右子节点都不为空，则先加入左子节点，后加入右子节点。
如果搜索结束时两个队列同时为空，则两个二叉树相同。如果只有一个队列为空，则两个二叉树的结构不同，因此两个二叉树不同。
 */
bool isSameTreeBFS(TreeNode *p,TreeNode *q){
    if (p == nullptr && q == nullptr) return true ;
    else if (p == nullptr || q == nullptr) return false;
    queue<TreeNode*> q1,q2;
    q1.push(p);
    q2.push(q);
    while(!q1.empty() && !q2.empty()) {
        auto node1 = q1.front(); //auto 自动判断后面变量的数据类型
        q1.pop();
        auto node2 = q2.front();
        q2.pop();
        if (node1->val != node2->val) return false;
        auto left1 = node1->left;
        auto left2 = node2->left;
        auto right1 = node1->right;
        auto right2 = node2->right;
        if (left1 == nullptr ^ left2 == nullptr) return false;
        if (right1 == nullptr ^ right2 == nullptr) return false;
        if (left1 != nullptr) q1.push(left1);
        if (left2 != nullptr) q2.push(left2);
        if (right1 != nullptr) q2.push(right1);
        if (right2 != nullptr) q2.push(right2);
    }
    return q1.empty()&&q2.empty();
}

/*
 * DFS类枚举
 * 常用VIS数组做标记
 * DFS(某状态){
 *  如果搜出一种结果 返回;
 *   在所有能做出的选择中:{
 *      做出改线选择并记录选择做过;
 *      DFS(选择后得状态)
 *      取消该选择以及对该选择的记录;
 *      }
 *  }
 */

/**
 * 按照字典序输出自然数1到n所有不重复的排列，即n的全排列
 * 要求所产生的任一数字序列中不允许出现重复的数字。
 */
int ans[10];
int n;
//用一个bool数组来存储每次已经遍历的点，默认是false
bool visit[10];

void dfs(int num){
    if (num == n) {
        for (int i = 0; i < n; ++i) {
            printf("%5d",ans[i]);
        }
        cout << endl;
        return ;
    }
    for (int i = 1; i <= n; ++i) {
        if (!visit[i]){
            ans[num]=i;
            visit[i]=true;
            dfs(num+1);
            visit[i]=false;
        }
    }
}


int main(){
    //cin >> n ;
    n = 3;
    dfs(0);


    return 0;
}

