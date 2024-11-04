// combination as recurrence relation

#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

int comb(int n, int r)
{
    int arr[n + 1][r + 1];

    for (int i = 0; i <= n; i++)
    {
        int min = i > r ? r : i;
        for (int j = 0; j <= min; j++)
        {
            if (j == 0 || j == i)
            {
                arr[i][j] = 1;
            }
            else
            {
                arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
            }
        }
    }

    return arr[n][r];
}

int main()
{
    cout << comb(7, 3) << endl;
}

/*
def combination(n, r):
B = [[0 for _ in range(r+1)] for _ in range(n+1)]
for i in range(n+1):
for j in range( min(i, r) + 1 ):
if j == 0 or j == i:
B[i][j] = 1
else:
B[i][j] = B[i-1][j-1] + B[i-1][j]
return B[n][r]

*/