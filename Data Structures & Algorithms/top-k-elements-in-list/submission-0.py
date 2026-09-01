class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        map = defaultdict(int)
        res = []

        for num in nums:
            map[num] += 1

        sorted_map = sorted(map.items(), key=lambda x:x[1], reverse=True)

        for i in range(k):
            res.append(sorted_map[i][0])

        return res
            