class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& c, int e) {
        vector<bool> ans;
        int max=*max_element(c.begin(),c.end());
        int n= c.size();
        for(int i=0;i<n;i++){
            if((c[i]+e)>=max){
                ans.push_back(true);
            }
            else{
                ans.push_back(false);
            }
        }
        return ans;
    }
};