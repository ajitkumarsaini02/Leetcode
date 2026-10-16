class Solution {
public:
    int reverse(int x) {
        int temp=x;
        long rev=0;
        while(temp!=0){
            int digit=temp%10;
            rev=(rev*10)+digit;
            temp/=10;
            if(rev>INT_MAX || rev<INT_MIN)
                return 0;
        }
        return int(rev);
    }
};