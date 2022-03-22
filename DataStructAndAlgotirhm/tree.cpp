//
// 树
//

#include <iostream>
#include <stack>
#include<vector>
#include <queue>

using namespace std;

/*
 * edge 边(e)  n 为顶点总数
 * 一棵树的 e = n-1 = 根节点的出度 = O(n)  任何一棵树顶点数和边数是同阶的
 * 指定好孩子的次序的树称为有序树
 *
 * 路径：V中k+1 通过E中 k条边，依次相连构成一条路径(path)
 * 环路：路径上第一顶点和最后一个顶点是相同的称为环路(loop)
 * 节点之间均有路径，称为连通图(connected)，不含环路，称为无环图(acyclic)
 * 一棵树的任意节点与根之间存在唯一路径
 * 没有后代的节点称为叶子节点(leaf)
 * 叶子深度的最大者，称为树的高度
 * 一个节点的树 高度是0。空树高度取为 -1
 */


/*
 * 二叉树 ： 节点度数不超过2的树
 * 真二叉树 ： 节点度数只有 0 或 2
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};

//先序遍历 根左右
vector<int> preorder(TreeNode *root) {
    vector<int> res;
    if (root == nullptr) {
        return res;
    }
    res.push_back(root->val);
    preorder(root->left);
    preorder(root->right);
    return res;
}

//先序遍历 用栈迭代
vector<int> stackPreorder(TreeNode *root) {
    vector<int> res;
    if (root == nullptr) {
        return res;
    }
    stack<TreeNode *> s;
    while (!s.empty() || root != nullptr) {
        while (root != nullptr) {
            res.push_back(root->val);
            s.push(root);
            root = root->left;
        }
        root = s.top();
        s.pop();
        root = root->right;
    }
    return res;
}

//中序遍历 左根右
vector<int> inorder(TreeNode *root) {
    vector<int> res;
    if (root == nullptr) return res;
    inorder(root->left);
    res.push_back(root->val);
    inorder(root->right);
    return res;
}

//中序遍历 用栈迭代
vector<int> stackInorder(TreeNode *root) {
    vector<int> res;
    if (root == nullptr) return res;
    stack<TreeNode *> s;
    while (!s.empty() || root != nullptr) {
        while (root != nullptr) {
            s.push(root);
            root = root->left;
        }
        root = s.top();
        s.pop();
        res.push_back(root->val);
        root = root->right;
    }
    return res;
}
//次序遍历
vector<int> traverseLevel(TreeNode *root){
    vector<int> res;
    if (root == nullptr) return res;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        root = q.front();
        q.pop();
        res.push_back(root->val);
        if (root -> left) q.push(root ->left);
        if (root -> right) q.push(root ->right);
    }
}

//哈夫曼树 最优带权编码树




int main() {
    stack<TreeNode *> s;
    TreeNode *node1 = new TreeNode;
    node1->val = 1;
    TreeNode *node2 = new TreeNode;
    node2->val = 2;
    s.push(node1);
    s.push(node2);
    TreeNode *root = s.top();
    cout << root << endl;
    s.pop();
    cout << root;


    return 0;
}