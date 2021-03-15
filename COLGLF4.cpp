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
#define setbits(x)      __builtin_apcountll(x)
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

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;


void c_p_p()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("C:\\Users\\KIIT\\input.txt", "r", stdin);
	freopen("C:\\Users\\KIIT\\output.txt", "w", stdout);
#endif
}
//--------------------------- Your Functions Below --------------------------------------







int32_t main()
{
	c_p_p();
	//--------------------------- Your Code Below -----------------------------------




	w(t)
	{
		int n, e, h, a, b, c;
		cin >> n >> e >> h >> a >> b >> c;

		vector<int> sol;
		vector<int> tempvec;

		for (int i = 0; i <= n + 1; i++)
			tempvec.push_back(i);

		for (int m = 0; m <= n; m++)
		{
			int low_bound = lower_bound(tempvec.begin(), tempvec.end(), (2 * n - e - 2 * m)) - tempvec.begin();
			int up_bound = upper_bound(tempvec.begin(), tempvec.end(), (h - 3 * m)) - tempvec.begin() - 1;

			if (up_bound < low_bound || low_bound == n + 1)
				continue;

			if (up_bound == n + 1 && up_bound + 3 * m > h)
				continue;

			int k;

			if (c > a)
				k = (low_bound < (n - m) ? low_bound : (n - m));

			else
				k = (up_bound < (n - m) ? up_bound : (n - m));

			int o = n - k - m;

			if (k + 2 * m >= 2 * n - e && k + 3 * m <= h)
				sol.push_back(a * o + b * m + c * k);
		}

		if (sol.size() == 0)
			cout << -1 << endl;
		else
		{
			int min = sol[0];
			for (int i = 0; i < sol.size(); i++)
				if (sol[i] < min)
					min = sol[i];

			cout << min << endl;
		}

	}




	return 0;
}
