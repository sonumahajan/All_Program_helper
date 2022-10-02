class Solution {
public:
    int prevElement(vector<int>& nums){
        int n=nums.size();
        int start=0;
        int end=n-1;
        if(nums[0]<nums[n-1])
            return nums[0];
        while(start<=end){
            int mid=start+(end-start)/2;
            int next=(mid+1)%n;
            int prev=(mid+n-1)%n;
            if(nums[mid]<=nums[next] && nums[mid]<=nums[prev])
                return mid;
            if(nums[0]<=nums[mid])
                start=mid+1;
            else if(nums[n-1]>=nums[mid])
                end=mid-1;
        }
        return -1;
    }
    int bSearch(vector<int>& nums, int start, int end, int target){
        while(start<=end){
            int mid=start+(end-start)/2;
            if(target == nums[mid])
                return mid;
            else if(target < nums[mid])
                end=mid-1;
            else
                start=mid+1;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int index = prevElement(nums);
        int first = bSearch(nums, 0, index-1, target);
        int second =bSearch(nums, index, nums.size()-1, target);
        if(first>=0 && second==-1)
            return first;
        else if(first == -1 && second>=0)
            return second;
        else
            return -1;
    }
};
