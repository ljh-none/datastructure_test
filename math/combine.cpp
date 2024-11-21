// combination as recursive

#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

int value[7];
int total = 0;

void comb(int start, int end, int index, int r)
{
    // 종료 조건
    if (index == r)
    {
        cout << "result : ";
        for (int j = 0; j < r; j++)
            cout << value[j] << " ";
        cout << endl;
        total++;
        return;
    }

    for (int i = start; end - i + 1 >= r - index; i++)
    {
        value[index] = i;
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
            cout << value[j] << " ";
        cout << endl;
        total++;
        return;
    }

    for (int i = start; i <= end; i++)
    {
        value[index] = i;
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

void comb_numerical(int start, int end, int r, int index, int buf[])
{
    // start be stored buf
    //  종료 조건
    if (index == r)
    {
        cout << "case " << total << " : ";
        for (int j = 0; j < r; j++)
            cout << buf[j] << " ";
        cout << endl;
        total++;
        return;
    }

    for (int i = start; i <= end; i++)
    {
        buf[index] = i;
        comb_numerical(i + 1, end, r, index + 1, buf);
    }
}

int main()
{
    // 숫자 0 ~ n 사이의 r개의 조합
    int n = 15;
    int r = 7;
    int buf[r];
    comb_numerical(1, n, r, 0, buf);
    cout << "total : " << total << endl;
}

/*
n : 6, r : 3
        start   end     index   r
get     0       5       0       3
for     i = 0; i <= 5 && 6-i >= 3 -> 0 1 2 3 -> 0
get     1       5       1       3
for     i=1; i <=5 && 6-i >= 2 -> 1 2 3 4 -> 1
get     2       5       2       3
for     i=2; i <=5 && 6 - i >=1 -> 2 3 4 5 -> 2
get     3       5       3       3
for     index == r, print, 32 -> 3
get     4       5       3       3
        index == r, print, 32 -> 4
get     5       5       3       3
        index == r, print, 32 -> 5

*/
