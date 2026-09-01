class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        map = {}
        for item_s in s:
            map[item_s] = map.get(item_s, 0) + 1

        for item_t in t:
            if item_t not in map: return False
            map[item_t] -= 1
            if map[item_t] == 0: map.pop(item_t)

        if len(map) > 0: return False
        else: return True
        