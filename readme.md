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
time complexity : O(n^2)
(n-1)+(n-2)+(n-3)+...+1 번 비교
-> (n-1)*n/2

1. bubble sort
2. insert sort
3. quick sort

### ~~fix
1. prefix
2. infix
3. postfix

### search

### linked list

### tree