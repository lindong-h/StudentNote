#include<bits/stdc++.h>
using namespace std;
const int N = 1000;

template <class DataType>
struct node{
    DataType data;
    node<DataType>* next;
};

template <class DataType>
class linkList{
    public:
        linkList();
        ~linkList();
        void Delete();
        void show();
        void reverse_node();
        node<DataType>* Find_reverse_index(int k);
        void deleteList(DataType mink,DataType maxk);
    private:
        node<DataType>* first;
};

template <class DataType>
node<DataType>* linkList<DataType>::Find_reverse_index(int k)
{
    node<DataType> *p = first;
    int len = 0;
    while(p -> next != nullptr)
    {
        len ++;
        p = p -> next;
    }
    
    int nk = len - k;
    node<DataType> *s = first -> next;
    for(int i = 0 ; i < len ; i++)
    {
        if(i == nk) return s;
        s = s -> next;
        if(i == len) s = nullptr;
    }
    
}

template <class DataType>
void linkList<DataType>::deleteList(DataType mink,DataType maxk)
{
    node<DataType> *p = first;
    while(p->next && (p->next->data) <= mink)
    {
        p = p -> next;
    }
    while(p->next && (p->next->data) < maxk)
    {
        node<DataType> *q = p -> next;
        if(q != nullptr)
        {
            p -> next = q -> next;
            delete q;
        }
        else delete q;
    }
}

template <class DataType>
linkList<DataType>::linkList()
{
    first = new node<DataType>;
    first -> next = nullptr;
    node<DataType>* rear = first;
    int n;
    cin >> n;
    
    // 尾插法构造单链表
    for(int i = 0 ; i < n ; i++) 
    {
        DataType e;
        cin >> e;
        node<DataType>* s = new node<DataType>;
        s -> data = e;
        rear -> next = s;
        rear = s;
    }
}

// 头插法
template <class DataType>
void linkList<DataType>::reverse_node() 
{
    node<DataType> *p , *q;
    p = first -> next;
    first -> next = nullptr;
    
    while(p)
    {
        q = p;
        p = p -> next;
        q -> next = first -> next;
        first -> next = q;
    }
}

template <class DataType>
linkList<DataType>::~linkList()
{
    node<DataType>* p;
    while(first != NULL){
        p = first;
        first = first->next;
        delete p;
    }
}

// 删除连续重复的数据
template <class DataType>
void linkList<DataType>::Delete()
{
    node<DataType>*p , *q = nullptr;
    p = first -> next;
    while(p -> next)
    {
        if(p -> data == p -> next -> data)
        {
            q = p -> next;
            p -> next = q -> next;
            continue;
        }
        else p = p -> next;
    }
}

template <class DataType>
void linkList<DataType>::show()
{
    node<DataType>* p = first->next;
    if(p == nullptr) cout<<"Empty";
    else{
        while(p != NULL){
            cout<<p->data<<" ";
            p = p->next;
        }
        cout<<endl;
    }
}

int main()
{
    linkList<int> L;
    // L.Delete();
    //L.reverse_node();
    
    // auto p = L.Find_reverse_index(5);
    // cout << p -> data << endl;
    
    int mink , maxk;
    cin >> mink >> maxk;
    L.deleteList(mink ,maxk);
    
    
    L.show();
    L.~linkList();
    return 0;
}