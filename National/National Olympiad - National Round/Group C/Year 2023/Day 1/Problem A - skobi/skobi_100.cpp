#include<bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 10;

string s;
bool used[MAXN];
int cnt_left, cnt_right, cur;
int n;

void read()
{
    cin >> s;
    n = s.size();
}

void goLR()
{
    for(int i = 0; i < n; i++)
    {
        if(s[i] == '(')
        {
            cur++;
        }
        else if(cur == 0)
        {
            cnt_left++;
        }
        else
        {
            cur--;
        }
    }
}

void goRL()
{
    cur = 0;
    for(int i = n - 1; i >= 0; i--)
    {
        if(s[i] == ')')
        {
            cur++;
        }
        else if(cur == 0)
        {
            used[i]=true;
            cnt_right++;
        }
        else
        {
            cur--;
        }
    }
}

void solve()
{
    cur = 0;
    int minc = 0,maxc = 0;
    for(int i = 0; i < n; i++)
    {
        if(s[i] == '(')
        {
            if(!used[i])cur++;

            minc = max(minc, cur);
        }
        else
        {
            if(cur) cur--;

            else minc = max(minc, cur+1);
        }
    }

    cur = maxc = cnt_left;
    for(int i = 0; i < n; i++)
    {
        if(s[i] == '(')
        {
            cur++;
            maxc = max(maxc, cur);
        }
        else cur--;
    }
    cout << minc << " " << maxc <<endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    read();
    goLR();
    goRL();
    solve();

	return 0;
}
