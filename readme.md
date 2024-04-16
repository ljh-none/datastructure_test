# data structure & algorithm

### complexity
- time complexity
기본적인 연산 횟수(비교, 할당, 계산, R/W 등)를 입력 크기인 n단위로 표현
알고리즘의 효율성을 나타내는 지표
최악과 평균의 경우만 생각

- 계수 생략, 차수에 대해서만 고려
시간 복잡도를 쓰는 이유는 거대한 시스템에서 n이 충분히 클 때의 상황을 보려는 것. 따라서 계수의 영향이 미미.

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

---------------------------------------------------
- Fractional Knapsack
단위 무게 당 가치 계산 후 greedy -> 최적 해와 크게 차이 안남
T.C : 물건 갯수 n개
단위무게 가치 O(n)
가치 순 정렬 O(nlogn)
while문 O(n)
나머지 상수 O(1)
=> 다더하면 O(nlogn)

- set cover problem
U : n개의 원소 집합.
F : U의 부분집합들을 원소로 하는 집합. F의 크기 = c*n
=> F에서 선택한 set의 수를 최소화 하여 U를 만들어라
solution 1 : 2^n만큼의 경우의 수 모두 따진다 -> O(2^n) -> 최적 해 발견
solution 2 : 근사 해 찾기
신도시학교 tc -> 코드 짜볼 것
while문 n
set이 처음부터 sorted list라고 가정, 교집합 산출 시 2n, O(n)

virus signature?

- job scheduling
Earliest start time first - realtime system
Earliest finish time first - realtime system
Shortest job first 
Longest job first
1빼고 조금 별로

- Huffman compression
ASCI code : 문자 하나 당 8bit
문자 별 빈도수 산출
-> 빈번한 문자에는 짧은 이진코드
-> 드문 문자에는 긴 이진 코드
prefix property 적용
    글자가 같을 경우 - 글자구분가능
    다를경우 - 어디서부터 어디까지가 문자 하나인지 구분 불가능
Huffman tree 생성
이를 기반으로 각 문자에 binary code 할당
해당 코드로 압축한 파일과 문자 별 빈도수를 송신
-> 수신측에서도 Huffman tree 생성 후 압축해제

0 -> A확정
1
11 -> C확정
10 -> 0시작인 A가 이미 있으므로 넘어간다
100 -> 확
101 -> 확

### dynamic programming
- All Pairs Shortest Paths

chained multiplex mul

- edit distance
3 operation : insert, delete, substitute
옆 위 에서 내려오는건 무조건 +1임. 대각선의경우만 생각하면댐.
왜냐 옆으로가는건 그냥 문자추가. 내려오는건 문자제거?




  
--------------------  
### ~~fix
1. prefix
2. infix
3. postfix


