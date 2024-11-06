#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
	string final = "1";
	string ans = "";
	int count = 0;
	for(int i=0;i<n-1;i++)
	{
	    for(int j=0;j<final.size();j++)
	    {
	        count++;
	        if((j==(final.size()-1) && final[j] != final[j-1]) || (j==(final.size()-1) && final[j] == final[j-1]))
	        {
	            char c = count + '0';
	            ans = ans + c;
	            ans = ans + final[j];
	            count = 0;
	        }
	        else if(final[j] != final[j+1])
	        {
	            char c = count + '0';
	            ans = ans + c;
	            ans = ans + final[j];
	            count = 0;
	        }
	    }
	    final = "";
	    final = ans;
	    ans = "";
    }
    cout << final << endl;
	return 0;
}
