/*
문제 2. 모의 고사

분석

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_ary(int *answer, int *p1, int *p2, int *p3, int length)
{
    printf("answer : ");
    for (int i = 0; i < length; i++)
    {
        printf("%d ", answer[i]);
    }
    printf("\n");

    printf("p1 : ");
    for (int i = 0; i < length; i++)
    {
        printf("%d ", p1[i]);
    }
    printf("\n");

    printf("p2 : ");
    for (int i = 0; i < length; i++)
    {
        printf("%d ", p2[i]);
    }
    printf("\n");

    printf("p3 : ");
    for (int i = 0; i < length; i++)
    {
        printf("%d ", p3[i]);
    }
    printf("\n");
}

void allocate_answer(int *answer, int *p1, int *p2, int *p3, int length)
{
    // 포인터 변수 선언
    // p1 : 전달받은 주소
    // &p1 : p1 포인터 변수의 주소
    // *p1 : 전달받은 주소의 실제 인스턴스

    for (int i = 0; i < length; i++)
    {
        // real answer
        answer[i] = (rand() % 5) + 1;

        // p1 answer
        p1[i] = i % 5 + 1;

        // p2 answer
        if (i % 2 == 0)
        {
            p2[i] = 2;
        }
        else
        {
            int check = i % 8;
            if (check == 1)
            {
                p2[i] = 1;
            }
            else if (check == 3)
            {
                p2[i] = 3;
            }
            else if (check == 5)
            {
                p2[i] = 4;
            }
            else if (check == 7)
            {
                p2[i] = 5;
            }
            else
            {
                printf("err!\n");
            }
        }

        // p3 answer
        int check = i % 10;
        if (check == 0 || check == 1)
        {
            p3[i] = 3;
        }
        else if (check == 2 || check == 3)
        {
            p3[i] = 1;
        }
        else if (check == 4 || check == 5)
        {
            p3[i] = 2;
        }
        else if (check == 6 || check == 7)
        {
            p3[i] = 4;
        }
        else if (check == 8 || check == 9)
        {
            p3[i] = 5;
        }
        else
        {
            printf("err!\n");
        }
    }
}

void solution1(int *answer, int *p1, int *p2, int *p3, int length)
{
    int count[3] = {0, 0, 0};

    for (int i = 0; i < length; i++)
    {
        if (p1[i] == answer[i])
        {
            count[0]++;
        }

        if (p2[i] == answer[i])
        {
            count[1]++;
        }

        if (p3[i] == answer[i])
        {
            count[2]++;
        }
    }

    printf("result : ");
    for (int i = 0; i < 3; i++)
    {
        printf("%d ", count[i]);
    }
    printf("\n");
    return;
}

int main()
{
    srand(time(0));
    int length = 20; // < 10000
    int answer[length];
    int p1[length]; // p1 : 배열의 시작 주소, p1[i] : 원소
    int p2[length];
    int p3[length];

    allocate_answer(answer, p1, p2, p3, length);
    printf("[list]\n");
    print_ary(answer, p1, p2, p3, length);
    solution1(answer, p1, p2, p3, length);
    return 0;
}
