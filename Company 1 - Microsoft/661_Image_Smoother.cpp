#include <vector>
using namespace std;
// C++
class Solution
{
public:
    vector<vector<int>> imageSmoother(vector<vector<int>> &img)
    {
        int m = img.size();
        int n = img[0].size();

        vector<vector<int>> iimg(m, vector<int>(n));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {

                int sum = 0, count = 0;

                for (int x = i - 1; x <= i + 1; x++)
                {
                    for (int y = j - 1; y <= j + 1; y++)
                    {

                        if (x >= 0 && x < m && y >= 0 && y < n)
                        {
                            sum += img[x][y];
                            count += 1;
                        }
                    }
                }

                int avg = sum / count;
                iimg[i][j] = avg;
            }
        }

        return iimg;
    }
};

// Python
/*
class Solution:
    def imageSmoother(self, img: List[List[int]]) -> List[List[int]]:
        m = len(img)
        n = len(img[0])

        iimg = [[0] * n for _ in range(m)]

        for i in range(m):
            for j in range(n):
                sum, count = 0, 0

                for x in (i-1, i, i+1):
                    for y in (j-1, j, j+1):
                        if 0 <= x < m and 0 <= y < n:
                            sum += img[x][y]
                            count += 1

                iimg[i][j] = sum // count

        return iimg
*/
