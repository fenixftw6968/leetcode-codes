const int N = 10001;
const int mod = 1e9 + 7;

int dp[21][N];
int lengths[N][21];

class Solution {
    void CalculateUniquePathLengths() {
        memset(lengths, 0, sizeof(lengths));

        for (int j = 1; j < N; j++) {
            // contribute 'j' to its every multiples
            lengths[j][1] = 1;

            for (int k = j + j; k < N; k += j) {
                for (int i = 0; i < 20; i++) {
                    lengths[k][i + 1] += lengths[j][i];
                }
            }
        }
    }

    int UniqueArrangements(int length, int mx) {
        if (length == 0) return (mx == 0);
        if (mx == 0) return 0;

        int &ans = dp[mx][length];

        if (ans != -1) return ans;

        ans = (UniqueArrangements(length - 1, mx) +
               UniqueArrangements(length - 1, mx - 1)) % mod;

        return ans;
    }

public:
    int idealArrays(int n, int maxValue) {
        memset(dp, -1, sizeof(dp));

        CalculateUniquePathLengths();

        int ans = 0;

        for (int last = maxValue; last >= 1; last--) {
            for (int j = 1; j < 21; j++) {
                long long arrangementsWithEverything = UniqueArrangements(n, j);

                ans = (ans +
                       (arrangementsWithEverything * lengths[last][j]) % mod) % mod;
            }
        }

        return ans;
    }
};