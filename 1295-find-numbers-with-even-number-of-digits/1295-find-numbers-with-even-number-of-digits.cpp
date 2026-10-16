class Solution {
public:
    bool digit(int n){
        int count = 0;
        while(n > 0){
            int r = n % 10;
            count++;
            n /= 10;
        }
        if(count % 2 != 0) return false; 
        return true;
    }
    int findNumbers(vector<int>& nums) {
        int count = 0;
        for(int i=0;i<nums.size();i++){
            if(digit(nums[i])) count++;
        }
        return count;
    }
};