/*
 * Author Chaudhary Hamdan
 * C++ Template for Competitive Programming
 * Github link : https://github.com/hamdan-codes
 * */

/*
 * Template available at my Github
 * Repository Link :-
 * https://github.com/hamdan-codes/templates-for-CP/
 * */




#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <string>
#include <list>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <unordered_map>
#include <set>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/exception.hpp>
#include <ext/pb_ds/hash_policy.hpp>
#include <ext/pb_ds/list_update_policy.hpp>
#include <ext/pb_ds/tag_and_trait.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/trie_policy.hpp>

#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             LONG_LONG_MAX
#define ps(x,y)         fixed<<setprecision(y)<<x
#define endl            "\n"
#define mk(arr,n,type)  type *arr=new type[n]
#define w(x)            int x; cin>>x; while(x--)
#define f(i,x,y,inc)    for(int i = x; i < y; i += inc)


using namespace std;

using namespace __gnu_pbds;
using namespace __gnu_cxx;

mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;


void c_p_p()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("C:\\Users\\KIIT\\input.txt", "r", stdin);
	freopen("C:\\Users\\KIIT\\output.txt", "w", stdout);
#endif
}
//--------------------------- Your Functions Below ----------------------------------------------







int32_t main()
{
	c_p_p();
	//--------------------------- Your Code Below -----------------------------------------------






	w(t)
	{
		int r, c, x;
		cin >> r >> c >> x;

		int a[r][c], b[r][c], arrdiff[r][c];

		int suma = 0, sumb = 0;

		f(i, 0, r, 1)
		{
			f(j, 0, c, 1)
			{
				cin >> a[i][j];
				suma += a[i][j];
			}
		}

		f(i, 0, r, 1)
		{
			f(j, 0, c, 1)
			{
				cin >> b[i][j];
				sumb += b[i][j];
			}
		}


		f(i, 0, r, 1)
		{
			f(j, 0, c, 1)
			{
				arrdiff[i][j] = b[i][j] - a[i][j];
			}
		}
		f(j, 0, c, 1)
		{
			int addedd = 0;
			int addindex = r - x;

			while (addindex >= 0)
			{
				addedd += arrdiff[addindex][j];
				addindex -= x;
			}

			for (int i = r - 1; i > r - x; i--)
			{
				int dif = i - x;

				while (dif >= 0)
				{
					arrdiff[i][j] += arrdiff[dif][j];
					dif = dif - x;
				}
				arrdiff[i][j] -= addedd;
			}
		}


		for (int i = r - 1; i > r - x; i--)
		{
			int addedd = 0;
			int addindex = c - x;

			while (addindex >= 0)
			{
				addedd += arrdiff[i][addindex];
				addindex -= x;
			}

			for (int j = c - 1; j > c - x; j--)
			{
				int dif = j - x;

				while (dif >= 0)
				{
					arrdiff[i][j] += arrdiff[i][dif];
					dif = dif - x;
				}

				arrdiff[i][j] -= addedd;
			}
		}

		bool ans = 1;

		for (int i = r - 1; i > r - x; i--)
		{
			for (int j = c - 1; j > c - x; j--)
			{
				if (arrdiff[i][j] != 0)
				{
					ans = 0;
					break;
				}
			}

			if (!ans)
				break;
		}

		if (ans)
			cout << "Yes" << endl;

		else
			cout << "No" << endl;


	}



	return 0;
}
