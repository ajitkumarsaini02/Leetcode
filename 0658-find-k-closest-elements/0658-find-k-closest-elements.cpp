class Solution {
public:
    typedef pair<int, int> pi;
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        priority_queue<pi> q;
        vector<int> ans;

        for (int i = 0; i < n; i++) {

            q.push({abs(x - arr[i]), arr[i]});
            if (q.size() > k) {
                q.pop();
            }
        }
        while (!q.empty()) {
            ans.push_back(q.top().second);
            q.pop();
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};