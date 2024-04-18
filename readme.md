# data structure & algorithm

### complexity
- time complexity
기본적인 연산 횟수(비교, 할당, 계산, R/W 등)를 입력 크기인 n단위로 표현
알고리즘의 효율성을 나타내는 지표
최악과 평균의 경우만 생각
계수 생략, 차수에 대해서만 고려
시간 복잡도를 쓰는 이유는 거대한 시스템에서 n이 충분히 클 때의 상황을 보려는 것. 따라서 계수의 영향이 미미.
=> 즉, 미지수에 대한 연산 횟수만 고려한다!

- Big oh
모든 n ≥ n0에 대해서, f(n) ≤ cg(n)이 성립하는 양의 상수 c와 n0가 존재하면, f(n) =O(g(n))이다.
-> 두 함수 f(n)과 g(n)\*c가 있다.
-> 범위(n ≥ n0)안에 두 함수가 존재한다.
-> 이 범위에서 f(n)이 g(n)\*c의 값을 절대 넘지 못한다.
-> 이 때, 함수 f(n)은 다음과 같은 빅 오 표기법으로 나타낼 수 있다.
=> f(n) =O(g(n))
=> 즉, 빅 오 표기법은 상한(Upper Bound)을 나타냄.

- space complexity
사용되는 메모리 크기

### tree & graph
graph와 tree의 차이
그래프 : circle형성 가능
Tree : ㄴㄴ

### divide & conquer
divide input(size n) -> subproblem(n/b) * a  
conquer : 문제를 해결  

- merge sort : for linked list, multi processor 병렬화
- quick sort : good for large input
- insert sort
- binary search
- select problem(value search) : find median at data analyzation
- closest pair

- 고려 사항
1. 부적절한 경우
input < sum of sub problem's input 일 때
Ex | n 번째의 피보나치 수를 구하기 - 사실상 n의 값 자체가 입력 크기이므로

2. 문제 특성 상 취합 과정이 효과적일 수 있다.
Ex | most of geometry problem

### greedy
가능한 해들 중에서 가장 좋은 (최대 또는 최소) 해를 찾는다 -> 최적화
근시안적 선택 : 데이터 간 관계 고려 X, 선택 시 번복 X
greedy하게 선택할 값 결정 
-> 이 값이 최소값(비용의 경우) 또는 최대값(이익의 경우)이 되는 값 찾기

- minimum spanning tree
- shortest path
- fractional Knapsack : 최소의 비용으로 자원을 할당
- set cover
- job scheduling 
- Huffman compression

### dynamic programming
input size가 작은 sub problems 해결
–> 그 해들을 "이용"하여 큰 sub problems 해결
–> 최종적으로 이 해들을 이용해 원래 문제 해결

기본적으로 모든 경우의 해를 구하되, 이전에 구한 해는 다시 계산하지 않음.

- All Pairs Shortest Paths
- chained multiplex mul
- edit distance
- 0-1 knap problem
물건 n개
물건 index i
물건 무게 w
물건 가치 v
배낭 총 용량 C
sub program 

matrix 생성
-> row : 물건 index (0~i)
-> column : 물건 weight의 합 (0~C)
-> element's value : 가치


- coin change

----------------------------

- edit distance
3 operation : insert, delete, substitute
옆 위 에서 내려오는건 무조건 +1임. 대각선의경우만 생각하면댐.
왜냐 옆으로가는건 그냥 문자추가. 내려오는건 문자제거?


--------------------  

### ~~fix
1. prefix
2. infix
3. postfix


