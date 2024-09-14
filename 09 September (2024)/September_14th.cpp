//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:

    void rearrange(vector<int> &arr) {
        // code here
        vector<int> pos;
        vector<int> neg;
        int counter_pos = 0;
        int counter_neg = 0;
        
        for(auto x : arr){
            if(x < 0){
                neg.push_back(x);
            }else{
                pos.push_back(x);
            }
        }
        
        for(int i = 0; i < arr.size(); i++){
            if(i%2 == 0 and counter_pos < pos.size()){
                arr[i] = pos[counter_pos];
                counter_pos++;
            }else if(counter_neg < neg.size()){
                arr[i] = neg[counter_neg];
                counter_neg++;
            }else{
                if(counter_pos < pos.size()){
                    arr[i] = pos[counter_pos];
                    counter_pos++;
                }else{
                    arr[i] = neg[counter_neg];
                    counter_neg++;
                }
            }
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        int num;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution ob;
        ob.rearrange(arr);
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends
