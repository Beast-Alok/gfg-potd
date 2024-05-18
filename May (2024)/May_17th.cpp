//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    int findPair(int n, int x, vector<int> &arr) {
        // code her
        sort(arr.begin(), arr.end());
        
        for(int i=0; i<n; i++){
            
            int temp = x + arr[i];
            arr[i] = 0;
            int s = 0, e = n-1;
            
            while(s<=e){
                int mid = s + (e-s)/2;
                if(arr[mid] == temp) return 1;
                else if(arr[mid] > temp) e = mid - 1;
                else s = mid + 1;
            }
            arr[i] = temp - x;
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        int x;
        scanf("%d", &x);

        vector<int> arr(n);
        Array::input(arr, n);

        Solution obj;
        int res = obj.findPair(n, x, arr);

        cout << res << endl;
    }
}

// } Driver Code Ends
