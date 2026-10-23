class Solution {
public:
    string toLowerCase(string s) {
        string ans = "";
        int n = s.size();
        for(int i=0;i<n;i++){
            if (isalpha(s[i]))
               ans += tolower(s[i]);
            else {
                ans +=s[i];
               }
        }
        return ans;
    }
};