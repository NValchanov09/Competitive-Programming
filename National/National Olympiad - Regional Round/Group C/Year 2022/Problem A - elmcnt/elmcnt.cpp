#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int ll;

ll start, finish, n, br[10];

ll pieces[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

void read()
{
	  cin >> n >> start;
	  finish = start + n - 1;
}

ll zeroes(ll n)
{
	ll br = 0;
	while(n % 10 == 0)
	{
		n /= 10;
		br++;
	}
	return br;
}

void fill_br(ll cur, ll cnt)
{
	ll l = cur;
	while(l)
	{
		br[l % 10] += cnt;
		l /= 10;
	}
}

ll remove_zeroes(ll n)
{
	while(n % 10 == 0)
    n /= 10;

	return n;
}

ll exponentiation(ll base, ll exponent)
{
	if(exponent == 0)
    return 1LL;

	return exponentiation(base, exponent - 1) * base;
}

void solve()
{
	ll exponent, nine, nonzero, cur;
	cur = start;
	while(cur <= finish)
	{
		fill_br(cur, 1LL);
		exponent = zeroes(cur);

		if(exponent)
		{
			nine = exponentiation(10LL, exponent) - 1;

			if(cur + nine <= finish)
			{
				for(int i = 0; i < 10; i++)
				{
					br[i] += exponent * exponentiation(10LL, exponent - 1);
				}

				br[0] -= exponent;
				nonzero = remove_zeroes(cur);
				fill_br(nonzero, nine);
				cur += nine;
			}
		}

		cur++;
	}

	ll ans=0;

	for(int i = 0; i < 10; i++)
	{
		ans += (br[i] * pieces[i]);
	}
	cout << ans << endl;
}
int main()
{
    read();
    solve();

    return 0;
}
