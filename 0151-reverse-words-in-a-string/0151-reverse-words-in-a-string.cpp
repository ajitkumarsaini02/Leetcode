class Solution {
public:
    vector<string> split(string s){
        vector<string> words;
        string temp = "";
        for(char c : s){
            if(c == ' '){
                if(!temp.empty()){
                    words.push_back(temp);
                    temp = "";
                }
            }
            else{
                temp += c;
            }
        }
        if (!temp.empty()) words.push_back(temp);
        return words;
    }

    string reverseWords(string s) {
        vector<string> words = split(s);
        if(words.empty()) return "";
        string ans;
        
        for(int i=words.size()-1;i>=0;i--){
            if(!ans.empty()){
                ans += " ";
            }
            ans += words[i];
            
        }
        return ans;
    }
};