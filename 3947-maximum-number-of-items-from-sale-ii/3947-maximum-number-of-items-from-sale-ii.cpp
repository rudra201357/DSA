class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
          int n = items.size();
        
        // Step 1: Find the cheapest item price and the maximum factor
        long long cheapest = LLONG_MAX;
        int max_factor = 0;
        for (const auto& item : items) {
            max_factor = max(max_factor, item[0]);
            cheapest = min(cheapest, (long long)item[1]);
        }
        
        // Step 2: Count frequency of each factor and accumulate multiples (Sieve approach)
        vector<long long> freq(max_factor + 1, 0);
        for (const auto& item : items) {
            freq[item[0]]++;
        }
        
        for (int i = 1; i <= max_factor; ++i) {
            if (freq[i] > 0) {
                for (int multiple = 2 * i; multiple <= max_factor; multiple += i) {
                    freq[i] += freq[multiple];
                }
            }
        }
        
        // Step 3: Collect valid 2-for-1 deals that cost at most 2 * cheapest
        map<long long, long long> cost_count;
        for (const auto& item : items) {
            long long factor = item[0];
            long long price = item[1];
            // Subtract 1 because an item cannot give a free copy of itself
            long long free_opportunities = freq[factor] - 1; 
            
            if (free_opportunities > 0 && price <= 2 * cheapest) {
                cost_count[price] += free_opportunities;
            }
        }
        
        // Step 4: Greedily buy the cheapest 2-for-1 deals first
        long long total_items = 0;
        long long rem_budget = budget;
        
        for (const auto& [price, count] : cost_count) {
            long long can_buy = min(count, rem_budget / price);
            total_items += 2 * can_buy; // 1 purchased + 1 free
            rem_budget -= can_buy * price;
            
            if (rem_budget < price) break;
        }
        
        // Step 5: Spend any remaining budget on the single cheapest item (1-for-1)
        total_items += rem_budget / cheapest;
        
        return (int)total_items;
    }
};