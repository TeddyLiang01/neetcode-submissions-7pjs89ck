class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
        letterDiction = dict()

        for let in s:
            if let in letterDiction:
                letterDiction[let] += 1
            else:
                letterDiction[let] = 1
        
        for let in t:
            if let in letterDiction:
                letterDiction[let] -= 1
            else:
                letterDiction[let] = -1

        for item in letterDiction.items():
            if item[1] != 0:
                return False
        
        return True

        