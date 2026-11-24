class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 1;

        for (int i = 0; i < n; i++) {
            long long product = 1;
            long long gcdVal = 0;
            long long lcmVal = 1;

            for (int j = i; j < n; j++) {
                long long x = nums[j];

                product *= x;

                gcdVal = gcd(gcdVal, x);

                lcmVal = lcmVal / gcd(lcmVal, x) * x;

                if (product == gcdVal * lcmVal) {
                    ans = max(ans, j - i + 1);
                }

                // Product can never become equal again
                if (product > gcdVal * lcmVal) {
                    break;
                }
            }
        }

        return ans;
    }
};