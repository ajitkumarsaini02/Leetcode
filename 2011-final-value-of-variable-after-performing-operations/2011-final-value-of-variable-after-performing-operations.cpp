class Solution {
public:
    int finalValueAfterOperations(vector<string>& o) {
        int d=0;
        for(int i=0;i<o.size();i++){
            if(o[i]=="--X") --d;
            else if(o[i]=="X--") d--;
            else if(o[i]=="++X") ++d;
            else if(o[i]=="X++")  d++;
        }
        return d;
    }
};