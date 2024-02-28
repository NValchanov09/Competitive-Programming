#include<bits/stdc++.h>

#define endl '\n'

using namespace std;

typedef long long ll;

const ll MAXN = 2e5 + 10;
const ll MAXA = 2e6 + 10;
const ll MAXK = 1e18 + 10;

ll n,k;
ll a[MAXN];
ll p[MAXA + 10];
ll sd[MAXA + 10];
ll cnt = 1;

void read()
{
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
}

void change_prod(ll x, ll change)
{
    while(x != 1)
    {
        ll div = sd[x];
        cnt = (cnt / (p[div] + 1));
        p[div] += change;
        cnt = (cnt * (p[div] + 1));
        x /= div;
    }
}

void fill_sd()
{
    for(int i = 1; i <= MAXA; i++)
    {
        sd[i] = i;
    }
    for(int i = 2; i * i <= MAXA; i++)
    {
        if(sd[i] != i)
            continue;
        for(int j = i * i; j <= MAXA; j+=i)
        {
            sd[j] = i;
        }
    }
}

void solve()
{
    ll left = 1, right = 1;
    ll ans = 0;
    while(right <= n)
    {
        change_prod(a[right], 1);
        while(left < right && cnt >= k)
        {
            change_prod(a[left], -1);
            left++;
        }
        if(cnt < k && left != 1)
        {
            left--;
            change_prod(a[left], 1);
        }
        if(cnt >= k)
            ans += left;
        right++;
    }
    cout << ans << endl;
}

int main()
{
	  ios_base::sync_with_stdio(false);
	  cin.tie(nullptr);
	  cout.tie(nullptr);

    read();
    fill_sd();
    solve();

	  return 0;
}
