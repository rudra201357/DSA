
class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        
        // Two prime moduli and bases for collision-resistant double hashing
        const long long MOD1 = 1000000007LL;
        const long long MOD2 = 1000000009LL;
        const long long BASE1 = 1315423911LL % MOD1;
        const long long BASE2 = 2654435761LL % MOD2;

        // Precompute powers of BASE1 and BASE2
        vector<long long> pow1(n + 1, 1), pow2(n + 1, 1);
        for (int i = 1; i <= n; ++i) {
            pow1[i] = (pow1[i - 1] * BASE1) % MOD1;
            pow2[i] = (pow2[i - 1] * BASE2) % MOD2;
        }

        // Helper lambda to check if a unique subarray of length `len` exists
        auto hasUnique = [&](int len) -> bool {
            long long h1 = 0, h2 = 0;
            for (int i = 0; i < len; ++i) {
                h1 = (h1 * BASE1 + nums[i]) % MOD1;
                h2 = (h2 * BASE2 + nums[i]) % MOD2;
            }

            unordered_map<uint64_t, int> freq;
            freq.reserve(n - len + 1);
            
            // Pack both 32-bit hashes into a single 64-bit integer key
            uint64_t key = (static_cast<uint64_t>(h1) << 32) | static_cast<uint64_t>(h2);
            freq[key]++;

            for (int i = len; i < n; ++i) {
                // Remove leftmost element
                h1 = (h1 - (nums[i - len] * pow1[len - 1]) % MOD1 + MOD1) % MOD1;
                h2 = (h2 - (nums[i - len] * pow2[len - 1]) % MOD2 + MOD2) % MOD2;

                // Shift and add rightmost element
                h1 = (h1 * BASE1 + nums[i]) % MOD1;
                h2 = (h2 * BASE2 + nums[i]) % MOD2;

                key = (static_cast<uint64_t>(h1) << 32) | static_cast<uint64_t>(h2);
                freq[key]++;
            }

            for (const auto& [hashKey, count] : freq) {
                if (count == 1) return true;
            }
            return false;
        };

        // Binary search on the subarray length
        int low = 1, high = n, ans = n;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (hasUnique(mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};
