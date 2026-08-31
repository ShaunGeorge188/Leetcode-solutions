class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        agas = sum(gas)
        rgas = sum(cost)
        if(agas < rgas):
            return -1
        s = 0
        tank = 0
        for i in range(len(gas)):
            tank = tank + gas[i] - cost[i]
            if(tank < 0):
                tank = 0
                s = i + 1
        return s