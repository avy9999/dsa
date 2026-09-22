class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        int row = 0;
        int col = 0;
        for (auto i : commands){
            if (i == "RIGHT") col++;
            else if (i == "UP") row--;
            else if (i == "DOWN") row++;
            else col--;
        }
        return (row * n) + col;
    }
};