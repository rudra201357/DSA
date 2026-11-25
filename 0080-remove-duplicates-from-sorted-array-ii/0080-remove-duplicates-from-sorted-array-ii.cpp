class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0;
        int k=0;
        for(i;i<nums.size();i++){
           if(k<2 || nums[i] != nums[k-2]){
            nums[k++] = nums[i];
            
           }
        }
        return k;
    }
};