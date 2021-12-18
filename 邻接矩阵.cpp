#include<iostream>
using namespace std;
const int N = 100;
bool st[N]; // 判重数组

template <typename DataType>
class MGraph{
public:
    MGraph(DataType a[], int n, int e); // 构造函数
    ~MGraph();
    void DFS(int v);
    void BFS(int v);
private:
    DataType vertex[N];  //  存储图中节点
    int edge[N][N];      //  存储图的边 
    int vertexNum , edgeNum;  //  节点数 ， 边数
}

template <typename DataType>
MGraph<DataType>:: MGraph(DataType a[],int n , int e)
{
    vertexNum = n , edgeNum = e;
    for(int i = 0 ; i < vertexNum ; i++) // 存储节点
        vertex[i] = a[i];
    
    for(int i = 0 ; i < vertexNum ; i++) //  初始化邻接矩阵
        for(int j = 0 ; j < vertexNum ; j++)
            edge[i][j] = 0;

    for(int k = 0 ; k < edgeNum ; k++)  //  依次输入每一条边
    {
        cin >> i >> j;
        edge[i][j] = 1 , edge[j][i] = 1 ; // 无向图
    }
}

template <typename DataType>
MGraph<DataType>::DFS(int v)
{
    cout << vertex[v] << endl; // 输出遍历到的节点
    st[v] = 1; // 该点已遍历

    //  遍历邻接节点
    for(int i = 0 ; i < vertexNum ; j++)
    {
        if(edge[v][i] == 1 && st[j] == 0)
            DFS(i);
    }
    
}

template <typename DataType>
MGraph<DataType>::BFS(int v)
{
    int q[N]; // 定义队列
    int hh = -1 , tt = -1; // 初始化队列
    cout << vertex[v] << endl; 
    st[v] = 1; 
    q[++hh] = v;  // 开始节点入队

    while(hh != tt) // 队不空
    {
        int t = q[++tt]; // 队头出队

        // 遍历 队头的 所有邻接节点。
        for(int i = 0 ; i < vertexNum ; i++)
        {
            if(edge[t][i] == 1 && st[i] == 0) // 未遍历过，边存在
            {
                cout << vertex[i] << endl;// 输出节点
                st[j] = 1;  // 已遍历
                q[++tt] = j; // 邻接节点入队
            }
        }
    } 

}
//   邻接矩阵转邻接表
void MatToList(AdjMatrix &A , AdjList &B)
{
    B.vertexNum = A.vertexNum;
    B.edgeNum = A.edgeNum;
    // 初始化邻接表头指针
    for(int i = 0 ; i < A.vertexNum ; i++)
    {
        B.adjlist[i].firstEdge = nullptr;
    }
    
    for(int i = 0 ; i < vertexNum ; i++)
        for(int j = 0 ; j < i ; j++)
            if(A.edge[i][j] != 0)
            {
                p = new EdgeNode;
                p -> adjvex = j;
                p -> next = B.adjlist[i].first;
                B.adjlist[i].firstEdge = p;
            }
}