
class Solution {
public:
    using ll = long long;
    ll minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        ll common = min(need1, need2);
        ll ans = common * min(costBoth, cost1 + cost2);

        need1 -= common;
        need2 -= common;

        ans += 1LL * need1 * min(cost1, costBoth);
        ans += 1LL * need2 * min(cost2, costBoth);

        return ans;
    }
};
