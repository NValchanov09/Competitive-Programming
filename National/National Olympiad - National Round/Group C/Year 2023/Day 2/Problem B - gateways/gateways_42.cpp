#include<bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 10;

int a[MAXN];
int n,q;

int query(int t)
{
    for(int i = 1; i <= n; i++)
    {
        long long int sum = 0;
        bool lampa = true;
        for(int j = 0; j < n; j++)
        {
            if(j < i)sum+=t;
            sum-=a[j];
            if(sum < 0)
            {
                lampa = false;
                break;
            }
        }
        if(lampa)
            return i;
    }
    return -1;
}

void read()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cin >> q;
    for(int i = 1; i <= q; i++)
    {
        int t;
        cin >> t;
        cout << query(t) << endl;
    }
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	read();

	return 0;
}
