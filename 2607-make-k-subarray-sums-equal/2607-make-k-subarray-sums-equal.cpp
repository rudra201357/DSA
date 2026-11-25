class Solution {
public:
    long long makeSubKSumEqual(vector<int>& arr, int k) {
        int n = arr.size();
        int g = gcd(n, k);

        long long ans = 0;

        for (int i = 0; i < g; i++) {
            vector<int> group;

            // Collect elements belonging to the same group
            for (int j = i; j < n; j += g) {
                group.push_back(arr[j]);
            }

            // Sort the group to find its median
            sort(group.begin(), group.end());

            int median = group[group.size() / 2];

            // Calculate minimum operations
            for (int x : group) {
                ans += abs(x - median);
            }
        }

        return ans;
    }
};