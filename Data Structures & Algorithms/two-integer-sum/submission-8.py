class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        numsDict = dict()

        for i in range(len(nums)):
            if target - nums[i] in numsDict:
                return [numsDict[target - nums[i]], i]
            numsDict[nums[i]] = i
