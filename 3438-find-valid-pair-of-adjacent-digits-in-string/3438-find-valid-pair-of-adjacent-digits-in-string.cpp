class Solution {
public:
    string findValidPair(string s) {
        unordered_map<char,int>mp;
        for(char c:s){
            mp[c]++;
        }
        for(int i=0;i<s.length()-1;i++){
            if(s[i]==s[i+1]) continue;
            if(mp[s[i]]==s[i]-'0' and mp[s[i+1]]==s[i+1]-'0' ) return s.substr(i,2);
        }
        return "";
    }
};