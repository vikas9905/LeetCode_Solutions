#https://leetcode.com/problems/car-pooling/

class Solution:
    def carPooling(self, l: List[List[int]], cap: int) -> bool:
        arr=[]
        for i in l:
            arr.append([i[0],i[1],'a'])
            arr.append([i[0],i[2],'d'])
        arr.sort(key=lambda it:it[1])
        capacity=0
        for i in arr:

            if i[2]=='a' and cap>=capacity:
                capacity+=i[0]
            elif i[2]=='a' and capacity>cap:
                print(capacity)
                return 0
            if i[2]=='d':
                capacity-=i[0]

            if capacity>cap:
                return 0
        if capacity>=0:
            return 1
