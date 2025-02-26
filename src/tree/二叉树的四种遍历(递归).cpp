#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
} Node;

vector<int> res;

vector<int> inorderTraversal(TreeNode *root)
{ // 中序遍历
    res.clear();
    if (root == nullptr)
        return res;
    inorderTraversal(root->left);
    res.push_back(root->val);
    inorderTraversal(root->right);
    return res;
}

vector<int> preorderTraversal(TreeNode *root)
{ // 前序遍历
    res.clear();
    if (root == nullptr)
        return res;
    res.push_back(root->val);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
    return res;
}

vector<int> postorderTraversal(TreeNode *root)
{ // 后序遍历
    res.clear();
    if (root == nullptr)
        return res;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    res.push_back(root->val);
    return res;
}

vector<vector<int>> levelorderTraversal(TreeNode *root)
{
    vector<vector<int>> res;
    if (root == nullptr)
        return res;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        vector<int> temp;
        int size = q.size();
        for (int j = 0; j < size; j++)
        {
            TreeNode *node = q.front();
            q.pop();
            temp.push_back(node->val);
            if (node->left != nullptr)
                q.push(node->left);
            if (node->right != nullptr)
                q.push(node->right);
        }
        res.push_back(temp);
    }
    return res;
}

int main()
{
    return 0;
}