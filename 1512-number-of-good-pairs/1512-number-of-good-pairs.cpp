class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int sum=0;
        int n=nums.size();
        unordered_map<int, int> mp;
        for(int i=0;i<n;i++){
            sum += mp[nums[i]];
            mp[nums[i]]++;
        }

        return sum;
    }
};