# path problem

### 참고 링크
https://www.geeksforgeeks.org/kruskals-minimum-spanning-tree-algorithm-greedy-algo-2/

### MST
minimum (weight) spanning tree  
간선들의 가중치 합이 최소인 트리  
cycle 없이 모든 점을 연결시켜야 한다.(주의, tree에 간선 하나 추가하면 사이클됨)  

- spanning?

- component
input = 1 connected component
number of volt on graph : n
number of edge on graph : m
number of volt on spanning tree : v
number of edge on spanning tree : n-1

- 샘플 그래프
노드: 0, 1, 2, 3, 4
간선:
(0, 1, 7)
(0, 3, 5)
(1, 2, 8)
(1, 3, 9)
(1, 4, 7)
(2, 4, 5)
(3, 4, 15)
(3, 2, 5)

### kruskal - MST
- 절차
    1. 가중치 오름차순 정렬. create empty tree
    2. 1 edge fetch, cycle이 생성되는지 체크 
    3. 생성되지 않는다면 tree에 추가
    4. tree's edge가 node - 1이 될 때까지 반복

- 추가된 edge가 cycle을 형성하는지 판별하는 방법
set problem -> disjoint set

- T.C
a. edge sort : O(mlogm)
b. while loop : O(m)
c. cycle 검사 -> find-union : O(logm)
a+b*c = O(mlogm)

### prim - MST
- component
distance array : tree 바깥의 volts 중 가장 가까운 volts에 대한 distance 저장 배열. 이외 volts의 가중치는 null

- 절차
1. 임의의 점 p 선택
2. init distance array
    D[p]=0
    D[closest volts] = weight
    D[others] = null
3. start while
    3-1. tree에 distance가 최소인 volt와의 edge 추가
    3-2. update distance array

- prim이 cycle을 만들지 않는 이유
tree에 volt 추가 시 항상 tree 바깥의 volt만 추가하므로 cycle의 형성 여부를 고려하지 않아도 된다.

- T.C : O(n^2)
1. 기본 경우
a. while loop : O(n-1)
b. search min volt in distance array : O(n) (sizeof(D)=number of volt on graph)
a*b=O(n^2)

2. distance를 array에서 binary heap으로 변경 시
a. while loop : O(n-1)
b. search min volt in distance heap으로 : O(logm)
a*b=O(nlogn)

### Dijkstra - shortest path
prim이랑 유사한 최단 경로 탐색 방법
-> distance array에 저장하는 데이터가 다름!

- component
distance array : start point ~ selected point 까지의 최단 거리

- 절차
1. 시작점 s 선정
2. init distance array
    D[s]=0
    D[others] = null
3. while loop
    3-1. distance가 가장 낮은 volt select   (첫 시작 시 s 선택)
    3-2. "start ~ selected" 의 distance 확정 (s의 경우 0으로)
    3-3. edge relaxation : "start ~ selected의 인접 points" 간의 distance 완화
4. start ~ all volts 간 shortest distance 반환

- T.C
a. while loop : O(n-1) (size of distance array == number of volts on graph)
b. selected point와 연결된 volt가 최대 n-2개 있을 수 있으므로 이 경우 O(n-2)
-> a*b = O(n^2)
distance array -> binary heap으로 교체 시 O(mlogn)

### floyd algorithm - All Pairs Shortest Paths
- 방법 1. dijkstra n번 수행
복잡함

- 방법 2. floyd : 모두 고려
start ~ end의 distance와
start ~ waypoint ~ end의 distance 중 최단 경로 선택.
이를 점 3개의 경우부터 시작하여 키워나감

- pseudo code
2dim array distance     //평면 상 좌표이므로
init distance
    D[i, j] : edge가 연결되어 있으면 weight값, 아니면 null
    D[i, i] : all 0
    D[j, i] : D[i, j]와 같으므로 고려 X (두 volt 간 edge가 2개일 때는 계산 필요)
for way_point in range(1, n)
    for i in range(1, n)    // 단, waypoint != i
        for j in range(1, n)    // 단, waypoint != j, i
            D[i, j] = min(D[i, way_point]+D[way_point, j], D[i, j])
