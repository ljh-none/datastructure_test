#include <string>
#include <vector>
#include <iostream>

using namespace std;

void do_union(int a, int b, int *ary)
{
    // weight rule이 적용된 union 연산
    // 1. 원소 a, b의 root를 찾는다.
    while (ary[a] >= 0)
    {
        a = ary[a];
    }
    while (ary[b] >= 0)
    {
        b = ary[b];
    }

    // 같은 root의 집합인 경우
    if (a == b)
    {
        return;
    }

    // 2. 해당 root중 원소의 갯수가 작은 쪽을 큰 쪽의 자식으로
    int temp = ary[a] + ary[b]; // 총 원소의 갯수 계산
    if (-ary[a] < -ary[b])      // 집합 i의 원소 수가 집합 j보다 적다면
    {
        // 노드 j를 "노드 i의 부모 노드"로 지정
        // == "집합 i의 루트 노드"를 "집합 j의 루트 노드"로 지정
        ary[a] = b;
        ary[b] = temp; // 집합 j의 원소 수 업데이트
    }
    else
    {
        ary[b] = a;
        ary[a] = temp;
    }
}

int do_find(int i, int *parent)
{
    // 붕괴 규칙이 적용된 find연산
    int root = i; // root를 i로 초기화
    int trail = i;
    int lead;

    // 1. 먼저 노드 i가 속한 트리의 root를 찾는다.
    while (parent[root] >= 0)
    {
        root = parent[root];
    }

    // trail이 따라 올라가며 자식 노드의 원소를 현재 루트 노드의 값으로 갱신
    while (trail != root)
    {
        lead = parent[trail];
        parent[trail] = root;
        trail = lead;
    }

    return root;
}

int do_find_2(int i, int *ary)
{
    // 간단한 find 연산
    int temp = i;

    while (ary[temp] >= 0)
    {
        temp = ary[temp]; // move to parent
    }

    return temp;
}

int main()
{
    // 0. 변수 정의
    int n;    // 초기 집합은 n+1 개로 되어 있다. 각 원소는 0 ~ n
    int m;    // 다음 m개의 줄에 주어지는 각각의 연산
    int inst; // 명령어, 0 : 합집합 연산, 1 : 같은 집합인지 확인하는 연산
    int a;    // 대상 원소 1
    int b;    // 대상 원소 2

    // 1. 초기 정보 입력받기
    scanf("%d %d", &n, &m);

    // 2. 초기 정보를 바탕으로 자료구조 초기화
    int ary[n + 1]; // 집합을 저장하는 자료구조
    // index : 집합의 원소
    // value가 음수 : root 노드 & 해당 root가 가진 원소 수
    // value가 양수 : 해당 원소의 parent node
    for (int i = 0; i <= n; i++)
    {
        ary[i] = -1;
    }

    // 3. 연산 명령 입력받기
    for (int k = 0; k < m; k++)
    {
        scanf("%d %d %d", &inst, &a, &b);
        if (inst == 0)
        {
            do_union(a, b, ary);
        }
        else if (inst == 1)
        {
            int result_a = do_find(a, ary);
            int result_b = do_find(b, ary);
            if (result_a == result_b)
            {
                printf("YES\n");
            }
            else
            {
                printf("NO\n");
            }
        }
        else
        {
            continue;
        }
    }
}