#include<iostream>
using namespace std;
const int N = 1010;
int f[N];

int main()
{
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i++) cin >> a[i]; 

    f[0] = 0;
    for(int i = 1 ; i <= n ; i++)
        for(int j = m ; j >= v[i] ; j--)
            f[j] = f[j - v[i]] + a[i];

    cout << f[n];
    
    return 0;
}