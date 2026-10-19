class Solution {
public:
    int heightChecker(vector<int>& h) {
        int count=0;
        vector<int>v;
        for(int i=0;i<h.size();i++){
           v.push_back(h[i]);
        }
        sort(v.begin(),v.end());
        for(int i=0;i<v.size();i++){
            if(v[i]!=h[i]) count++;
        }
        return count;
    }
};