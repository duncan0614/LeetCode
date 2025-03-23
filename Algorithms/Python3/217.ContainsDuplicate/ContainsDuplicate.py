class Solution:
    def hasDuplicate(self, nums: list[int]) -> bool:
        
        checkSuccess = set()

        for num in nums:
            if num in checkSuccess:
                return True
            checkSuccess.add(num)
            print(checkSuccess)
        
        return False
    
test = Solution()
test.hasDuplicate([1,2,3,4,3])
            