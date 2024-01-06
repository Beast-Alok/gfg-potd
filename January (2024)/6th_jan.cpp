#include<bits/stdc++.h>
using namespace std;

// GFG solution from here
class Solution {
public:
	int primePowers(int n)
    {
        int cnt = 0;
        for(int i = 2; i <= sqrt(n); i++)
        {
            while(n % i == 0)
            {
                cnt++;
                n = n / i;
            }
        }
        if(n > 1)
            cnt++;
        
        return cnt;
    }
    
    int sumOfPowers(int a, int b)
    {
        int cnt = 0;
        for(int i = a; i <= b; i++)
            cnt += primePowers(i);
        return cnt;
    }
};


int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int a, b;
		cin >>  a >> b;
		Solution obj;
		int ans = obj.sumOfPowers(a, b);
		cout << ans <<"\n";
	}
	return 0;
}

//code written by alok kumar raghuwanshi