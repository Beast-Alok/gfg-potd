//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    int merge(int low, int mid, int high, int arr[]){
        int left = low;
        int right = mid+1;
        int count = 0;
        vector<int>v;
        
        while(left <= mid && right <= high){
            if(arr[left] <= arr[right]){
                v.push_back(arr[left]);
                left++;
            }
            else{
                count += (mid-left+1);
                v.push_back(arr[right]);
                right++;
            }
        }
        
        while(left <= mid){
            v.push_back(arr[left]);
            left++;
        }
        while(right <= high){
            v.push_back(arr[right]);
            right++;
        }
        
        for(int i=low; i<=high; i++){
            arr[i] = v[i-low];
        }
        
        
        return count;
    }
    
    
    int mergefun(int low, int high, int arr[]){
        int count = 0;
        if(low == high) return 0;
        int mid = low + (high - low)/2;
        
        count+=mergefun(low, mid, arr);
        count+=mergefun(mid+1, high, arr);
        count+=merge(low, mid, high, arr);
        return count;
        
    }
    
    int countPairs(int arr[] , int n ) 
    {
        // Your code goes here  
        for(int i=0; i<n; i++) arr[i] = i*arr[i];
        return mergefun(0, n-1, arr);
    }
};

//{ Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	int a[n];
    	for(int i=0;i<n;i++)
    	cin>>a[i];
    	Solution ob;
    	cout<<ob.countPairs(a, n)<<endl;
    }
}
// } Driver Code Ends
