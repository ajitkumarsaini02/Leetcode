class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int n=nums1.size();
        int m=nums2.size();
        int i=0;
        int j=0;
        vector<int>v;
        int last=INT_MIN;
        while(i<n && j<m){
            if(nums1[i]<nums2[j]){
                i++;
            }
            else if(nums1[i]>nums2[j]){
                j++;
            }
            else{
                if(nums1[i]!=last)
                    v.push_back(nums1[i]);
                    last=nums1[i];
                i++;
                j++;
            }
        }
        return v;
    }
};