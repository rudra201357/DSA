class Solution {
public:
    int largestInteger(int num) {
        string str = to_string(num);

        for (int i = 0; i < str.length(); i++) {
            int idx = i;

            for (int j = i + 1; j < str.size(); j++) {
                if ((str[j] - '0') % 2 == (str[i] - '0') % 2) {
                    if (str[j] > str[idx]) {
                        idx = j;
                    }
                }
            }

            swap(str[i], str[idx]);
        }

        return stoi(str);
    }
};