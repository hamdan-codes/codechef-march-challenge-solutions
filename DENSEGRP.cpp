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
typedef long long int ll;


void c_p_p()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("C:\\Users\\KIIT\\input.txt", "r", stdin);
	freopen("C:\\Users\\KIIT\\output.txt", "w", stdout);
#endif
}
//--------------------------- Your Functions Below ----------------------------------------------












vector<ll> p1;
vector<ll> p2;

bool isinrange(ll a, ll b) {
	for (ll i = 0; i < p1.size(); i++)
		if (p1[i] <= b && p2[i] >= a)
			return true;

	return false;
}


int main()
{
	c_p_p();
	//--------------------------- Your Code Below -----------------------------------------------




	ll t;
	cin >> t;
	while (t--)
	{
		ll n, m, x, y;
		cin >> n >> m >> x >> y;

		ll a[m], b[m], c[m], d[m];

		for (ll i = 0; i < m; i++) {
			cin >> a[i] >> b[i] >> c[i] >> d[i];
		}
		if (x == y) {
			cout << "0\n";
			continue;
		}

		ll di[m];
		ll ans = -1;
		ll z = 0;

		vector<ll> q1;
		vector<ll> q2;

		for (ll i = 0; i < m; i++) {
			di[i] = 0;
		}

		q1.push_back(x);
		q2.push_back(x);

		while ((ans == -1) && (q1.size() != 0)) {

			p1.clear();
			p2.clear();

			p1 = q1;
			p2 = q2;

			vector<ll> w1;
			vector<ll> w2;

			for (ll i = 0; i < (m); i++) {
				if ((di[i] == 0) && isinrange(a[i], b[i])) {

					w1.push_back(c[i]);
					w2.push_back(d[i]);

					if (c[i] <= y && d[i] >= y) {
						ans = z + 1;
					}

					di[i] = 1;
				}
			}

			q1 = w1;
			q2 = w2;
			z++;

		}

		cout << ans << endl;


	}




	return 0;
}