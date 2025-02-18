//{ Driver Code Starts
// Initial Template for C++

#include <iostream>
#include <vector>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int f(int index, int price[], int n, vector<vector<int>> &dp)
    {
        if (index == 0)
        {
            return (n * price[index]);
        }
        if (dp[index][n] != -1)
            return dp[index][n];
        int ntake = f(index - 1, price, n, dp);
        int take = INT_MIN;
        if (index + 1 <= n)
            take = price[index] + f(index, price, n - index - 1, dp);
        return dp[index][n] = max(take, ntake);
    }
    int cutRod(int price[], int n)
    {
        // code here
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return f(n - 1, price, n, dp);
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];

        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends