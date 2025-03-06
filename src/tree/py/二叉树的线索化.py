'''
小技巧:使用列表模拟引用传递：
pre 是一个包含单个元素的列表 [None]。在递归过程中，通过修改 pre[0] 来更新前一个节点的引用。
这样做的原因是 Python 的函数参数传递是按值传递的，但对于可变对象（如列表），可以在函数内部修改其内容，从而影响外部变量。
'''

class TreeNode:
    def __init__(self, val, left=None, right=None, ltag=0, rtag=0):
        self.val = val
        self.left = left
        self.right = right
        self.ltag = ltag  # 左子树是否为线索 (0: 非线索, 1: 线索)
        self.rtag = rtag  # 右子树是否为线索 (0: 非线索, 1: 线索)

def InorderTree(t,pre):
    if t==None:
        return t
    InorderTree(t.left,pre) #递归遍历左子树
    if t.left==None: # 建立当前节点的前序线索
        t.ltag = 1
        t.left = pre
    if pre[0]!=None and pre[0].right==None: # 建立当前节点的后序线索
        pre[0].right=t
        pre[0].rtag = 1
    pre[0]=t
    InorderTree(t.right,pre)
        
# 创建中序线索二叉树
def CreateInTree(t):
    if t==None:
        return t
    pre=[None]  #用列表来模拟引用
    InorderTree(t,pre)
    pre[0].right = None
    pre[0].rtag = 1
    
#测试函数
# 测试函数
if __name__ == "__main__":
    # 构建一个简单的二叉树
    root = TreeNode(1)
    root.left = TreeNode(2)
    root.right = TreeNode(3)
    root.left.left = TreeNode(4)
    root.left.right = TreeNode(5)
    root.right.left = TreeNode(6)
    root.right.right = TreeNode(7)

    # 创建中序线索二叉树
    CreateInTree(root)

    # 打印线索化后的二叉树
    node = root
    while node is not None:
        # 找到最左节点
        while node.ltag == 0 and node.left is not None:
            node = node.left
        print(node.val, end=" ")

        # 中序遍历
        while node is not None and node.rtag == 1:
            node = node.right
            if node is not None:
                print(node.val, end=" ")
        
        # 如果当前节点有右子树且不是线索，则进入右子树
        if node is not None and node.rtag == 0 and node.right is not None:
            node = node.right
        else:
            break
    