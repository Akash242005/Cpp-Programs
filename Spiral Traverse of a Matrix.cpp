#include <iostream>
using namespace std;
int main() {
    int row;
    int col;
    cin >> row >> col;
    int arr[row][col];
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            cin >> arr[i][j];
        }
    }
    int top = 0;
    int bot = row-1;
    int left = 0;
    int right = col - 1;
    int d = 1;
    while(top<=bot && left<=right)
    {
        if(d==1)
        {
            for(int i=left;i<=right;i++)
            {
                cout << arr[top][i] << " ";
            }
            top++;
        }
        if(d==2)
        {
            for(int i=top;i<=bot;i++)
            {
                cout << arr[i][right] << " ";
            }
            right--;
        }
        if(d==3)
        {
            for(int i=right;i>=left;i--)
            {
                cout << arr[bot][i] << " ";
            }
            bot--;
        }
        if(d==4)
        {
            for(int i=bot;i>=top;i--)
            {
                cout << arr[i][left] << " ";
            }
            left++;
        }
        d++;
        if(d==5)
        {
            d = 1;
        }
    }
}
