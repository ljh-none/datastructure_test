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

### sort
- selection sort
1. time complexity : O(n^2)
(n-1)+(n-2)+(n-3)+...+1 번 비교
-> (n-1)*n/2

- merge sort
1. time complexity : O(nlogn)
문제 분할 시 마다 부분문제로 이루어진 층이 하나 생긴다.
더이상 분할하지 못할 때 까지 수행하면 k개의 층이 생긴다.
입력이 n인 문제는 분할 때마다 반씩 줄어듦 
-> 마지막 층의 입력은 n/(2^k)
-> 총 log_2_n개의 층
각 층에서 합병 수행 시 O(n)만큼의 시간이 든다.
그러므로 총 수행 시간은 log_2_n x O(n) = O(nlogn)
2. 특징
합병 결과를 저장할 입력 크기만큼의 배열이 별도로 필요 -> 공간 복잡도 증가
외부 정렬, 정렬의 병렬화 시 사용

- quick sort
1. TC
최악 : pivot이 항상 작을 때. 
(n-1)+(n-2)+(n-3)+…+2+1 = n(n-1)/2 = O(n^2)
최선 : like merge sort. O(nlogn)
2. feature
pivot 왼/오른쪽에 작은/큰 수 배치
-> pivot 선정하고
-> 배열의 끝으로 이동(주로 왼쪽)
-> 양 끝 인덱스에서 시작해서 수를 비교해가며 정렬
-> 교차 시 종료. pivot 복귀
3. pivot 선정 방법
random
median of three
median of median
4. with insertion sort
성능 향상 방법. quick sort는 입력크기가 클 때 성능 좋음
sub problem의 크기가 작을 시 insertion sort 수행

- bubble sort

- insert sort


### divide & conquer
conquer : 문제를 해결

- selection
수행 과정 : 과제로 했으니 옮기셈요
T.C :
goob/bad divide : divide 시 크기가 input의 3/4를 넘으면 bad
정렬에 n번 연산
분할 후 크기 3/4 감소, 큰 한쪽에서 다시 selection 수행 -> 3/4n
n + 3/4n + (3/4)^2n + .... + (3/4)^in
= n(1 + 3/4 + (3/4)^2 + ... + (3/4)^i)
= O(n)

- closest pair
수행 코드 짜보기
T.C :
방법 1. 전수조사 : nC2 -> O(n)
방법 2. divide & conquer : 

- 분할 정복이 부적절한 경우
- 입력이 분할될 때마다 분할된 부분 문제의 입력 크기의 합이 분할되기 전의 입력 크기보다 커지는 경우
분할 정복처럼 보이므로 주의 필요
(Ex)n 번째의 피보나치 수를 구하기 - 사실상 n의 값 자체가 입력 크기이므로

### greedy
가능한 해들 중에서 가장 좋은 (최대 또는 최소) 해를 찾는다 -> 최적화
근시안적 선택 : 데이터 간 관계 고려 X, 선택 시 번복 X
greedy하게 선택할 값 결정 
-> 이 값이 최소값(비용의 경우) 또는 최대값(이익의 경우)이 되는 값 찾기

MST : minimum (weight) spanning tree, input = 1 connected component

- MST - kruskal
코드 짜보기

- MST - prim

- Dijkstra 
주어진 출발점에서 시작
출발점으로부터 최단 거리가 확정되지 않은 점들 중에서 출발점으로부터 가장 가까운
점을 추가하고, 그 점의 최단 거리를 확정
prim이랑 유사
배열 생성, 시작점 s세팅(거리0) 나머지 무한


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

### dynamic programming algorithm
- All Pairs Shortest Paths

chained multiplex mul

- edit distance
3 operation : insert, delete, substitute
옆 위 에서 내려오는건 무조건 +1임. 대각선의경우만 생각하면댐.
왜냐 옆으로가는건 그냥 문자추가. 내려오는건 문자제거?

### ~~fix
1. prefix
2. infix
3. postfix

### search
binary search

### linked list

### tree
graph와 tree의 차이
그래프 : circle형성 가능
Tree : ㄴㄴ