#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

typedef struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
} Node;

vector<int> res;

// 前序遍历二叉树
vector<int> PreorderTraversal(TreeNode *root)
{
    if (root == nullptr)
        return res;
    stack<TreeNode *> s;
    s.push(root);
    while (!s.empty())
    {
        auto r = s.top();
        s.pop();
        res.push_back(r->val);
        if (r->right)
            s.push(r->right);
        if (r->left)
            s.push(r->left);
    }
    return res;
}

// 中序遍历二叉树
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> res;  // 初始化结果数组，用于存储中序遍历的节点值
    if (root == nullptr) return res;  // 如果根节点为空，直接返回空结果数组

    stack<TreeNode*> s;  // 使用栈来辅助中序遍历
    TreeNode* a = root;  // 初始化当前节点为根节点

    // 当当前节点不为空或栈不为空时，继续遍历
    while (a != nullptr || !s.empty()) {
        if (a != nullptr) {
            s.push(a);  // 将当前节点压入栈中
            a = a->left;  // 移动到当前节点的左子节点
        } else {
            a = s.top();  // 从栈顶取出节点
            s.pop();  // 弹出栈顶节点
            res.push_back(a->val);  // 将访问的节点值加入结果数组
            a = a->right;  // 移动到当前节点的右子节点
        }
    }

    return res;  // 返回中序遍历的结果数组
}

// 后序遍历二叉树
vector<int> postorderTraversal(TreeNode* root) {
    vector<int> res;  // 初始化结果数组，用于存储后序遍历的节点值
    if (root == nullptr) return res;  // 如果根节点为空，直接返回空结果数组

    stack<TreeNode*> s;  // 使用栈来辅助后序遍历
    TreeNode* a = root;  // 初始化当前节点为根节点
    s.push(a); // 将根节点压入栈中
    while(!s.empty())
    {
        auto r = s.top();
        s.pop();
        res.push_back(r->val);
        if (r->left)
            s.push(r->left);
        if (r->right)
            s.push(r->right);
    }
    reverse(res.begin(), res.end());  // 返回后序遍历的结果数组
    return res;
}
