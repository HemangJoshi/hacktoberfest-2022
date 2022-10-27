// Problem Statement: “Given a text and a pattern, write a program to print the occurrences of pattern in the text”

// Examples:

// Example 1:
// Input: text[] = "BAABABAABBBABAA"
// pat[] = "ABAA"
// Output: Pattern found at index 0
// Pattern found at index 9
// Pattern found at index 12
// Explanation: Give a very clear understanding to the reader between the correlation of Input and Output relating to the problem statement.

// Example 2:
// Input: txt[] = "AABAACAADAABAABA"
// pat[] = "AABA"
// Output:Pattern found at index 0
// Pattern found at index 9
// Pattern found at index 12

#include <bits/stdc++.h>

using namespace std;

void search(char text[], char pat[]) {
  int N = strlen(text);
  int M = strlen(pat);

  // Check for each element in text
  for (int i = 0; i < N; i++) {
    int j;

    // Check whether all elements of pat are present in text, break if not found
    for (j = 0; j < M; j++)
      if (text[i + j] != pat[j])
        break;

    if (j == M) // When all element of pat are found, print ith index
      cout << "Pattern found at index " <<
      i << endl;
  }
}

// Driver Code
int main() {
  char text[] = "AABAACAADAABAAABAA";
  char pat[] = "AABA";
  search(text, pat);
  return 0;
}
