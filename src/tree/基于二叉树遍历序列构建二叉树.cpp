#include <iostream>
#include <vector>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 定义一个函数 buildTree，用于根据中序遍历和后序遍历构建二叉树
TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
{
    // 如果中序遍历或后序遍历为空，则返回空指针，表示树为空
    if (inorder.size() == 0 || postorder.size() == 0)
        return nullptr;
    // 获取后序遍历的最后一个元素作为根节点的值
    int value = postorder[postorder.size() - 1];
    // 创建一个新的树节点，值为获取到的根节点值
    TreeNode *root = new TreeNode(value);
    // 将后序遍历数组的大小减1，去掉已经使用的根节点值
    postorder.resize(postorder.size() - 1);
    // 定义一个变量 index 用于存储根节点在中序遍历数组中的位置
    int index; // 找分割点
    // 遍历中序遍历数组，找到根节点的位置
    for (int i = 0; i < inorder.size(); i++)
    {
        if (inorder[i] == root->val)
        {
            index = i;
            break;
        }
    }

    // 切割中序数组
    vector<int> leftInorder(inorder.begin(), inorder.begin() + index);
    vector<int> rightInorder(inorder.begin() + index + 1, inorder.end());

    // 切割后序数组
    vector<int> leftPostorder(postorder.begin(), postorder.begin() + leftInorder.size());
    vector<int> rightPostorder(postorder.end() - rightInorder.size(), postorder.end());

    // 递归
    root->left = buildTree(leftInorder, leftPostorder);
    root->right = buildTree(rightInorder, rightPostorder);
    return root;
}

// 构建二叉树的函数，输入为前序遍历和中序遍历的数组
TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    // 如果中序遍历或前序遍历数组为空，则返回空指针，表示树为空
    if (inorder.size() == 0 || preorder.size() == 0)
        return nullptr;
    // 获取前序遍历的第一个值作为根节点的值
    int value = preorder[0];
    // 创建根节点
    TreeNode *root = new TreeNode(value);
    // 从前序遍历数组中移除第一个元素，因为已经用作根节点
    preorder.erase(preorder.begin());
    int index; // 找分割点
    for (int i = 0; i < inorder.size(); i++)
    {
        if (inorder[i] == root->val)
        {
            index = i;
            break;
        }
    }

    // 切割中序数组
    vector<int> leftInorder(inorder.begin(), inorder.begin() + index);
    vector<int> rightInorder(inorder.begin() + index + 1, inorder.end());

    // 切割前序数组
    vector<int> leftPreorder(preorder.begin(), preorder.begin() + leftInorder.size());
    vector<int> rightPreorder(preorder.end() - rightInorder.size(), preorder.end());

    // 递归
    root->left = buildTree(leftPreorder, leftInorder);
    root->right = buildTree(rightPreorder, rightInorder);
    return root;
}