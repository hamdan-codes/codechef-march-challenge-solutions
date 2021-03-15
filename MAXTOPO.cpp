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
#define MOD             1000000007
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












int n;

const int N = (int)5e5 + 5;
int InverseFact[N + 1];
int InverseNum[N + 1];
int fact[N + 1];

void InverseofNumber(int p)
{
	InverseNum[0] = InverseNum[1] = 1;

	for (int i = 2; i <= N; i++)
		InverseNum[i] = InverseNum[p % i] * (p - p / i) % p;
}

void InverseofFactorial(int p)
{
	InverseFact[0] = InverseFact[1] = 1;

	for (int i = 2; i <= N; i++)
		InverseFact[i] = (InverseNum[i] * InverseFact[i - 1]) % p;
}

void factorial(int p)
{
	fact[0] = 1;
	for (int i = 1; i <= N; i++)
	{
		fact[i] = (fact[i - 1] * i) % p;
	}
}

int Binomial(int N, int R, int p)
{
	if (R > N)
		return 0;
	if (R == N)
		return 1;

	int calc = ((fact[N] * InverseFact[R]) % p * InverseFact[N - R]) % p;

	return calc;
}

vector<vi> present;
vi nodess;
vi no_ways;
vi sm_data;

int dfs(int node)
{
	nodess[node] = 1;
	int calc = 1, data = 0;

	for (auto x : present[node])
	{
		if (nodess[x] == 0)
		{
			int cur_dfs = dfs(x);
			data += cur_dfs;
			calc *= Binomial(data, cur_dfs, MOD);
			calc %= MOD;
			calc *= no_ways[x];
			calc %= MOD;
		}
	}

	calc %= MOD;
	no_ways[node] = calc;


	return data + 1;
}
bool Yes = false;
int XX;
vector<pair<int, pii>> data_min_x_node;

int get_node(int node)
{
	nodess[node] = 1;
	int to_return = 0, curr;

	for (auto x : present[node])
	{
		if (nodess[x] == 0)
		{
			curr = get_node(x);
			to_return += curr;
			data_min_x_node.pb({min(curr, (n - curr)), mp(x, node)});
		}
	}

	sm_data[node] = to_return + 1;


	return to_return + 1;
}





int32_t main() {

	c_p_p();
	//--------------------------- Your Code Below -----------------------------------------------






	factorial(MOD);
	InverseofNumber(MOD);
	InverseofFactorial(MOD);

	w(t)
	{

		int  k;
		cin >> n >> k;

		int m = n - 1;

		present.clear(), nodess.clear(), no_ways.clear();
		present.resize(n), nodess.resize(n, 0), no_ways.resize(n);

		while (m--)
		{

			int x, y;
			cin >> x >> y;

			present[x - 1].pb(y - 1);
			present[y - 1].pb(x - 1);

		}

		if (n == 1)
		{
			int mx = 0, mi = 0;

			if (k == 1)
			{
				nodess.clear(), no_ways.clear();
				nodess.resize(n, 0), no_ways.resize(n);
				dfs(mx);

				cout << mx + 1 << " " << no_ways[mx] % MOD << endl;
			}
			else
			{
				nodess.clear(), no_ways.clear();
				nodess.resize(n, 0), no_ways.resize(n);
				dfs(mi);

				cout << mi + 1 << " " << no_ways[mi] % MOD << endl;
			}

			continue;
		}

		while (Yes && (sm_data[0] == n - sm_data[m + 1]))
		{
			XX = data_min_x_node[0].ss.ff == data_min_x_node[0].ss.ss;
			sort(data_min_x_node.begin(), data_min_x_node.end(), greater<pair<int, pii>>());
			XX++;
		}




		data_min_x_node.clear(), sm_data.clear(), sm_data.resize(n);

		get_node(0);

		int idx = 1;

		sort(data_min_x_node.begin(), data_min_x_node.end(), greater<pair<int, pii>>());

		int mx, mi;

		if (data_min_x_node[0].ff != data_min_x_node[1].ff)
		{
			int X = data_min_x_node[0].ss.ff, Y = data_min_x_node[0].ss.ss;

			if (sm_data[X] == n - sm_data[X])
			{
				mx = max(X, Y);
				mi = min(X, Y);
			}
			else
			{
				if (sm_data[X] > n - sm_data[X])
				{
					mx = X;
					mi = Y;
				}
				else
				{
					mi = X;
					mx = Y;
				}
			}
		}
		else
		{
			vector<int> temp;

			if ((data_min_x_node[0].ss.ff == data_min_x_node[1].ss.ff) || (data_min_x_node[0].ss.ff == data_min_x_node[1].ss.ss))
			{

				mx = data_min_x_node[0].ss.ff;
			}
			else
			{
				mx = data_min_x_node[0].ss.ss;
			}

			idx = 1;

			temp.pb((data_min_x_node[0].ss.ff != mx) ? data_min_x_node[0].ss.ff : data_min_x_node[0].ss.ss);

			while (idx != n && data_min_x_node[idx - 1].ff == data_min_x_node[idx].ff )
			{
				temp.pb((data_min_x_node[idx].ss.ff != mx) ? data_min_x_node[idx].ss.ff : data_min_x_node[idx].ss.ss);
				++idx;
			}

			mi = *max_element(temp.begin(), temp.end());
		}


		if (k == 1)
		{
			nodess.clear(), no_ways.clear();
			nodess.resize(n, 0), no_ways.resize(n);
			dfs(mx);

			cout << mx + 1 << " " << ((no_ways[mx] % MOD) + MOD) % MOD << endl;
		}
		else
		{
			nodess.clear(), no_ways.clear();
			nodess.resize(n, 0), no_ways.resize(n);
			dfs(mi);

			cout << mi + 1 << " " << ((no_ways[mi] % MOD) + MOD) % MOD << endl;
		}
	}


	return 0;
}
