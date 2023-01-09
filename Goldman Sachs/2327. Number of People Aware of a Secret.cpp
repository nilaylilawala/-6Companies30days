class Solution {
public:
    const int N = 1e9+7;
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<int> dp(n, 0);
        dp[0] = 1;
        for (int i = 1; i < n; ++i) {
            int newlyAdded = i >= delay ? dp[i - delay] : 0;
            if (i >= forget) {
                newlyAdded += N - dp[i - forget];
                newlyAdded %= N;
            }
            dp[i] = (dp[i - 1] + newlyAdded) % N;
        }
        int ret = dp.back();
        if (n > forget) {
            ret += N - dp[n - 1 - forget];
            ret %= N;
        }
        return ret;
    }
};
