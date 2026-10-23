class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& n, int k) {
        unordered_map<int,int> w;
        for(int i = 0; i < n.size(); i++){
            if(w.count(n[i])){
                if(i-w[n[i]] <= k){
                    return true;
                }
            }
            w[n[i]] = i;
        }
        return false;
    }
};