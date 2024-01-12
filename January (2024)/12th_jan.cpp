#include <bits/stdc++.h>
using namespace std;

// gfg solution from here
class Solution
{
    public:
    queue<int> modifyQueue(queue<int> q, int k) {
        stack <int> S;
        int n = q.size();
        for(int i = 0; i < k; i++){
            S.push(q.front());
            q.pop();
        }
        while(!S.empty()){
            q.push(S.top());
            S.pop();
        }
        for(int i =0 ; i < n-k; i++){
            S.push(q.front());
            q.pop();
            q.push(S.top());
            S.pop();
        }
        return q;
    }
};

int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n, k;
        cin >> n >> k;
        queue<int> q;
        while (n-- > 0) {
            int a;
            cin >> a;
            q.push(a);
        }
        Solution ob;
        queue<int> ans = ob.modifyQueue(q, k);
        while (!ans.empty()) {
            int a = ans.front();
            ans.pop();
            cout << a << " ";
        }
        cout << endl;
    }
}

// code written by alok kumar raghuwanshi