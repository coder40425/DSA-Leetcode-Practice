class Solution {
public:
  
  int maxsum=INT_MIN;
  int sum=0;
    int maxSubArray(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
                sum=sum+nums[i];
                maxsum=max(sum,maxsum);

                if(sum<0){
                    sum=0;
                }   
        }
        return maxsum;
    }
};
