class Solution {
public:
    int minDeletions(vector<int>& nums) {
        int count = 0;

        for(int i=1;i<nums.size();i++){
            if((nums[i-1] ^ nums[i]) == 0){
                count++;
            }
            
        }
        return count;
    }
};