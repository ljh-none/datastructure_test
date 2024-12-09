#include <stdlib.h>
#include <stdio.h>

//

solution1(int n, int k)
{
    int answer[n];
    for (int i = 0; i < n; i++)
    {
        answer[i] = 0;
    }

    int count = -1;
    for (int i = 0; i < n; i++)
    {
        count += 3;
        if (answer[count] == 0)
        {
            answer[count] = count + 1;
        }
        }
}

int main()
{
}