class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0, left = 0;
        for (int num : nums) sum += num;

        for (int i = 0; i < nums.size(); i++) {
            if (left == sum - left - nums[i])
                return i;
            left += nums[i];
        }

        return -1;
    }
};
