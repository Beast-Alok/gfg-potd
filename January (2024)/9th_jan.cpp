#include<bits/stdc++.h>
using namespace std;

//gfg solution from here
class Solution
{
    public:
        vector <int> search(string pat, string txt)
        {
            vector<int> pos;
            for(int i = 0; i <= txt.length()-pat.length(); i++){
                if(txt[i] == pat[0]){
                    string sub = txt.substr(i,pat.length());
                    if (sub == pat){
                        pos.push_back(i+1);
                    }
                }
            }
            if (pos.size() == 0){
                pos.push_back(-1);
            }
            return pos;
        }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        if (res.size()==0)
            cout<<-1<<endl;
        else {
            for (int i : res) cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}

//code written by alok kumar raghuwanshi