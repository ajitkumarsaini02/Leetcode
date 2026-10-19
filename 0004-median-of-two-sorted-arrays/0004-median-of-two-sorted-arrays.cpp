class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        int n=nums1.size();
        int m=nums2.size();
        int i=0;
        int j=0;
        while(i<n && j<m){
            if(nums1[i]<=nums2[j]){
                ans.push_back(nums1[i]);
                i++;
            }
            else{
                ans.push_back(nums2[j]);
                j++;
            }

        }
        while(i<n){
            ans.push_back(nums1[i]);
            i++;
        }
        while(j<m){
            ans.push_back(nums2[j]);
            j++;
        }
        int  sum=0;
        for(int i=0;i<ans.size();i++){
            sum +=ans[i];
        }
        int a = ans.size();
        if(a%2==1){
            return ans[a/2];
        }
        else{
            return (ans[a/2 - 1]+ans[a/2])/2.0;
        }
    }
};