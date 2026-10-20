class Solution {
public:
    int hIndex(vector<int>& c) {
        int n = c.size();
        sort(c.begin(), c.end());

        for(int i = 0; i < n; i++){
            int h = n - i;

            if(c[i] >= h)
                return h;
        }

        return 0;
    }
};