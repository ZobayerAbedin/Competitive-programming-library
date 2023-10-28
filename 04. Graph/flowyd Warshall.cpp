int dis[N][N];
int dp[N][N];

void floydWarshall() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) dp[i][j] = dis[i][j];
    }
    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (dp[i][k] + dp[k][j] < dp[i][j]) {
                    if (i != j) dp[i][j] = dp[i][k] + dp[k][j];
                }
            }
        }
    }

}