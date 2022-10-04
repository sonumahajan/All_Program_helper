    int maximumUniqueSubarray(vector<int>& nums) {
        int size=nums.size();
        int p1=0,p2=0;
        int result=0,ans=0;
        unordered_set<int> set;
        while(p2<size){
            if(set.find(nums[p2])==set.end()){
                set.insert(nums[p2]);
                ans=ans+nums[p2++];
                result=max(result,ans);
            }
            else{
                set.erase(nums[p1]);
                ans=ans-nums[p1++];
            }
        }
        return result;
    }
