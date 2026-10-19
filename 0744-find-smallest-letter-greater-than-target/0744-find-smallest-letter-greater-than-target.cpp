class Solution {
public:
    char nextGreatestLetter(vector<char>& l, char t) {
        for(char ch : l){
            if(ch > t){
                return ch;
            }
        }
        return l[0];
    }
};