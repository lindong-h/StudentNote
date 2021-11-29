#include<iostream>
#include<cstring>
#include<queue>
typedef pair<int, int> PII;
using namespace std;
const int N = 3001;

int g[N][N];
int dist[N];
bool v[N];

int h[N], e[N], ne[N] ,w[N] , idx;

void add(int a , int b, int w)
{
    e[idx] = b, ne[idx] = h[a] , w[idx] = w, h[a] = idx++;
}



void dijkstra_1()
{
    memset(dist, 0x3f , sizeof dist);
    memset(v, false , sizeof v);
    d[1] = 0;

    for(int i = 1 ; i < n ; i++)
    {
        int x = 0;
        for(int j = 1 ; j <= n ; j++)
            if(!v[i] && dist[j] < dist[x] ) x = j;
        
        v[i] = true;
        
        for(int i = 1 ; i <= n ; i++)
        {
            d[y] = min(d[y] , d[x] + g[x][j])
        }
    }
}


memset(h, -1 ,sizeof h);
void dijkstra_2()
{
    memset(dist, 0x3f , sizeof dist);
    memset(v, false ,sizeof v);
    priority_queue<PII, vector<PII>, greater<PII>> q;
    q.push({1, 0});

    while(q.size())
    {
        auto t = q.top();
        q.pop();
        int ver = q.first, d = q.second;

        if(v[t]) continue;
        v[t] = true;

        for(int i = h[t] ; i != -1 ; i = ne[i])
        {
            int j = e[i];
            if(dist[j] > d + w[i])
                d[j] = d + w[i];
            q.push({j, d[j]});
        }
    }
}