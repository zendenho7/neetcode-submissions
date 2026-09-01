class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:

        map = {}
        index = 0
        for i in nums:
            if target - i in map: 
                return [map.get(target - i, 0), index]
            else:
                map[i] = index
                index += 1

        return [0, 0]
        