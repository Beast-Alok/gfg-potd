//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Complete this function
    // Function to sort the array according to frequency of elements.
    vector<int> sortByFreq(vector<int>& arr) {
        vector<pair<int,int>> p;
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int cnt = 1;
    
        for(int i = 1; i < n; i++) {
            if(arr[i-1] != arr[i]) {
                p.push_back({cnt, arr[i-1]});
                cnt = 0;
            }
            cnt++;
        }
    
        p.push_back({cnt, arr[n-1]});
        sort(p.begin(), p.end(), [](pair<int, int>& a, pair<int, int>& b) {
            if (a.first == b.first) {
                return a.second < b.second; // If frequencies are equal, sort by value in ascending order
            }
            return a.first > b.first; // Sort by frequency in descending order
        });
        
        vector<int> a;
        for(int j = 0; j < p.size(); j++) {
            int newn = p[j].first;
            int num = p[j].second;
            for(int i = 0; i < newn; i++) {
                a.push_back(num);
            }
        }
        return a;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution obj;
        vector<int> v;
        v = obj.sortByFreq(arr);
        for (int i : v)
            cout << i << " ";
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends
