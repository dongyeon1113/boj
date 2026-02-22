#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
    long n,m;
    cin>>n>>m;
    long tree[1000001]={0,};
    for (int i=0; i<n; i++)
    {
        cin>>tree[i];
        sort(tree,tree+n);
        
    }
}