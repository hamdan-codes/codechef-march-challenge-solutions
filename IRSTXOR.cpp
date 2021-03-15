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




#include<bits/stdc++.h>
#include <cmath>
#include <ext/pb_ds/assoc_container.hpp>
#include<iostream>
using namespace __gnu_pbds;
using namespace std;

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
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define endl            "\n"
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
#define f(i,x,y,inc)    for(int i = x; i < y; i += inc)
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

int setBitNumber(int n)
{
	if (n == 0)
		return 0;

	int msb = 0;
	n = n / 2;
	while (n != 0) {
		n = n / 2;
		msb++;
	}

	return (1 << msb);
}

int32_t main()
{
	c_p_p();
	//----------------------------- Your Code Below ------------------------------------------------


	w(t)
	{
		int c; cin >> c;

		int set = setBitNumber(c);

		int i = 1;

		int a = set, b = set - 1;

		while (i <= set)
		{

			if (!(i & c))
				a += i;
			i <<= 1;
		}

		cout << a * b << endl;
	}


	return 0;
}
