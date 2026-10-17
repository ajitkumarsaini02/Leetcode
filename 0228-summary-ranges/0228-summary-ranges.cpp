class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        if(nums.size()==0) return ans;
        int start =nums[0];
        for(int i=0;i<nums.size();i++){
            if(i==nums.size()-1 || (nums[i]+1)!=nums[i+1]){
                if(start == nums[i]){
                ans.push_back(to_string(start));
                }
                else{
                    ans.push_back(to_string(start) + "->" + to_string(nums[i]));
                }
                if(i+1<nums.size()){
                    start = nums[i+1];
                }
            }
            
        }
        return ans;
    }
};