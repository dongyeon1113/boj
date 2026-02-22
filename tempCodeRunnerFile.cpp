#include <iostream>
#include <algorithm>
using namespace std;
int binary_search(long card[],long target, int start, int end)
{
    if(start>end)
    {
        return 0;
    }
    int mid=(start+end)/2;
    if(card[mid]==target)
    {
        return 1;
    }
    else if(card[mid]>target)
    {
        return binary_search(card,target,start,mid-1);
    }
    else
    {
        return binary_search(card,target,mid+1,end);
    }
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    long card[500001]={0,};
    for (int i=0; i<n; i++)
    {
        cin>>card[i];
    }
    int m;
    cin>>m;
    for (int i=0; i<m; i++)
    {
        long target;
        cin>>target;
        int result=binary_search(card,target,0,n-1);
        cout<<result<<" ";
    }
}