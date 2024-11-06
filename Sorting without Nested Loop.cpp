#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<int> arr(n);
	for(int i=0;i<n;i++)
	{
	    cin >> arr[i];
	}
	int low = 0;
	int low1 = 0;
	while(low<n)
	{
	    if(arr[low]<arr[low1])
	    {
	        int temp = arr[low];
	        arr[low] = arr[low1];
	        arr[low1] = temp;
	        if(low1==(n-1))
	        {
	            low++;
	            low1 = 0;
	        }
	    }
	    else if(low1==(n-1))
	    {
	       low1 = 0;
	       low++;
	    }
	    else
	    {
	        low1++;
	    }
	}
	for(int i=0;i<n;i++)
	{
	    cout << arr[i] << " ";
	}
	return 0;
}
