#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

typedef long long ll;

const ll MAXN = 512;
const ll MAXM = 512;
const ll MOD = 998244353;

ll n, m, k;
ll c[MAXN][MAXN];
ll dp[MAXN][MAXM];

void read()
{
    cin >> n >> m >> k;
}

void fillc()
{
    for(ll i = 0; i <= n; i++)
    {
        c[i][0] = c[i][i] = 1;
        for(ll j = 1; j < i; j++)
        {
            c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % MOD;
        }
    }
}

void init()
{
    for(ll j = 0; j <= m; j++)
    {
        dp[0][j] = 1;
    }
}

void filldp()
{
    for(ll i = 1; i <= n; i++)
    {
        for(ll j = 1; j <= m; j++)
        {
            ll ends = min(i, k);
            for(ll cnt = 0; cnt <= ends; cnt++)
            {
                dp[i][j] = (dp[i][j] + dp[i - cnt][j - 1] * c[i][cnt] % MOD) % MOD;
            }
        }
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    read();
    init();
    fillc();
    filldp();
    
    cout<<dp[n][m]<<endl;

    return 0;
}
