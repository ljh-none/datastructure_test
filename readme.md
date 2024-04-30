# DSA

### Complexity
- time complexity : 거대한 미지수에 대한 연산 횟수만 고려
기본적인 연산 횟수(비교, 할당, 계산, R/W 등)를 입력 크기인 n단위로 표현
알고리즘의 효율성을 나타내는 지표
최악과 평균의 경우만 생각
계수 생략, 차수에 대해서만 고려
시간 복잡도를 쓰는 이유는 거대한 시스템에서 n이 충분히 클 때의 상황을 보려는 것. 따라서 계수의 영향이 미미.
=> 즉, 미지수에 대한 연산 횟수만 고려한다!

- space complexity
사용되는 메모리 크기

- 지표 표기법
1. big oh : O(n), 상한선
2. big omega : Ω(n), 하한선
3. big theta : Θ(n), 유사한 증가율

- 각 지표 별 유도
두 함수 f(x), g(x)가 모든 x(≥ x0)에 대하여 (상수 n)
Big oh : f(x) ≤ ng(x) 인 n과 x0가 존재 -> f(x)=O(g(x))
    -> (x0, ∞)에서 f(x)이 ng(x)의 값을 절대 넘지 못한다.
    -> 상한
Big omega : f(x) ≥ ng(x) 인 n과 x0가 존재 -> f(x)=Ω(g(x))
Big theta : ng(x) ≥ f(x) ≥ mg(x) 인 n, m, x0가 존재 -> f(x) = Θ(g(x))

- 자주 사용되는 함수 별 그래프
![alt text](images/image.png)

### Data Structure
- array, linked list
- matrix, Grid
- stack
- queue
- hash
- heap
- string
- graph, tree
- set
- map 

### Algorithm
##### divide & conquer
- feature
divide input(size n) -> subproblem(n/b) * a  
conquer : 문제를 해결  

- 종류
    1. merge sort : for linked list, multi processor 병렬화
    2. quick sort : good for large input
    3. insert sort
    4. binary search
    5. select problem(value search) : find median at data analyzation
    6. closest pair

- 고려 사항
1. 부적절한 경우
input < sum of sub problem's input 일 때
Ex | n 번째의 피보나치 수를 구하기 - 사실상 n의 값 자체가 입력 크기이므로
2. 문제 특성 상 취합 과정이 효과적일 수 있다.
Ex | most of geometry problem
##### greedy
- feature
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
##### dynamic programming
- feature
input size가 작은 sub problems 해결
–> 그 해들을 "이용"하여 큰 sub problems 해결
–> 최종적으로 이 해들을 이용해 원래 문제 해결
-> 체계적인 solution 설계 가능 but TC 증가
기본적으로 모든 경우의 해를 구하되, 이전에 구한 해는 다시 계산하지 않음.

- All Pairs Shortest Paths
- chained multiplex mul
- edit distance
- 0-1 knap problem
##### Searching
##### Sorting
##### Bitwise
##### Recursion
##### Backtracking
##### Mathmatical
##### Geometric


# --------------------------------
0-1 knap problem
물건 n개
물건 index i
물건 무게 w
물건 가치 v
배낭 총 용량 C
sub program 

matrix 생성
-> row : 물건 index (0~i)
-> column : 배낭의 용량 (0~C), 이 요소로 weight까지 다룸
-> element's value : 가치

단위무게 당 가치 고려 안하는 이유 : 어차피 모두고려라
3개 이상 들어갈 때도 저걸로 풀리나? ㅇㅇ
용량이 작으면 이게 효율적. 크면 힘듬

- coin change
동전 value가 배수가 아닐 때 greedy로 ideal solution 못찾음
dp쓰면 가능
초기화 시 d[0]=0, d[동전 value에 해당하는 index]=1, 나머지 infinit

TC 
O(nk) -> n=k+1 -> O(k^2)?

입력크기 logn=x -> O(2^x*k)

----------------------------

배낭문제 O(nC) -> O(k^2)?




--------------------  








입력 크기 n에 대해 sin(n) + 1의 θ 표기를 구할 수 있는가? 그 이유를 설명하시오.

분할 정복 문제가 a개로 분할되고, 부분 문제의 크기가 1/b로 감소한다고 표현할 때, "이진 탐색"의 a와 b를 구하시오.

퀵 정렬에서 pivot을 선정하는 방식으로 Median-of-Medians (또는 Turkey's Ninther) 방식을 선택했을 때 최악의 시간복잡도를 계산하시오

최근접점 쌍 찾기 문제 (closest pair problem)에서 중간 영역에 있는 점들을 매번 y-좌표 기준으로 정렬하면 전체 시간복잡도가 O(nlog^2 n)가 된다. 이 정렬 부분을 개선해서 시간복잡도를 더 줄이는 방법을 제시하시오.

다음 무방향성 그래프에서 시작점을 0으로 하는 모든 점으로의 shortest path를 Dijkstra의 알고리즘으로 푸시오. 순서대로 선택된 각 점, 그 점으로의 경로값, 그리고 수정된 D값을 제시하시오.선택된 정점 | 경로값 | D[1 2 3 4 5 6 7] 

.다음 4개의 행렬이 주어질 때    A1: 100 x 40   A2: 40 x 50   A3: 50 x 20   A4: 20 x 50
a. A1 x A2 x A3 x A4를 최소의 곱셈으로 구하는 행렬곱의 순서를 괄호로 표현하고,
b. 그로 인한 곱셈의 개수를 구하시오.

3.한 파일이 5개의 문자로 구성되어 있고, 다음과 같이 5개 문자의 빈도수가 주어진다.m : 10i : 32e : 40b : 5o : 27
a. 각 문자의 Huffman code는 무엇인가?

b. 8-bit ASCII 코드로 구성된 이 파일에 Huffman 압축을 적용하면 파일 크기가 원래의 몇 %가 되는가?
c. 문자열 'iboombe'를 Huffman 압축하시오. 이진코드로 표시하시오.
d. 압축된 이진코드가 전달되는 과정에서 첫 0001이 1100으로 변경되었다. 변경된 압축코드를 받은 수신자가 압축을 풀면 어떤 문자열을 얻게 되는가?


.다음 Big-O 표기들을 작은 값부터 큰 값 순으로 배열하시오.
n^3 2^n nlogn 1

임의의 n개 데이터들을 연결리스트와 배열에 각각 넣었다고 가정하자. 다음 물음에 답하시오.
어떤 값이 이 자료구조에 들어 있는지 찾으려고 할 때, 어떤 자료구조가 더 효율적인가?
만약 데이터들을 자료구조에 넣는 방법을 변경한다면 임의로 넣을 때보다 찾을 때 더 효율적으로 찾을 수 있는 자료구조는 어떤 것인가?
이 때 어떤 방식으로 데이터들을 넣으면 찾는 효율이 높아지는가?
그리고 얼마만큼 더 높아지는가?

주어진 그래프에서 최소 신장 트리 (minimum spanning tree)를 구하려고 한다. 간선 (edge)들이 무게순으로 이미 정렬되어 있다면 Kruskal의 방법과 Prim의 방법 중 어떤 것이 더 효율적인가? 그 이유를 설명하시오.

합병 정렬 (merge sort)의 시간복잡도와 공간복잡도는 각각 무엇인가?

퀵 정렬 (quick sort)과 삽입 정렬 (insertion sort)를 비교하려고 한다. 다음 물음에 답하시오.
퀵 정렬의 최소 시간복잡도와 최대 시간복잡도는 각각 무엇인가?
삽입 정렬의 최소 시간복잡도와 최대 시간복잡도는 각각 무엇인가?
어떤 정렬 알고리즘이 더 효율적인가? 그 이유를 설명하시오