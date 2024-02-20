#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

typedef long long ll;

const ll MAXN = 26;

ll dp[MAXN + 1];

int n;

void read()
{
    cin >> n;
}

void solve()
{
    dp[1] = 1;
    for(int i = 2; i <= n; i++)
    {
        int sz = 2 * (i - 1);
        for(int j = 0; j <= sz; j++)
        {
            dp[i] = dp[i] + sz + 1 - j;
        }
        dp[i] = dp[i] * dp[i - 1];
    }
    cout << dp[n] << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    read();
    solve();
    return 0;
}
