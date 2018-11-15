/*
1007 Maximum Subsequence Sum （25 分）
Given a sequence of K integers { N
​1
​​ , N
​2
​​ , ..., N
​K
​​  }. A continuous subsequence is defined to be { N
​i
​​ , N
​i+1
​​ , ..., N
​j
​​  } where 1≤i≤j≤K. The Maximum Subsequence is the continuous subsequence which has the largest sum of its elements. For example, given sequence { -2, 11, -4, 13, -5, -2 }, its maximum subsequence is { 11, -4, 13 } with the largest sum being 20.

Now you are supposed to find the largest sum, together with the first and the last numbers of the maximum subsequence.

Input Specification:
Each input file contains one test case. Each case occupies two lines. The first line contains a positive integer K (≤10000). The second line contains K numbers, separated by a space.

Output Specification:
For each test case, output in one line the largest sum, together with the first and the last numbers of the maximum subsequence. The numbers must be separated by one space, but there must be no extra space at the end of a line. In case that the maximum subsequence is not unique, output the one with the smallest indices i and j (as shown by the sample case). If all the K numbers are negative, then its maximum sum is defined to be 0, and you are supposed to output the first and the last numbers of the whole sequence.

Sample Input:
10
-10 1 2 3 4 -5 -23 3 7 -21
Sample Output:
10 1 4
*/
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
    std::ios::sync_with_stdio(false);
    int n;
    cin >> n;
    int array[n];
    for (int i = 0; i < n; i++)
        cin >> array[i];

    int dp[n];
    int dpi[n];
    dp[0] = array[0];
    dpi[0] = 0;
    for (int i = 1; i < n; i++) {
        if (dp[i - 1] < 0 && array[i] > dp[i - 1]) {
            dp[i] = array[i];
            dpi[i] = i;
        } else {
            dp[i] = dp[i - 1] + array[i];
            dpi[i] = dpi[i - 1];
        }
    }

    int maxnum = dp[0];
    for (int i = 0; i < n; i++)
        maxnum = dp[i] > maxnum ? dp[i] : maxnum;

    if (maxnum < 0)
        cout << "0 " << array[0] << " " << array[n - 1] << endl;
    else {
        int res = 0;
        while (maxnum != dp[res])
            res++;
        cout << maxnum << " " << array[dpi[res]] << " " << array[res] << endl;
    }
    return 0;
}
