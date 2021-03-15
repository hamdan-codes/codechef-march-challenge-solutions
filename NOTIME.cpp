#include <iostream>
using namespace std;

int main() {
	// your code goes here
	
	int n, h, x;
	cin >> n >> h >> x;
	int a, m = 0;
	for(int i=0;i<n;i++)
	{
	    cin >> a;
	    if(a>m)
	        m=a;
	}
	if((m+x) >= h)
	    cout << "YES\n";
	else
	    cout << "NO\n";
	
	
	
	return 0;
}
