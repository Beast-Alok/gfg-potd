static bool cmp(string a,string b)

    {

        if(a+b > b+a)return true;

        return false;

    }

 // The main function that returns the arrangement with the largest value as

 // string.

 // The function accepts a vector of strings

 string printLargest(int n, vector<string> &arr) {

     // code here 

     sort(arr.begin(),arr.end(),cmp);

     string ans = "";

     for(int i=0;i<arr.size();i++)

     {

         ans += (arr[i]);

     }

     return ans;

 }
