class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() <= 1)
            return nums.empty() ? 0 : nums[0];
        vector<int> vec1 = nums, vec2 = nums;
        vec1.erase(vec1.begin());
        vec2.pop_back();
        return max(Rob(vec1), Rob(vec2));
    }
    
    int Rob(vector<int>& nums){
        int a = 0, b = 0;
        for(int i=0;i<nums.size();i++){
            if(i % 2 != 0){
                a += nums[i];
                a = max(a, b);
            }
            else {
                b += nums[i];
                b = max(a, b);
            }
        }
        return max(a, b);
    }
};