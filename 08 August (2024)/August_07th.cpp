//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int kthElement(int k, vector<int>& arr1, vector<int>& arr2) {
        // code here
        int i = 0, j = 0;
        int n1 =arr1.size(), n2 = arr2.size();
        int ans = -1;
        while(i < n1 && j < n2){
            if(arr1[i] < arr2[j]) ans = arr1[i++];
            else ans = arr2[j++];
            if(--k == 0) return ans;
        }
        while(i < n1){
            ans = arr1[i++];
            if(--k == 0) return ans;
        }
        while(j < n2){
            ans = arr2[j++];
            if(--k == 0) return ans;
        }
        return ans;
    }
};

//{ Driver Code Starts.

// Driver code
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, m, k;
        cin >> k;
        cin.ignore();
        string input;
        int num;
        vector<int> arr1, arr2;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr1.push_back(num);
        }

        getline(cin, input);
        stringstream s3(input);
        while (s3 >> num) {
            arr2.push_back(num);
        }

        Solution ob;
        cout << ob.kthElement(k, arr1, arr2) << endl;
    }
    return 0;
}
// } Driver Code Ends
