#include <iostream>
#include <string>
using namespace std;

int main() {
	// your code goes here
	
	int t; cin >> t;
	for(int i=0;i<t;i++)
	{
	    string s;
	    cin >> s;
	    int l = s.length();
	    int ans = 0;
	    
	    char prev = s[0];
	    
	    for(int j=1;j<l;j++)
	    {
	        if(prev=='1' and s[j] == '0')
	            ans++;
	        
	        prev = s[j];
	    }
	    if(prev == '1')
	        ans++;
	    
	    
	    
	    
	    cout << ans << '\n';
	}
	
	
	
	
	return 0;
}
