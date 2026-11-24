class Solution {
public:
    int maxPower(string s) {
        int ans = 1;
        int temp = 1;
        for(int i =0;i<s.length()-1;i++){
            if(s[i]==s[i+1]){
                temp++;
            
            }else {
                ans = max(ans,temp);
                temp =1;
            }
        }
        return max(temp,ans);
    }
};