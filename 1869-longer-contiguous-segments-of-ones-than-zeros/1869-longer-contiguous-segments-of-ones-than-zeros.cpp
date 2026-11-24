class Solution {
public:
    bool checkZeroOnes(string s) {
        int ones_sub = 0;
        int ones_temp = 0;
        int zeros_temp = 0;
        int zeros_sub = 0;

        for (int i = 0; i < s.length(); i++) {

            if (s[i] == '1') {
                ones_temp++;
                zeros_temp = 0;
            } 
            else {
                zeros_temp++;
                ones_temp = 0;
            }

            ones_sub = max(ones_sub, ones_temp);
            zeros_sub = max(zeros_sub, zeros_temp);
        }

        return ones_sub > zeros_sub;
    }
};