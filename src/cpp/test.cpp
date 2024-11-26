#include <iostream>

using namespace std;

typedef struct LinkListNode{
    int data; //数据
    LinkListNode* next;  //指向下一个节点的指针
}Node;

class LinkList   //链表类
{
private:
    LinkListNode* head;  //链表头指针
    int length;  //链表长度
public:
    LinkList()
    {
        head=nullptr;
        length = 0;
    }

    LinkListNode* Get_Cur_Node()  //获取链表尾节点
    {
        LinkListNode* node=head;
        while(node->next!=nullptr)
        {
            node=node->next;
        }
        return node;
    }
    void Add_Node(int data)  //末尾添加链表节点
    {
        if(head==nullptr) 
        {
            head=new LinkListNode;
            head->data=data;
            head->next=nullptr;
            length++;
            return;
        } 
        LinkListNode* node=Get_Cur_Node();
        LinkListNode* Newnode = new LinkListNode;
        Newnode->data=data;
        node->next=Newnode;
        Newnode->next=nullptr;
        length++;
    }

    void Add_Index_Node(int index,int data)  //在指定位置添加节点
    {
        if (index<0)
        {
            cout<<"index error"<<endl;
        }
        if (index==0)
        {
            Add_Node(data);
            return;
        }
        LinkListNode* Newnode = new LinkListNode;
        LinkListNode* node=head;
        for(int i=0;i<index-1;i++)  //让游标指向待插入节点的前一个节点
        {
            node=node->next;
        }
        Newnode->data=data;
        Newnode->next=node->next;
        node->next=Newnode;
        length++;
    }

    void Delete_Node() //删除尾节点
    {
        if(head==nullptr||length<=0)  return;
        LinkListNode* node=Get_Cur_Node();
        delete node;
        length--;
    }
    void Delete_Index_Node(int index)  //删除指定位置的指针
    {
        if(head==nullptr||length<=0)  return;
        if (index<0)
        {
            cout<<"index error"<<endl;
        }
        if (index==0)
        {
            Delete_Node();
            return;
        }
        LinkListNode* node=head;
        for(int i=0;i<index-1;i++)  //让游标指向待删除节点的前一个节点
        {
            node=node->next;
        }
        node->next=node->next->next; //跳过该节点
        /*
            删除节点时，将待删除节点的下一个节点的地址赋给待删除节点，
            LinkListNode* tmp=node->next;
            delete tmp;
            node->next=node->next->next;
        */
       length--;
    }

    int Get_List_Length()
    {
        return length;
    }

    void Print_List()
    {
        int length=Get_List_Length();
        LinkListNode* node=head;
        for(int i=0;i<length;i++)
        {
            cout<<node->data<<" ";
            node=node->next;
        }
        cout<<endl;
    }

    ~LinkList()
    {
        LinkListNode* current = head;
        int length=Get_List_Length();
        for(int i=0;i<length;i++)
        {
            LinkListNode* tmp=current;
            current=current->next;
            delete tmp;
        }
    }
};

int main()
{
     LinkList myList;

    myList.Add_Node(10);
    myList.Add_Node(20);
    myList.Add_Node(30);
    cout << "After adding nodes at the end: ";

    myList.Print_List(); // 应该输出: 10 20 30

    // 测试在指定位置添加节点
    myList.Add_Index_Node(1, 5); // 在索引1处添加5
    cout << "After adding a node at index 1: ";
    myList.Print_List(); // 应该输出: 10 5 20 30

    // 测试删除尾节点
    myList.Delete_Node();
    cout << "After deleting the last node: ";
    myList.Print_List(); // 应该输出: 10 5 20

    // 测试删除指定位置的节点
    myList.Delete_Index_Node(1);
    cout << "After deleting the node at index 1: ";
    myList.Print_List();

    // 测试获取链表长度
    cout << "List length: " << myList.Get_List_Length() << endl; 

    return 0;
}