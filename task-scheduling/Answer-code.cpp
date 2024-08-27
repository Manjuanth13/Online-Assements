int f(int i, int left, int n, vector<int> &cost, vector<int> &time, vector<vector<int>> &dp) {
        if(left <= 0) return 0;
        if(i < 0) return 1e9;
        if(dp[i][left] != -1) return dp[i][left];
        
        int notpick = f(i - 1, left, n, cost, time, dp);
        int pick = cost[i] + f(i - 1, left - time[i] - 1, n, cost, time, dp);
        
        return dp[i][left] = min(pick, notpick);
    }

int getMinCost(vector<int>& cost, vector<int>& time) {
    int n = cost.size();
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    return f(n-1, n, n, cost, time, dp);
}
