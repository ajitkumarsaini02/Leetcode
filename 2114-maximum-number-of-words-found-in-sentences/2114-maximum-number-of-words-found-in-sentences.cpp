class Solution {
public:
    int mostWordsFound(vector<string>& s) {
        vector<int>a;
        for(int i=0;i<s.size();i++){
            int count=0;
           for(char c:s[i]){
            if(c==' '){
                count++;
            }
           }
           a.push_back(count+1);
        }
        int b=0;
        for(int i=0;i<a.size();i++){
            b=max(b,a[i]);
        }
        return b;
    }
};