class Solution {
public:
    using pi = pair<int, int>;
    using ppi = pair<long long, pair<int, int>>;

    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size();
        int m = tasks.size();

        priority_queue<pi, vector<pi>, greater<pi>> free;
        priority_queue<ppi, vector<ppi>, greater<ppi>> busy;

        for (int i = 0; i < n; i++) {
            free.push({servers[i], i});
        }

        long long currTime = 0;
        vector<int> ans(m);

        for (int j = 0; j < m; j++) {
            currTime = max(currTime, (long long)j);

            if (free.empty()) {
                currTime = busy.top().first;
            }

            while (!busy.empty() && busy.top().first <= currTime) {
                auto server = busy.top();
                busy.pop();
                free.push(server.second);
            }

            auto best = free.top();
            free.pop();
            ans[j] = best.second;

            busy.push({currTime + tasks[j], best});
        }

        return ans;
    }
};