class Solution {
public:
    string multiply(string num1, string num2) {
        int n = num1.size();
        int m = num2.size();
        vector<int>re(n+m,0);
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                int m = (num1[i]-'0')*(num2[j]-'0');
                int s = m + re[i+j+1];
                re[i+j+1] = s%10;
                re[i+j] += s/10;
            }
        }
        string s = "";
        for(int num : re){
            if(!(s.size()==0 && num ==0)){
                s += (num + '0');
            }
        }
        if(s.size() == 0) return "0";
        else return s;
    }
};