class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> ans;
         sort(nums.begin(),nums.end());
        int currentsum=nums[0];
        int expectedsum=0;
        int n=nums.size();
        
        for(int i=1;i<n;i++){
           if(nums[i-1]!=nums[i]){
            currentsum+=nums[i];
           }
           else{
            ans.push_back(nums[i]);
           }
        }
        expectedsum=(n*(n+1))/2;
        ans.push_back(expectedsum-currentsum);
        return ans;
    }
};