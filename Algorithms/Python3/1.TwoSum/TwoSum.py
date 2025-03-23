class Solution:
    def twoSum(self, nums: list[int], target: int) -> list[int]:
        
        tempDict = {}

        for index, num in enumerate(nums):
            tempDict[num] = index
        
        for index, num in enumerate(nums):
            keyNum = target - num
            if keyNum in tempDict and index != tempDict[keyNum]:
                return [index, tempDict[keyNum]]

        return []


