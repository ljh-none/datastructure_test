/*
nCr 계산하기
-> 팩토리얼 구현

방법 1. 반복문 -> 반복문으로 팩토리얼 구현 시 오버플로우
방법 2. 재귀 << 이게있었네. 얘는 이미 구현해봄
방법 3. 점화식 -> 이차원 배열의 동적 계획법

이항계수는 동적계획법으로
동적계획법은 아주 어렵게는 안나옴
피보나치수열, 행렬곱셈 같은거


*/
#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

int data[3];
int total = 0;

void comb(int start, int end, int index, int r)
{
    // 종료 조건
    if (index == r)
    {
        cout << "result : ";
        for (int j = 0; j < r; j++)
            cout << data[j] << " ";
        cout << endl;
        total++;
        return;
    }

    for (int i = start; end - i + 1 >= r - index; i++)
    {
        data[index] = i;
        comb(i + 1, end, index + 1, r);
    }
}

void comb2(int start, int end, int r, int index)
{
    // start <= x <= end 사이 범위의 숫자 중에서 r개의 조합
    // start는 store할 값이다.
    // r : 몇 개를 선택할 것인지
    // index : r개 중에서 몇 번째인지
    // 처음 index는 0 이다

    //  종료 조건
    // ex) r == 3 이면 index 0, 1, 2가 다 채워진것이므로 출력을 실행 후 종료
    // 종료 조건
    if (index == r)
    {
        cout << "result : ";
        for (int j = 0; j < r; j++)
            cout << data[j] << " ";
        cout << endl;
        total++;
        return;
    }

    for (int i = start; i <= end; i++)
    {
        data[index] = i;
        comb2(i + 1, end, r, index + 1);
    }
}

void comb3(int start, int end, int r, int index, int buf[])
{
    // 종료 조건
    if (index == r)
    {
        cout << "result : ";
        for (int j = 0; j < r; j++)
            cout << buf[j] << " ";
        cout << endl;
        total++;
        return;
    }

    for (int i = start; i <= end; i++)
    {
        buf[index] = i;
        comb3(i + 1, end, r, index + 1, buf);
    }
}

int main()
{
    // 숫자 0 ~ n 사이의 r개의 조합
    int n = 6;
    int r = 3;
    int buf[r];
    comb3(0, n, r, 0, buf);
    cout << "total : " << total << endl;
}