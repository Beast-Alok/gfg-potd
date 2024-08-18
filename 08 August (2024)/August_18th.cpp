//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool canSplit(vector<int>& arr) {
        int right_sum = 0, left_sum = 0;
        int left = -1, right = arr.size();
        
        while(left < right){
            // cout<<left_sum<<"  "<<left<<"  "<<right_sum<<"  "<<right<<endl;
            if(left_sum == right_sum and left == right-1){
                return true;
            }else if(left_sum < right_sum){
                left++;
                left_sum += arr[left];
            }else{
                right--;
                right_sum += arr[right];
            }
        }
        
        return false;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t-- > 0) {
        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> arr;
        string temp;
        while (ss >> temp) {
            arr.push_back(stoi(temp));
        }

        Solution obj;
        bool res = obj.canSplit(arr);
        cout << (res ? "true" : "false") << endl;
    }
    return 0;
}
// } Driver Code Ends
