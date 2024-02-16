#include<bits/stdc++.h>
using namespace std;

// gfg solution from here
class Solution {
public:
int isPossible(vector<vector<int>> paths){
    for(auto i: paths){
        if(accumulate(i.begin(), i.end(), 0) % 2 != 0)
            return false;
    }
    return true;
}
};

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>paths(n, vector<int>(n, 0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++)
				cin >> paths[i][j];
		}
		Solution obj;
		int ans = obj.isPossible(paths);
		cout << ans <<"\n";
	}
	return 0;
}
// code written by alok kumar raghuwanshi