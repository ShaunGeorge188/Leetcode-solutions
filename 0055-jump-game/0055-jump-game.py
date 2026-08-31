class Solution:
    def canJump(self, nums: List[int]) -> bool:
        fp = len(nums) - 1
        
        for p in range(len(nums) - 2, -1, -1):
            # Check if current index (p) + jump capability (nums[p]) reaches the target (fp)
            if p + nums[p] >= fp:
                fp = p 
                
        return fp == 0