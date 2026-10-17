class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int>ans;
        int n = nums.size();
        int mx = *max_element(nums.begin(), nums.end());
        int mn = *min_element(nums.begin(), nums.end());
        vector<int> freq(mx-mn+1,0);
        for(int i=0;i<n;i++){
            freq[nums[i]-mn]++;
        }
        int a = n/3;
        for(int i=0;i<freq.size();i++){
            if(freq[i] > a){
                ans.push_back(i+mn);
            }
        }
        return ans;
    }
};