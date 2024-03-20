# data structure & 

### complexity
time complexity
기본적인 연산 횟수(비교, 할당, 계산, R/W 등)를 입력 크기인 n단위로 표현
최악과 평균의 경우만 생각
계수 생략, 차수에 대해서만 고려
계수 생략 이유
시간 복잡도를 쓰는 이유는 거대한 시스템에서 n이 충분히 클 때의 상황을 보려는 것. 따라서 계수의 영향이 미미.

알고리즘의 효율성을 나타내는 지표

Big oh
모든 n ≥ n0에 대해서, f(n) ≤ cg(n)이 성립하는 양의 상수 c와 n0가 존재하면, f(n) =O(g(n))이다.
-> 두 함수 f(n)과 g(n)\*c가 있다.
-> 범위(n ≥ n0)안에 두 함수가 존재한다.
-> 이 범위에서 f(n)이 g(n)\*c의 값을 절대 넘지 못한다.
-> 이 때, 함수 f(n)은 다음과 같은 빅 오 표기법으로 나타낼 수 있다.
=> f(n) =O(g(n))
=> 즉, 빅 오 표기법은 상한(Upper Bound)을 나타냄.

space complexity
사용되는 메모리 크기

### sort
1. selection sort
1-1. time complexity : O(n^2)
(n-1)+(n-2)+(n-3)+...+1 번 비교
-> (n-1)*n/2

2. merge sort
2 - 1. time complexity : O(nlogn)
문제 분할 시 마다 부분문제로 이루어진 층이 하나 생긴다.
더이상 분할하지 못할 때 까지 수행하면 k개의 층이 생긴다.

입력이 n인 문제는 분할 때마다 반씩 줄어듦으로 마지막 층에서의 입력의 크기는 n/(2^k)임을 알 수 있다.
이를 통해 층수는 log_2_n 임을 알 수 있다.

각 층에서 합병 수행 시 O(n)만큼의 시간이 든다.
그러므로 총 수행 시간은 log_2_n x O(n) = O(nlogn)

2 - 2. 특징
합병 결과를 저장할 입력 크기만큼의 배열이 별도로 필요 -> 공간 복잡도 증가
외부 정렬, 정렬의 병렬화 시 사용

3. quick sort


1. bubble sort
2. insert sort


### ~~fix
1. prefix
2. infix
3. postfix

### search

### linked list

### tree