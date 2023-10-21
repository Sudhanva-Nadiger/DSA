class Solution:
    def countAnagrams(self, s: str) -> int:
        res = 1
        for w in s.split(" "):
            cnt, prem = Counter(w), factorial(len(w))
            for rep in cnt.values():
                prem = prem // factorial(rep)
            res = res * prem % 1000000007
        return res
        