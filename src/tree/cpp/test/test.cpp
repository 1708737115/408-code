#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// 定义树节点结构
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 中序遍历函数
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> res;  // 初始化结果数组
    if (root == nullptr) return res;  // 如果根节点为空，直接返回空结果

    stack<TreeNode*> s;
    TreeNode* a = root;

    while (a != nullptr || !s.empty()) {
        if (a != nullptr) {
            s.push(a);
            a = a->left;
        } else {
            a = s.top();
            s.pop();
            res.push_back(a->val);  // 将访问的节点值加入结果数组
            a = a->right;
        }
    }

    return res;
}

// 打印向量中的元素
void printVector(const vector<int>& vec) {
    for (int val : vec) {
        cout << val << " ";
    }
    cout << endl;
}

int main() {
    // 构建一个简单的二叉树
    //       1
    //        \
    //         2
    //        /
    //       3
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    // 调用中序遍历函数
    vector<int> result = inorderTraversal(root);

    // 输出结果
    cout << "Inorder Traversal: ";
    printVector(result);

    // 清理内存
    delete root->right->left;
    delete root->right;
    delete root;

    return 0;
}