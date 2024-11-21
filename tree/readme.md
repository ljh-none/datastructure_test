# Tree
계층적 형태를 갖는 여러 개의 데이터를 다룰 때 사용하는 비선형 자료구조

### kind of tree
1. Generic tree
2. binary tree
    대량의 데이터를 indexing하면 빠른 속도로 search, sort 연산 가능
3. binary search tree : left less than parent
4. RB tree

##### binary tree
root와 left sub tree & right sub tree로 분리된 이진 트리로 구성된 노드
의 유한 집합
𝑛개 노드를 갖는 이진 트리는 𝑛 − 1개의 간선을 갖는다.
노드의 개수가 𝑛개일 때 이진 트리의 높이 ℎ는 최소 log 𝑛 + 1 , 최대 𝑛이다.
레벨 𝑖에서의 최대 노드 수는 2𝑖−1이다.
높이가 ℎ인 이진 트리의 최대 노드 수는 최소 ℎ개,최대 2ℎ− 1이다.

##### Binary Search Tree
이진 트리의 기본 속성을 만족하면서,
1) 모든 노드는 고유의 키를 가지며, 각각의 키는 상이함.
2) 왼쪽 서브 트리에 포함된 키들은 그 루트 노드의 키보다 작다.
3) 오른쪽 서브 트리에 포함된 키들은 그 루트 노드의 키보다 크다.
4) 왼쪽과 오른쪽 서브 트리도 모두 이진 탐색 트리이다.

### operations
1. Search
    Depth First Search
    Breadth First Search
2. Insertion
3. Deletion
4. Traversal
    DFS : Depth First Search
        Inorder
        Preorder
        Postorder
    BFS : Breadth First Search
        == Level order travel

### use case
1) 자료의 구성 형태가 계층적으로 조직되어 있는 경우
2) 계층적 형태를 갖는 자료 또는 논리를 표현하거나 탐색을 위한 상태 공간을 표현할 때
-> 결정 트리(Decision tree), 파스 트리(Parsed tree), 상태 공간 트리(State space tree)
3) 문제를 유한 개의 상태(state)와 유한 개의 취할 수 있는 행동(action)으로 모델링할 수 있는 경우
4) 깊이 우선 탐색(DFS) 또는 너비 우선 탐색(BFS)을 수행해야 하는 경우
5) 계층적(Hierarchical) 형태의 자료 구조로 모델링할 수 있는 경우
6) 분할 정복 알고리즘 또는 동적 계획법을 사용하는 경우
7) 주어진 입력의 크기가 n일 때 시간 복잡도를 𝑂(𝑛) → 𝑂(log 𝑛)또는 𝑂(𝑛2) → 𝑂(𝑛 log 𝑛)으로 감소시켜야 하는 경우
8) 분리 집합(disjoint set)을 활용해야 하는 경우