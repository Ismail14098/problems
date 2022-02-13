class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int>st;
        int i = 0,j = 0;
        for(; j<nums.size(); j++){
            if(j>k){
                st[nums[i++]]--;
            }
            if(st[nums[j]]>0){
                return true;
            }
            st[nums[j]]++;
        }
        return false;
    }
};