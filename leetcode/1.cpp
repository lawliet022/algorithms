class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        int a[n];
        for(int i = 0; i < n; i++)
            a[i] = i;
        sort(a,a+n,[&](int i, int j){
           return nums[i] < nums[j]; 
        });
        vector<int> ans;
        int l = 0, r = n-1;
            
        while(l < r){
            if(nums[a[l]] + nums[a[r]] == target){
                ans = {a[l],a[r]};
                break;
            }
            else if(nums[a[l]] + nums[a[r]] > target){
                r--;
            }
            else
                l++;
        }
        return ans;
    }
};
