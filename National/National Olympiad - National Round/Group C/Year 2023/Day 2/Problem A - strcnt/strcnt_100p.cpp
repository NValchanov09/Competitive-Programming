#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

typedef long long ll;

const ll MAXN = 26;

string dp[MAXN + 1];
string subs[10];

int n;

void read()
{
    cin >> n;
}

string add_nulls(string s1, int nulls)
{
    string result = s1;
    for(int i = 1; i <= nulls ; i++)
    {
        result = "0" + result;
    }
    return result;
}

string add(string s1, string s2)
{
    int sz1 = s1.size();
    int sz2 = s2.size();
    s1 = add_nulls(s1, sz2 - sz1);
    s2 = add_nulls(s2, sz1 - sz2);

    sz1 = s1.size();
    sz2 = s2.size();

    string result = "";

    int p = 0;
    for(int i = sz1 - 1; i >= 0; i--)
    {
        int c = (s1[i] - '0') + (s2[i] - '0') + p;
        p = c / 10;
        c = c % 10;
        result = result + (char)('0' + c);
    }
    if(p != 0)
    {
        result = result + (char)('0' + p);
    }
    reverse(result.begin(), result.end());
    return result;
}

string mult_small(string s, ll d)
{
    int sz = s.size();
    int p = 0;
    string result = "";
    for(int i = sz - 1; i >= 0; i--)
    {
        int c = (s[i] - '0')* d + p;
        p = c / 10;
        c = c % 10;
        result = result + (char)('0' + c);
    }
    if(p != 0)
    {
        result = result + (char)('0' + p);
    }
    reverse(result.begin(), result.end());
    return result;
}

string mult_big(string s1, string s2)
{
    int sz1 = s1.size();
    int sz2 = s2.size();
    s1 = add_nulls(s1, sz2 - sz1);
    s2 = add_nulls(s2, sz1 - sz2);
    if(s1 < s2)
    {
        swap(s1, s2);
    }

    string result = "";

    for(int i = 0; i <= 9 ; i++)
    {
        subs[i] = mult_small(s1, i);
    }

    sz1 = s1.size();
    sz2 = s2.size();

    for(int i = sz1 - 1; i >= 0; i--)
    {
        int nulls = sz1 - i - 1;
        int c = s2[i] - '0';
        string cur = subs[c];
        for(int j = 1; j <= nulls; j++)
        {
            cur = cur + '0';
        }
        result = add(result, cur);
    }
    return result;
}

string remove_nulls(string s)
{
    while(s[0] == '0')
    {
        s.erase(0, 1);
    }
    return s;
}

void solve()
{
    dp[1] = "1";
    for(int i = 2 ; i <= n; i++)
    {
        int sz = 2 * (i - 1);
        for(int j = 0; j <= sz; j++)
        {
            int to_add = sz - j + 1;
            dp[i] = add(to_string(to_add), dp[i]);
        }
        dp[i] = mult_big(dp[i], dp[i - 1]);
        dp[i] = remove_nulls(dp[i]);
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
