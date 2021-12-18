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

template <typename DataType>
ALGraph<DataType>::DFS(int v)
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

template <typename DataType>
ALGraph<DataType>::BFS(int v)
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