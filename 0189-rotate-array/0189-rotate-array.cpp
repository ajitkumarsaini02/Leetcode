void Reverse(int i,int j,vector<int>&a){
    while(i<=j){
        int temp=a[i];
        a[i]=a[j];
        a[j]=temp;
        i++;
        j--;
    }
    return;
}

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k=k%n;
        Reverse(0,n-k-1,nums);
        Reverse(n-k,n-1,nums);
        Reverse(0,n-1,nums);
        for(int i=0;i<nums.size();i++){
            cout<<nums[i];
        }    
    }
};