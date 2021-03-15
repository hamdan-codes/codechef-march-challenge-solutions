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





	w(t) {

		int n;
		cin >> n;

		vector<pii> p, st;

		f(i, 0, n, 1) {

			int v;
			cin >> v;
			p.pb({i + 1, v});
		}

		if (n == 2) {

			cout << "1\n";
			continue;
		}

		st.pb(p[0]);
		st.pb(p[1]);

		int ans = 1, len = st.size();

		f(i, 2, n, 1) {

			while (st.size() >= 2) {

				double s1 = ((double)st[len - 1].ss - (double)st[len - 2].ss) / ((double)st[len - 1].ff - (double)st[len - 2].ff);
				double s2 = ((double)p[i].ss - (double)st[len - 1].ss) / ((double)p[i].ff - (double)st[len - 1].ff);

				if (s1 <= s2) {

					st.pop_back();
					len--;
				}
				else
					break;
			}

			st.pb(p[i]);

			len++;

			ans = max(ans, st[len - 1].ff - st[len - 2].ff);
		}


		cout << ans << endl;
	}


	return 0;
}

