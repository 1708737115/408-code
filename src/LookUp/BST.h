#include <vector>

typedef struct node{
    int data;
    struct node *left;
    struct node *right;
}BSTNode;


class BST{
    private:
        BSTNode *root;
    public:
        BST():root(nullptr){}
        bool Insert(int val);
        bool Remove(int val);
        BSTNode* Search(int val);
        bool insertNOde(BSTNode* T,int val);   //插入节点
        BSTNode* searchNode1(BSTNode* T,int key); //递归查找节点
        BSTNode* searchNode2(BSTNode* T,int key);//迭代查找节点
        bool removeNode(BSTNode* T,int key); //删除节点
        bool InitTree(std::vector<int>& nodes); //初始化二叉树
        BSTNode* getLeftMax(BSTNode* T); //获取左子树最大值
        BSTNode* getRightMin(BSTNode* T); //获取右子树最小值
        void deleteTree(BSTNode* T);
        ~BST(); //析构函数
};