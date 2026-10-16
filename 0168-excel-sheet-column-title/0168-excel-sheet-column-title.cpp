class Solution {
public:
    string convertToTitle(int columnNumber) {
        string result="";
        while(columnNumber>0){
            columnNumber--;
            char temp='A'+(columnNumber%26);
            result=temp+result;
            columnNumber/=26;
        }
        return result;
    }
};