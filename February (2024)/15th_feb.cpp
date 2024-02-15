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
