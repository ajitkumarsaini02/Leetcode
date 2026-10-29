class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(int x : nums){
            mp[x]++;
        }
        for(int i=1;i<=nums.size();i++){
            if(mp.count(i) == 0){
                return i;
            }
        }
        return nums.size()+1;
    }
};