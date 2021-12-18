#include"iostream"
using  namespace  std;
template<class  DataType>
struct  BiNode{
    DataType  key;
    BiNode*  lchild,*rchild;
};
template<class  DataType>
class  BiSortTree{
public:
    BiSortTree(DataType  arr[],int  n);
    ~BiSortTree(){Release(root);};//析构函数
    void  InsertBST(BiNode<DataType>*&root,BiNode<DataType>*s);//插入一个结点s
    BiNode<DataType>*  SearchBST(BiNode<DataType>  *root,DataType  key);
    BiNode<DataType>*  GetRoot();
private:
    BiNode<DataType>*  root;
    void  Release(BiNode<DataType>*  bt);
};
template<class  DataType>
BiSortTree<DataType>::BiSortTree(DataType  arr[],int  n)
{
    root  =  NULL;
    for(int  i  =  0;  i<n;  i++)
    {
        BiNode<DataType>  *s  =  new  BiNode<DataType>;
        s->key  =  arr[i];
        s->lchild  =  s->rchild  =  NULL;
        InsertBST(root,s);
    }
}
template<class  DataType>
void  BiSortTree<DataType>::Release(BiNode<DataType>  *bt)  //析构函数
{
        if(bt  ==  NULL)  return;
        else{
            Release(bt->lchild);
            Release(bt->rchild);
            bt  =  NULL;
        }
}
template<class  DataType>
void  BiSortTree<DataType>::InsertBST(BiNode<DataType>  *&root,BiNode<DataType>  *s)  //插入一个结点s
{
    if(root == nullptr)
    {
        s -> lchild = s -> rchild = nullptr;
        root = s;
    }
    else if(root -> key > s -> key) InsertBST(root -> lchild , s);
    else InsertBST(root -> rchild ,s);

}
template<class  DataType>
BiNode<DataType>*  BiSortTree<DataType>::SearchBST(BiNode<DataType>  *root,DataType  key)
{
    if(root == nullptr) return nullptr;
    if(root -> key == key) return root;
    else if(root -> key > key) return SearchBST(root -> lchild ,key);
    else return SearchBST(root -> rchild ,key);

}
template<class  DataType>
BiNode<DataType>*  BiSortTree<DataType>::GetRoot()
{
    return  root;
}
int  main()
{
    int  n;
    cin>>n;
    int  arr[n];
    for(int  i  =  0;  i<n;i++)
        cin>>arr[i];
    BiSortTree<int>  biSortTree(arr,n);
    int  searchKey;
    cin>>searchKey;
    if(biSortTree.SearchBST(biSortTree.GetRoot(),searchKey))
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;

    biSortTree.~BiSortTree();
    return  0;
}