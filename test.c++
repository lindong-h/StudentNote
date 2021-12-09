#include<bits/stdc++.h> 
using namespace std;
int n,m;
const int N=1010;
const int M=10010;
int head[N],nex[M*2],to[M*2];
int cnt;
void add(int x,int y){
    cnt++;
    to[cnt]=y;
    nex[cnt]=head[x];
    head[x]=cnt;
}    
int degree[N];//入度 
int d[N]; 
int ask[N];//询问 
bool f[110];
bool topsort(){
    for(int i=1;i<=n;i++){
        if(d[ask[i]])
            return 0;
        for(int j=head[ask[i]];j;j=nex[j])
            d[to[j]]--;
    }
    return 1;
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        degree[y]++;
        add(x,y);
    }
    int k;
    cin>>k;
    for(int i=0;i<k;i++){
        for(int j=1;j<=n;j++){
            cin>>ask[j];
            d[j]=degree[j];
        }
        if(topsort())
            f[i]=1;
        else
            f[i]=0;
    }
    for(int i=0;i<k;i++)
        if(!f[i])
            cout<<i<<' ';
    return 0;
}
