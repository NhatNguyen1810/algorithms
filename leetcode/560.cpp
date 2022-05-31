//https://leetcode.com/problems/subarray-sum-equals-k/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        if(nums.size() == 0){
            return 0; 
        }
        int n = nums.size(); 
        int total = 0; 
        map<int,int> m; 
        vector<int> prefix_sum(n, 0); 
        for(int i = 0; i < n; i++){
            prefix_sum[i] = i == 0 ? nums[i] : prefix_sum[i-1] + nums[i]; 
            if(prefix_sum[i] == k){
                total++; 
            }
            if(m.find(prefix_sum[i] - k) != m.end()){
                total += m[prefix_sum[i] - k]; 
            }
            m[prefix_sum[i]]++; 
        }
        return total; 
    }
};