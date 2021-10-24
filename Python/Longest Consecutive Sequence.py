from collections import Counter
class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        freq = Counter(nums)
        result = 0
        visited = {}
        
        def dfs(num):
            if freq[num]==0 or visited.get(num,0)==1:
                return 0
            visited[num] = 1
            return 1 + dfs(num-1) + dfs(num+1)   
        
        for num in nums:
            result  = max(result,dfs(num))
        
        return result
