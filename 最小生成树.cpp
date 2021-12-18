#include  <iostream>
#include  <string.h>

using namespace std;

const int MAXSIZE = 100;
const int MAXVALUE = 0x3f3f3f3f;
int lowcost[MAXSIZE];    //存储最短边
int adjvex[MAXSIZE];      //存储最短边的邻接顶点

template<class DataType, class WeightType>
class MGraph {
	public:
		MGraph(DataType a[], int n, int e);

		~MGraph() {}

		WeightType prim(int v);

		int findVertex(DataType ver);    //查找某个顶点在顶点数组中的编号
		int minEdge(WeightType lowcost[], int len);

		int getVertexNum() {
			return vertexNum;
		};

		void show();

	private:
		int vertexNum;
		int edgeNum;
		DataType vertex[MAXSIZE];
		WeightType edge[MAXSIZE][MAXSIZE];
};

template<class DataType, class WeightType>
MGraph<DataType, WeightType>::MGraph(DataType a[], int n, int e) {
	vertexNum = n;
	edgeNum = e;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j) {
			edge[i][j] = MAXVALUE;      //求最小生成树时，需要对比交小值，所以这里初始化为无穷大
		}
	for (int i = 0; i < n; ++i)
		vertex[i] = a[i];
	for (int k = 0; k < e; ++k) {
		DataType startVer, endVer;
		WeightType weight;
		cin >> startVer >> endVer >> weight;
		int i, j;
		i = findVertex(startVer);
		j = findVertex(endVer);
		edge[i][j] = weight;
		edge[j][i] = weight;
	}
}

template<class DataType, class WeightType>
int MGraph<DataType, WeightType>::findVertex(DataType ver) {
	for (int i = 0; i < vertexNum; ++i)
		if (vertex[i] == ver) return i;
	return -1;
}

template<class DataType, class WeightType>
WeightType MGraph<DataType, WeightType>::prim(int v) {
	int minCost = 0;
	int i, j, k;
	for (i = 0; i < vertexNum; i++) { // 初始化辅助数组
		lowcost[i] = edge[v][i];  //最短边的权值
		adjvex[i] = v;    // 最短边的邻接点
	}
	lowcost[v] = 0; // 到自己的权值为0
	for (k = 1; k < vertexNum; k++) {  // 迭代执行n-1次  寻找n-1个点
		j=minEdge(lowcost,vertexNum);   //寻找最短边的邻接点
		minCost+=lowcost[j];
		lowcost[j]=0;   //顶点j加入到集合U
		for(i=0; i<vertexNum; i++) {
			if(edge[i][j]<lowcost[i]) {
				lowcost[i]=edge[i][j];
				adjvex[i]=j;
			}
		}
	}

	return minCost;
}

template<class DataType, class WeightType>
int MGraph<DataType, WeightType>::minEdge(WeightType lowcost[], int len) {
	WeightType minValue = MAXVALUE;
	int minIndex = -1;
	for (int i = 0; i < len; ++i) {
		if (minValue > lowcost[i] && lowcost[i] != 0) {
			minValue = lowcost[i];
			minIndex = i;
		}
	}
	return minIndex;
}

template<class DataType, class WeightType>
void MGraph<DataType, WeightType>::show() {
	for (int i = 0; i < vertexNum; ++i) {
		for (int j = 0; j < vertexNum; ++j) {
			if (edge[i][j] == MAXVALUE) cout << "∞" << "  ";
			else cout << edge[i][j] << "  ";
		}
		cout << endl;
	}
}

int main() {
	int n, e;
	cin >> n >> e;
	char a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	MGraph<char, int> MG(a, n, e);
	char startVer;
	cin >> startVer;
	//MG.show();
	cout << MG.prim(MG.findVertex(startVer)) << endl;
	return 0;
}
