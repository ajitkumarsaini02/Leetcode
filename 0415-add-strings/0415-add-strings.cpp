class Solution {
public:
    string addStrings(string num1, string num2) {
        int i=num1.size()-1;
        int j=num2.size()-1;
        int carry=0;
        string ans="";
        while(i>=0 || j>=0 || carry){
            int x=0;
            int y=0;
            if(i>=0) x=num1[i]-'0';
            if(j>=0) y=num2[j]-'0';
            int sum=x+y+carry;
            ans+=(sum%10)+'0';
            carry=sum/10;
            i--;
            j--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};