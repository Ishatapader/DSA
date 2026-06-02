class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int startingRow = 0;
        int startingCol = 0;
        int endingRow = n - 1;
        int endingCol = n - 1;
        int value = 1;
        vector<int> row(n, 0);
        vector<vector<int>> Matrix(n, row);
        while (startingRow <= endingRow && startingCol <= endingCol) {
            for (int col = startingCol; col <= endingCol; col++) {
                Matrix[startingRow][col] = value++;
            }
            for (int row = startingRow + 1; row <= endingRow; row++) {
                Matrix[row][endingCol] = value++;
            }
            for (int col = endingCol - 1; col >= startingCol; col--) {
                Matrix[endingRow][col] = value++;
            }

            for (int row = endingRow - 1; row > startingRow; row--) {
                Matrix[row][startingCol] = value++;
            }
            startingCol++;
            startingRow++;
            endingCol--;
            endingRow--;
        }
        return Matrix;
    }
};