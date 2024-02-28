#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MAXN=(1e18)+10;
const ll MAXEL = 64;

ll n;
bool used[MAXEL];
vector<ll>a;
ll ans, cnt;

void read()
{
    cin >> n;
}

void fill_v()
{
    ll i = 1;
    while(i <= MAXN)
    {
        a.push_back(i);
        if(i % 2 == 0)
          i = 2 * i + 1;
        else 
          i *= 2;
      
        cnt++;
    }
}

ll bin_search(ll k)
{
    ll left = -1, right = cnt, mid;
    while(right - left > 1)
    {
        mid = (right + left) / 2;
        if(a[mid] <= k)
          left = mid;
        else 
          right = mid;
    }
    return left;
}

void solve()
{
    while(n > 0)
    {
        ll i = bin_search(n);
        if(!used[i])
          used[i]=1;
        else
        {
            ans = -1;
            break;
        }
        n -= a[i];
        ans++;
    }
    cout << ans << endl;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  
  read();
  fill_v();
  solve();
  
  return 0;
}
