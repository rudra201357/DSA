class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int i = 0;
        int k=0;
        int j = 0;
        while(i<nums.size()-1){
            if(nums[i]==nums[i+1]){
                nums[i] *=2;
                nums[i+1]=0;
            }
            
            i++;
        }
        while(j<nums.size()){
            if(nums[k]==0 && nums[j]!=0){
                swap(nums[k],nums[j]);
            }
            if(nums[k]!=0) k++;
            j++;
        }
        return nums;
    }
};