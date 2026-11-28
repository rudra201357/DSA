class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>ans(n,vector<int>(n,0));
        int val=1;
        int top=0,left=0;
        int buttom= n-1;
        int right= n-1;
        while(left<=right && top<=buttom){
            for(int i = left;i<=right;i++){
                ans[top][i]=val++;
            }
            top++;
            for(int i=top;i<=buttom;i++){
                ans[i][right]=val++;
            }
            right--;
            
            if(top<=buttom){
                for(int i = right;i>=left;i--){
                    ans[buttom][i]=val++;
                }
                buttom--;
            }
            if(left<=right){
                for(int i=buttom;i>=top;i--){
                    ans[i][left]=val++;
                }
                left++;
            }
        }
        return ans;
    }
};