#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int maxSubarraySum(int arr[], int n)
    {
        int res=arr[0];
        int sum=arr[0];
        for(int i=1;i<n;i++)
        {
            sum=max(sum+arr[i],arr[i]);
            res=max(res,sum);             
        }
        return res;
    }
};

int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        cout << ob.maxSubarraySum(a, n) << endl;
    }
}
