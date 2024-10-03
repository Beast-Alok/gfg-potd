//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find the majority elements in the array
    vector<int> findMajority(vector<int>& nums) {
        
        vector<int> ans;
        
        int count = 1;
        int n = nums.size();
        if(n < 3) return nums;
        
        sort(nums.begin(),nums.end());
        
        for(int i =1;i<n;i++)
        {
            if(nums[i] == nums[i-1])
            {
                count++;
                if(count > (n/3))
                {
                    ans.push_back(nums[i]);
                    count = 1;
                    
                    while(nums[i] == nums[i-1] && i<n)
                    {
                        i++;
                    }
                }
            }
            else{
                count = 1;
            }
            
        }
        
         if(ans.size() == 0) return {-1};
         
         return ans;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        Solution ob;
        vector<int> ans = ob.findMajority(nums);
        for (auto &i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends
