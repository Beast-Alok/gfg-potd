class Solution
{
    public:
    int subsequenceCount(string s, string t)
    {
      //Your code here
      int n=s.length();
      int m=t.length();
      int mod=(int)1e9+7;
      vector<int> p(m+1);
      vector<int> c(m+1);
      p[0]=1;
      for(int i=1;i<=n;i++){
          c[0]=1;
          for(int j=1;j<=m;j++){
              int np=p[j]%mod;
              int pi=0;
              if(s[i-1]==t[j-1]){
                  pi=p[j-1]%mod;
              }
                  c[j]=(np+pi)%mod;
          }
          p=c;
      }
      return p[m];
    }
};
