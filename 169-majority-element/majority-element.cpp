class Solution {
public:
    int majorityElement(vector<int>& nums) {

        unordered_map<int,int> mp;
        for(int num : nums){
            mp[num]++;
        }
        int maxc=0;
        int mj;
        for (const auto& [number, count] : mp) {
            if(count>maxc){
                mj=number;
                maxc=count;
            }
    }
    return mj;

        
    }
};