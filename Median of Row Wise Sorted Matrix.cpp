// Problem Statement: Given a row-wise sorted matrix of size r*c, where r is no. of rows and c is no. of columns, find the median in the given matrix.

// Example 1:
// Input: 
// r = 3 , c = 3
// 1 4 9 
// 2 5 6
// 3 8 7
// Output: Median = 5
// Explanation: If we find the linear sorted array, the array becomes 1 2 3 4 5 6 7 8 9
// So, median = 5

// Example 2:
// Input: 
// r = 3 , c = 3
// 1 3 8
// 2 3 4
// 1 2 5
// Output: Median = 3
// Explanation: If we find the linear sorted array, the array becomes 1 1 2 2 3 3 4 5 7 8
// So, median = 3

#include <bits/stdc++.h>
using namespace std;
// Function to find median  of row wise sorted matrix
int Findmedian(int arr[3][3], int row, int col)
{
  int median[row * col];
  int index = 0;
  for (int i = 0; i < row; i++)
  {
    for (int j = 0; j < col; j++)
    {
      median[index] = arr[i][j];
      index++;
    }
  }
 
  return median[(row * col) / 2];
}
int main()
{
  int row = 3, col = 3;
  int arr[3][3] = {{1, 3, 8},
                   {2, 3, 4},
                   {1, 2, 5}};
  cout <<"The median of the row-wise sorted matrix is: "<<Findmedian
  (arr, row, col) << endl;
  return 0;
}
