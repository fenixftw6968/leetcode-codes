class Solution {
public:
    int shortestSequence(vector<int>& rolls, int k) {
        vector<bool> seen(k + 1, false);

        int distinct = 0;
        int ans = 1;

        for (int r = rolls.size() - 1; r >= 0; r--) {

            if (!seen[rolls[r]]) {
                seen[rolls[r]] = true;
                distinct++;
            }

            if (distinct == k) {
                ans++;
                distinct = 0;
                fill(seen.begin(), seen.end(), false);
            }
        }

        return ans;
    }
};