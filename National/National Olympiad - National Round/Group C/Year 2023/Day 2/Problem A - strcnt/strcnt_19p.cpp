#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

typedef long long ll;

const ll MAXN = 26;

bool used_cap[MAXN];
bool used_sml[MAXN];

vector<char> p;
int n;
int m;
int ans;

void read()
{
    cin >> n;
    m = 2 * n;
}

void solve()
{
    if(p.size() == m)
    {
        ans++;
        return;
    }
    for(int i = 0; i < n; i++)
    {
        if(!used_sml[i] && !used_cap[i])
        {
            char c = 'A' + i;
            p.push_back(c);
            used_cap[i] = true;
            solve();
            p.pop_back();
            used_cap[i] = false;
        }
    }
    for(int i = 0; i < n; i++)
    {
        if(used_cap[i] && !used_sml[i])
        {
            char c = 'a' + i;
            p.push_back(c);
            used_sml[i] = true;
            solve();
            p.pop_back();
            used_sml[i] = false;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    read();
    solve();

    cout << ans << endl;

    return 0;
}
