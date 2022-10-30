// Problem Statement: Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input

// Examples:

// Example 1:

// Input: [[1,3],[2,6],[8,10],[15,18]]

// Output: [[1,6],[8,10],[15,18]]

// Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].

// Example 2:

// Input: [[1,4],[4,5]]

// Output: [[1,5]]

// Explanation: Intervals [1,4] and [4,5] are considered overlapping.


class Solution {
public:
  static bool sortInterval(const vector<int>& a, const vector<int>& b) {
    return a[0] < b[0];
  }
  
  vector<vector<int>> merge(vector<vector<int>>& intervals) {
    vector<vector<int>> res;
    vector<int> temp;

    // Sorting the intervals in ascending order of their `start`
    sort(intervals.begin(), intervals.end(), sortInterval);
    
    // Push the first interval in the resultant vector
    res.push_back(intervals[0]);
    
    // Looping through the vector to intervals and checking if the intervals overlap
    for(int i = 0; i < intervals.size(); i++) {
      temp = intervals[i];
      
      // If the intervals overlap with the last interval in the res vector,
      // we will set the `start` of that interval to the min of the current interval & the last interval in resultant vector
      
      // If the intervals don't overlap then we just append the interval in the resultant vector
      if(temp[0] <= res[res.size() - 1][1]) {
        res[res.size() - 1][0] = min(temp[0], res[res.size() - 1][0]);
        res[res.size() - 1][1] = max(temp[1], res[res.size() - 1][1]);
      } else {
        res.push_back(temp);
      }
    }
    
    return res;
  }
};