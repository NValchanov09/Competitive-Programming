#include <bits/stdc++.h>

using namespace std;

const int MAXN = (1e5) + 10;
const int MAXEL = (1e9) + 10;
int n, m, cntd;
int a[MAXN], b[MAXN];

void read()
{
  	cin >> n;
  	for(int i = 0; i < n; i++)
  	{
  		  cin >> a[i];
  	}
    
  	a[n] = MAXEL;
    
  	cin >> m;
  	for(int i = 0; i < m; i++)
  	{
  		  cin >> b[i];
  	}
    
  	b[m] = MAXEL;
}
void solve()
{
  	sort(a, a + n + 1);
  	sort(b,b + m + 1);
  	int i = 0, j = 0, ans = 0;
  	if(a[n - 1] != b[m - 1])
  	{
  		  cout<<"NO"<<endl;
  		  return;
  	}
  
  	while(i < n || j < m)
  	{
    	  if(a[i] > b[j]) 
          j++;
    		else if(a[i] < b[j]) 
          i++;
    		else
    		{
    			  i++;
    			  j++;
    		}
    		  ans++;
    }
    cout<<ans<<endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    read();
    solve();
    return 0;
}
