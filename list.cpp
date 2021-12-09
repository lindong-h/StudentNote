#include<bits/stdc++.h>
using namespace std;
const int N = 100;
int q[N];
int n;
void add(int a) // 顺序添加
{
    int i;
    for(i = n - 1 ; i >= 0 && q[i] > a ; i--)
        q[i + 1] = q[i];
    q[i + 1] = a;
    n ++;
}

void remove_q(int x) // 删除所有的 x 
{
    int j = 0;
    for(int i = 0 ; i < n ; i++)
    {
        if(q[i] == x) j++;
        else q[i - j] = q[i];
    }
    n -= j;
}

void reverse_q() // 非递归
{
    int t;
    for(int i = 0,j = n - 1 ; i < j ;i++ , j--)
    {
        t = q[i];
        q[i] = q[j];
        q[j] = t;
    }
}


int main()
{
    cin >> n;
    for(int i = 0 ; i < n ; i++)
        cin >> q[i];
    int x;
    cin >> x;
    // add(x);
    // remove_q(x);
    
    reverse_q();
    
    for(int i = 0 ; i < n ; i++)
        cout << q[i] << " "; 
    
    
    return 0;
}