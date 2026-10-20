class Solution {
public:
    typedef pair<double, pair<int, int>> pip;

    struct cmp {
        bool operator()(const pip& a, const pip& b) const {
            return a.first > b.first;
        }
    };

    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        priority_queue<pip, vector<pip>, cmp> pq;

        for (int i = 0; i < n - 1; i++) {
            pq.push({1.0 * arr[i] / arr[n - 1], {i, n - 1}});
        }

        pair<int, int> ans;
        while (k--) {
            auto top = pq.top();
            pq.pop();

            int i = top.second.first;
            int j = top.second.second;

            ans = {i, j};
            if (j - 1 > i) {
                pq.push({1.0 * arr[i] / arr[j - 1], {i, j - 1}});
            }
        }

        return {arr[ans.first], arr[ans.second]};
    }
};