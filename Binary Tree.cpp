#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
	vector<int> a(n);
	for(int i=0;i<n;i++)
	{
	    cin >> a[i];
	}
	sort(a.begin(),a.end());
	int mid = n/2;
	int low = 0;
	int high = n-1;
	int key;
	cin >> key;
	bool found = false;
	while(low<high)
	{
	    if(a[mid]==key)
	    {
	        cout << true << endl;
	        found = true;
	        break;
	    }
	    else if(a[mid]<key)
	    {
	        low = mid+1;
	        mid = (low+high)/2;
	    }
	    else if(a[mid]>key)
	    {
	        high = mid-1;
	        mid = (low+high)/2;
	    }
	}
	if(!found)
	{
	    cout << false << endl;
	}
	return 0;
}
