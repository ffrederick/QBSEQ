#include <iostream>
using namespace std;
int n, k, a[1001], du[1001], f[1001], cs[1001];
int j = 0;
void truyvet(int i, int &j)
{
    if (i <= n)
    {
        du[i] = (du[i-1] + a[i]) % k;
        if (cs[du[i]] != -1)
            f[i] = max(f[i-1], f[cs[du[i]]] + i - cs[du[i]]);
        else
        {
            cs[du[i]] = i;
            f[i] = f[i-1];
        }
        truyvet(i+1, j);
        if (i != j)
        {
            cout << a[i] << " ";
        }
        else
        {
            j = cs[du[i-1]];
        }
    }
    else j = cs[du[n]];
}
int main()
{
    cin >> n >> k;
    du[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        cs[i] = -1;
        f[i] = 0;
    }
    truyvet(1, j);
    return 0;
}
