# 图像渲染
## 题目
An image is represented by a 2-D array of integers, each integer representing the pixel value of the image (from 0 to 65535).

Given a coordinate (sr, sc) representing the starting pixel (row and column) of the flood fill, and a pixel value newColor, "flood fill" the image.

To perform a "flood fill", consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color as the starting pixel), and so on. Replace the color of all of the aforementioned pixels with the newColor.

At the end, return the modified image.

Example 1:
Input: 
image = [[1,1,1],[1,1,0],[1,0,1]]
sr = 1, sc = 1, newColor = 2
Output: [[2,2,2],[2,2,0],[2,0,1]]
Explanation: 
From the center of the image (with position (sr, sc) = (1, 1)), all pixels connected 
by a path of the same color as the starting pixel are colored with the new color.
Note the bottom corner is not colored 2, because it is not 4-directionally connected
to the starting pixel.
Note:

The length of image and image[0] will be in the range [1, 50].
The given starting pixel will satisfy 0 <= sr < image.length and 0 <= sc < image[0].length.
The value of each color in image[i][j] and newColor will be an integer in [0, 65535].

## 题解
### 算法分析
1. 定义oldColor=iamge[sr][sc]，如果oldColor==newColor直接返回image
2. 否则使用深度优先搜索，定义递归函数用于递归遍历节点<r,c>
3. 如果image[r][c] != oldColor则返回
4. 否则image[r][c] = newColor，递归调用<r,c>的四周节点
### 复杂度分析
+ 时间复杂度：O(n), n=r*c，最坏情况遍历二维数组所有的节点
+ 空间复杂度：O(n)，递归调用栈使用的空间
### 源码
```C++ []
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