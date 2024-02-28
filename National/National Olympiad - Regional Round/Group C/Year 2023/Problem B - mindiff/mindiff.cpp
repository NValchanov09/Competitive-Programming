#include<bits/stdc++.h>

#define endl '\n'

using namespace std;

typedef long long ll;

const ll MAXN = 1e5 + 10;
const ll MAXQ = 1e5 + 10;
const ll MAXA = 1e9 + 10;

ll a[MAXN];
ll ans[MAXN];
multiset<ll> s;
ll n,q;

void read()
{
    cin >> n >> q;
    for(ll i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
}

void precompute()
{
    ans[1] = 1e9 + 10;
    s.insert(a[1]);
    for(ll i = 2; i <= n; i++)
    {
        s.insert(a[i]);
        auto it_mid = s.find(a[i]);
        auto it_left = it_mid;
        auto it_right = it_mid;
        it_left--;
        it_right++;
        if(it_mid == s.begin())
        {
            ans[i] = min(ans[i - 1], llabs(*it_mid - *it_right));
        }
        else if(it_mid == s.end())
        {
            ans[i] = min(ans[i - 1], llabs(*it_mid - *it_left));
        }
        else
        {
            ans[i] = min(ans[i - 1], min(llabs(*it_mid - *it_left), llabs(*it_mid - *it_right)));
        }
    }
}

void process_queries()
{
    for(ll i = 1; i <= q; i++)
    {
        ll m;
        cin >> m;
        cout << ans[m] << " ";
    }
    cout << endl;
}

int main()
{
	  ios_base::sync_with_stdio(false);
	  cin.tie(nullptr);
	  cout.tie(nullptr);

    read();
    precompute();
    process_queries();

	  return 0;
}
