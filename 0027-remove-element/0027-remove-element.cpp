class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
   
        int i=0;
        int j=0;
        while(j<nums.size()){
            if(nums[i]==val && nums[j]!=val){
                swap(nums[i],nums[j]);
            }
            if(nums[i]!=val) i++;
            j++;
        }
        return i;
    }
};