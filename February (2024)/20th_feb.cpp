class Solution{
public:
    int minValue(string s, int k){
        // code here
        unordered_map<char,int>mp;
        for(auto it:s){
            mp[it]++;
        }
        priority_queue<int>pq;
        for(auto it:mp){
            pq.push(it.second);
        }
        while(k--){
            
           int t= pq.top();
           pq.pop();
           t--;
           if(t) pq.push(t);
        }
        int sum=0;
        while(!pq.empty()){
            sum+=pq.top()*pq.top();
           
            pq.pop();
        }
        return sum;
    }
};
