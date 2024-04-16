#include <stdio.h>
#include <stdlib.h>

// 2차원 평면상에서 n개의 점이 입력으로 주어질 때,
// 거리가 가장 가까운 한쌍의 점 찾기
// int ary[][2]에서 row 대괄호가 무시되는 이유?

// Row 갯수 산출 함수
int countRow(int size_1, int size_2)
{
    return size_1/
}

int *find_closest_pair(int ary[][2])
{
    static int arr[2] = {0, 1};
    return arr;

    //
    // 1. 점 갯수가 2~3개일 경우
}

int main()
{
    int coordinates[10][2] = {
        {1, 9},
        {2, 5},
        {3, 4},
        {4, 6},
        {5, 7},
        {6, 8},
        {7, 3},
        {8, 2},
        {9, 1},
        {10, 10}};

    // input : x좌표 순으로 오름차순 정렬
    int *result = find_closest_pair(coordinates);
}