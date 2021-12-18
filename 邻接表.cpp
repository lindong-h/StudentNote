#include<iostream>
using namespace std;
const int N = 100;
bool st[N];  // 判重数组

struct EdgeNode{        // 边表节点
    int adjvex;         // 邻接点信息
    EdgeNode* next;     // 指向下一个邻接点的指针
};
template <typename DataType>
struct VextexNode       // 定义顶点表节点
{
    DataType vertex;     // 节点信息
    EdgeNode* firstEdge; // 边表的头指针
}

template <typename DataType>
class ALGraph
{
public:
    ALGraph(DataType a[] , int n ,int e);
    ~ALGraph();
    void DFS(int v);
    void BFS(int v);

private:
    VertexNode<DataType> adjlist[N];    // 存放顶点表的数组
    int vertexNum , edgeNum;            // 图中顶点数和边数
}
//  建立邻接表
template <typename DataType>
ALGraph<DataType>:: ALGraph(DataType a[] , int n, int e)
{
    EdgeNode* s = nullptr;
    vertexNum = n, edgeNum = e;

    for(int i = 0 ; i < vertexNum ; i++)    //输入顶点信息，初始化顶点表
    {
        adjlist[i].vertex = a[i];
        adjlist.firstEdge = nullptr;
    }

    for(int k = 0 ; k < edgeNum ; k++)
    {
        cin >> i >> j;          // 输入边的信息
        s = new EdgeNode;       
        s -> adjvex = j;        

        s -> next = adjlist[i].firstEdge;   // 生成一个边表节点
        adjlist[i].firstEdge = s;   // 将节点 s 插入表头
    }

}
//  深度优先遍历邻接表
template <typename DataType>
ALGraph<DataType>::DFS(int v) //     memset(st , 0 , sizeof st);
{
    EdgeNode *p = nullptr;
    cout << adjlist[v].vertex << endl;
    st[v] = 1;

    p = adjlist[v].firstEdge; // 替换头节点
    //  遍历邻接表
    while(p != nullptr)
    {
        int j = p -> adjvex;
        if(st[j] == 0) DFS(j); // 未遍历
        p = p -> next;
    }
}
// 宽度优先遍历邻接表
template <typename DataType>
ALGraph<DataType>::BFS(int v) //     memset(st , 0 , sizeof st);
{
    int q[N] , hh = -1 , tt = -1; // 初始化队列
    EdgeNode* p = nullptr;
    cout << adjlist[v].vertex << endl;
    st[v] = 1;
    q[++tt] = v;        // 开始节点入队

    while(hh != tt)
    {
        int t = q[++hh];            // 出队头
        p = adjlist[t].firstEdge;   // 替换队头边表的头指针

        while(p != nullptr)         // 队列不空
        {
            int j = p -> vertex;
            if(st[j] == 0)          // 未遍历
            {
                cout << adjlist[j].vertex << endl;
                q[++tt] = j;        // 入队
            }
            p = p -> next;
        }
    }
}

// 邻接表转化为邻接矩阵
void ListToMat(AdjList &A, AdjMatList &B)
{
    A.vertexNum = B.vertexNum;
    A.edgeNum = B.edgeNum;

    //  初始化邻接矩阵
    for(int i = 0 ; i < A.vertexNum ; i++)
        for(int j = 0 ; j < A.vertexNum ; j++)
            A.edge[i][j] = 0;

    // 遍历边表的节点，修改 该节点所在行的值
    for(int i = 0 ; i < A.vertexNum ; i++)
    {
        p = B.adjlist[i].firstEdge;
        while(p)
        {
            j = p -> adjvex;
            a[i][j] = 1;
            p = p -> next;
        }
    }
}

//  建立逆邻接表
void InverseList(AdjList A , AdjList B)
{
    B.vertexNum = A.vertexNum;
    B.edgeNum = A.edgeNum;

    for(int i = 0 ; i < A.vertexNum ; i++)
        B.adjlist[i].firstEdge = nullptr;

    EdgeNode *p1 = new EdgeNode;
    EdgeNode *p2 = nullptr;
    for(int i = 0 ; i < A.vertexNum ; i++)
    {
        p1 = A.adjlist.firstEdge;
        while(p1)
        {
            j = p1 -> adjvex;
            p2 = new EdgeNode;

            p2 -> adjvex = i;
            p2 -> next = B.adjlist[j].firstEdge;
            B.adjlist[j].firstEdge = p2;
            p1 = p1 -> next;
        }
    }
}

// 判断路径 DFS
int DFS(int i , int j) // 判断 i 到 j 之间是否存在路径 memset(st , 0 , sizeof st);
{   
    int stack[N] , tt = -1;
    st[i] = 1;
    stack[++tt] = i;
    int flag = 0;
    while(tt != -1 || flag == 0)
    {
        i = stack[tt];
        p = adjlist[i].firstEdge;
        while(p && flag == 0)
        {
            auto t = p -> adjvex;
            if(t == j) flag = 1;
            else if(st[t] == 0)
            {
                st[t] = 1;
                stack[++tt] = t;
            }
            else p = p -> next;
        }
        if(!p) tt --;
    }
    return flag;
}

// 判断路径 BFS
int BFS(int i , int j) // 判断 i 到 j 之间是否存在路径 memset(st , 0 , sizeof st);
{   
    int q[N], hh = -1 , tt = -1;
    st[i] = 1;
    q[++tt] = i;

    int flag = 0;
    while(hh != tt || flag == 0)
    {
        i = q[++hh];
        auto p = adjlist[i].firstEdge;

        while(p && flag == 0)
        {
            auto t = p -> adjvex;
            if(t == j) flag = 1;
            else if(st[t] == 0)
            {
                st[t] == 1;
                q[++tt] = t;
            }
            else p = p -> next;
        }
    }
    return flag;
}