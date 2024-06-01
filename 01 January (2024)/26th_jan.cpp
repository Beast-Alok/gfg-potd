#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};
// gfg solution from here
class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        vector<pair<double,double>>v;
        for(int i=0;i<n;i++){
            v.push_back({double(arr[i].value)/double(arr[i].weight),double(arr[i].weight)});
        }
        sort(v.begin(), v.end());
        double w= double(W);
        double ans=0;
        int i=n-1;
        while(w>0 && i>=0){
            double x=min(w, v[i].second);
            w-=x;
            ans+=x*v[i].first;
            i--;
        }
        return ans;
    }
        
};
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(6)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// code written by alok kumar raghuwanshi