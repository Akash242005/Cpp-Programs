#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	int count = 0;
	int ans = 0;
	while(true)
	{
	    int mul = n;
	    while(mul!=0)
	    {
	        int rem = mul%10;
	        ans = ans + rem*rem;
	        mul = mul/10;
	    } 
	    n = ans;
	    ans = 0;
	    if(n/10 ==0)
	    {
	        if(n==1 || n==7)
	        {
	            count++;
	            cout << "happy" << endl;
	        }
	        break;
	    }
	}
	if(count==0)
	{
	    cout << " Un happpy" <<endl;
	}
	return 0;
}
