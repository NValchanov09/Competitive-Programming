#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 2e5 + 10;

ll a[MAXN], dp[MAXN], pref[MAXN], opt[MAXN], cur[MAXN];
ll n,q;

void precompute()
{
    dp[1] = pref[1];
    for(int i = 2; i <= n; i++)
    {
        ll cur = pref[i] / i;
        if(pref[i] % i > 0)
            cur++;

        dp[i] = max(dp[i - 1], cur);
    }
    for(int i = 1; i <= n; i++)
    {
        ll cur = pref[n] / i;
        if(pref[n] % i != 0)
            cur++;

        opt[i] = max(dp[n], cur);
    }
    int i = 1, j = n;
    while(i <= n && j >= 1)
    {
        cur[i] = opt[j];
        i++;
        j--;
    }
}

ll my_upper_bound(ll target)
{
    ll left = 1, right = n, mid;
    while(left <= right)
    {
        mid = left + (right - left) / 2;
        if(cur[mid] <= target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return right;
}

ll solve(ll target)
{
    ll pos = my_upper_bound(target);
    return pos == 0 ? -1 : n - pos + 1;
}

void process_query()
{
    cin >> q;
    for(int i = 1; i <= q; i++)
    {
        ll t;
        cin >> t;
        cout << solve(t) << endl;
    }
}

void read()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        pref[i] = pref[i - 1] + a[i];
    }


}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	read();
	precompute();
	process_query();

	return 0;
}
