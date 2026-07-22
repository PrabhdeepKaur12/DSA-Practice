class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
       unordered_map<int,int>mjr;
       for(int x : nums){
          mjr[x]++;
       }
       for(auto x:mjr){
         if(x.second >n/2){
            return x.first;
         }
       }
    return -1;
    }
};