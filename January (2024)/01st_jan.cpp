#include <bits/stdc++.h>
using namespace std;

// GFG solution from here
class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        map <int, int> f;
        for(int i = 0; i<nums.size(); i++){
            int current_value = nums[i] % k;
            int needed_value = (k - current_value) % k;
            
            if(f.count(needed_value)){
                --f[needed_value];
                
                if(f[needed_value] == 0){
                    f.erase(needed_value);
                }
                
            }else{
                ++f[current_value];
            }
        }
        return f.size() == 0;
    }
};

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}

//code written by alok kumar raghuwanshi
