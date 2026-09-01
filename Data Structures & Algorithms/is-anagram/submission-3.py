class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t): return False

        map = {}

        for char_s in s:
            map[char_s] = map.get(char_s, 0) + 1
        
        for char_t in t:
            if map.get(char_t, 0) == 0: return False

            map[char_t] -= 1

            if map[char_t] == 0: map.pop(char_t)

        if len(map) > 0: return False
        else: return True
        