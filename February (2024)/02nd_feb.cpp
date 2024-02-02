#include <bits/stdc++.h>
using namespace std;
// gfg solution from here
class Solution{
  public:
    int atoi(string s) {
        int result = 0;
        int sign = 1;

        if (s[0] == '-') {
            sign = -1;
            s = s.substr(1);
        }

        for (char c : s) {
            if (!isdigit(c))
                return -1;

            result = result * 10 + (c - '0');
        }
        return result * sign;
    }
};
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}
// code written by alok kumar raghuwanshi