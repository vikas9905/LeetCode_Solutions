#https://leetcode.com/problems/number-of-recent-calls/

import bisect
class RecentCounter:

    def __init__(self):
        self.l=[]

    def ping(self, t: int) -> int:
        self.l.append(t)
        lf=t-3000
        rt=t
        ind=bisect.bisect_left(self.l,lf)
        ind2=bisect.bisect(self.l,rt)
        if ind2>=len(self.l):
            ind2=0
        else:
            ind2=len(self.l)-ind2
        #print(ind,ind2)
        return len(self.l)-(ind+ind2)
        


# Your RecentCounter object will be instantiated and called as such:
# obj = RecentCounter()
# param_1 = obj.ping(t)