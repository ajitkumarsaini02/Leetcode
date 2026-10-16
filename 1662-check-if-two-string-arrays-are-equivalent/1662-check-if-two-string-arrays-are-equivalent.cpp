class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string first = "";
        string second = "";
        for(auto s : word1){
            first += s;
        }
        for(auto s : word2){
            second += s;
        }
        return first == second;
    }
};