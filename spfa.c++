#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
const int N = 100010;
int n, m;
int h[N], e[N] , ne[N], w[N],idx;
void add(int a, int b, int w)
{
    e[idx] = b, ne[idx] = h[a];
    w[idx] = w, h[a] = idx ++;
}
int d[N];
bool v[N];

/*
    某一条边 （x, y, z）
当图中所有的点都满足 d[y] < d[x] + z;
则 d[] 数组就是所求的最短路

*/

void spfa()
{
    memset(d, 0x3f , sizeof d);
    memset(v, 0 ,sizeof v);
    d[1] = 0;
    v[1] = 1;

    q.push(1);
    while(q.size())
    {
        int x = q.front(), q.pop();
        v[x] = 0;
        
        for(int i = h[x] ; i != -1; i++)
        {
            int y = e[i], z = w[i];
            if(d[y] > d[x] + z)
            {
                d[y] = d[x] + z;
                if(!v[i]) q.push(y), v[y] = 1;8
            }
        }
    }



}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    memset(h, -1, sizeof h);
    cin >> n >> m;
    for(int i = 1 ; i <=  m ;i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        add(a, b, w);
    }

    spfa();

    return 0;
}