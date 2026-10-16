class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> temp = nums;
        sort(temp.begin(), temp.end());
        unordered_map<int, int> mp;
        for(int i=0;i<nums.size();i++){
            if(mp.find(temp[i]) == mp.end()){
                mp[temp[i]] = i;
            }
        }

        for(int i=0;i<nums.size();i++){
            temp[i] = mp[nums[i]];
        }
        return temp;
    }
};