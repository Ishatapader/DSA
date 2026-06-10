class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas = 0;
        int currGas = 0;
        int startingIndex = 0;
        for (int i = 0; i < gas.size(); i++) {
            currGas += gas[i] - cost[i];
            totalGas += gas[i] - cost[i];
            if (currGas < 0) {
                startingIndex = i + 1;
                currGas = 0;
            }
        }
        return totalGas >= 0 ? startingIndex : -1;
    }
};