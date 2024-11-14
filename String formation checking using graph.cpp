#include <bits/stdc++.h>
using namespace std;

#define M 3 
#define N 3 
string dic[] = {"SEED","FOR","BED","GO"};
int n = sizeof(dic)/sizeof(dic[0]);

bool is_word(string str)
{
    for(int i=0;i<n;i++)
    {
        if(str.compare(dic[i]) == 0)
        {
            return true;
        }
    }
    return false;
}

void find_word(char boggle[M][N],bool visited[M][N],int i,int j,string &str)
{
    visited[i][j] = true;
    str = str + boggle[i][j];
    if(is_word(str))
    {
        cout << str << endl;
    }
    for(int row = i-1;row<=(i+1) && row<M;row++)
    {
        for(int col=j-1;col<=j+1 && col<N;col++)
        {
            if(row>=0 && col>=0 && !visited[row][col])
            {
                find_word(boggle,visited,row,col,str);
            }
        }
    }
    str.erase(str.length()-1);
    visited[i][j] = false;
}

void findwords(char boggle[M][N])
{
    bool visited[M][N] = {{false}};
    string str = "";
    for(int i=0;i<M;i++)
    {
        for(int j=0;j<N;j++)
        {
            find_word(boggle,visited,i,j,str);
        }
    }
}
 
int main() {
    char boggle[M][N] = {{'A','B','C'},{'D','E','F'},{'G','S','E'}};  
    cout << "Following words of dictionary are present\n";
    findwords(boggle);
    return 0;
}
