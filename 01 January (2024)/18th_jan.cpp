#include <bits/stdc++.h>
using namespace std;

// gfg solution from here
class Solution {
public:
    int min_sprinklers(int gallery[], int n) {
        vector<pair<int, int>> cov;

        for (int i = 0; i < n; i++) {
            if (gallery[i] == -1) {
                cov.push_back({1e7, 1e7});
            } else {
                cov.push_back({i - gallery[i], i + gallery[i]});
            }
        }
        sort(cov.begin(), cov.end());
        
        int take = 0, index = 0, ans = 0;
        while(take < n){
            int nax = take - 1;
            while(index < n and cov[index].first <= take){
                nax = max(nax, cov[index++].second);
            }

            if(nax+1 > take){
                take = nax+1;
                ans++;
            }else{
                return -1;
            }
        }
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        int gallery[n];
        for (int i = 0; i < n; i++)
            cin >> gallery[i];
        Solution obj;
        cout << obj.min_sprinklers(gallery, n) << endl;
    }
    return 0;
}
// code written by alok kumar raghuwanshi