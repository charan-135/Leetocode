class Solution {
public:
    int thirdMax(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        int count = 1;
        int n = nums.size();
        
        for(int i=n-1; i > 0; i--){
            if(nums[i] != nums[i-1]){
                count++;

                if (count == 3) {
                    return nums[i-1];
                }
            }
        }
        return nums[n-1]; 
    }
};