#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int oldColor = image[sr][sc];
        if (oldColor != newColor)
            floodFillRecusive(image, sr, sc, oldColor, newColor);
        return image;
    }

    void floodFillRecusive(vector<vector<int>>& image, int r, int c, int oldColor, int newColor)
    {
        if (image[r][c] != oldColor)
            return;
        
        image[r][c] = newColor;

        if (r - 1 >= 0)
        {
            floodFillRecusive(image, r - 1, c, oldColor, newColor);
        }
        if (r + 1 < image.size())
        {
            floodFillRecusive(image, r + 1, c, oldColor, newColor);
        }
        if (c - 1 >= 0)
        {
            floodFillRecusive(image, r, c - 1, oldColor, newColor);
        }
        if (c + 1 < image[r].size())
        {
            floodFillRecusive(image, r, c + 1, oldColor, newColor);
        }
    }
};