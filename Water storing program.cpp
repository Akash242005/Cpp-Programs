#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    int i;
    for(i=0;i<n;i++)
    {
        cin >> a[i];
    }
    i = 0;
    int count =0;
    while(i<n)
    {
        if(a[i]==0)
        {
            i++;
        }
        else
        {
            break;
        }
    }
    i++;
    while(i< n-1)
    {
        int l=i-1;
        int r = n-1;
        int min = 0;
        int lmax = 0;
        int rmax = 0;
        while(l>=0)
        {
            if(a[l] >= lmax)
            {
                lmax = a[l];
            }
            l--;
        }
        while(i<r)
        {
            if(a[r]>=rmax)
            {
                rmax = a[r];
            }
            r--;
        }
        if(lmax>rmax)
        {
            min = rmax;
        }
        else
        {
            min = lmax;
        }
        if((min-a[i]) > 0)
        {
            count = count + (min - a[i]);
        }
        i++;
    }
    cout << count << endl;
    return 0;
}
