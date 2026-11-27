class Solution {
public:
    string findCommonResponse(vector<vector<string>>& responses) {
        unordered_map<string, int> mp;

        for (int i = 0; i < responses.size(); i++) {
            unordered_set<string> us;

            for (int j = 0; j < responses[i].size(); j++) {
                us.insert(responses[i][j]);
            }

            for (auto str : us) {
                mp[str]++;
            }
        }

        string req_ans = "";
        int count = 0;

        for (auto str : mp) {
            if (str.second > count) {
                count = str.second;
                req_ans = str.first;
            }
            else if (str.second == count) {
                req_ans = min(req_ans, str.first);
            }
        }

        return req_ans;
    }
};