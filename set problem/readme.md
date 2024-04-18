# set problem

### Disjoint set
- What is a Disjoint set data structure?
서로소 집합. 공통 요소가 없다(교집합이 null)
1. Adding new sets to the disjoint set.
2. Merging disjoint sets to a single disjoint set using Union operation.
3. Finding representative of a disjoint set using Find operation.
4. Check if two sets are disjoint or not.

- find & union operation
1. find : 대표자를 찾는 연산.
2. union operation : 두 집합이 공통 요소가 없다면 합침. 3가지 advanced algorithm이 있음.
    1. union with path compression finding
    2. union by rank
    3. union by size

### set cover problem
최소한의 부분집합들만 모아서 부모집합 U를 만들어라

- component
U = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}
F = {S1, S2, S3, S4, S5, S6, S7, S8, S9, S10}   //set of subset
C ={S2, S6} //set of minimum subset
S1 = {1, 2, 3, 8}  
S2 = {1, 2, 3, 4, 8}  
S3 = {1, 2, 3, 4} 
S4 = {2, 3, 4, 5, 7, 8} 
S5 = {4, 5, 6, 7}
S6 = {5, 6, 7, 9, 10}
S7 = {4, 5, 6, 7}
S8 = {1, 2, 4, 8}
S9 = {6, 9}
S10 = {6, 10}

- ideal solution : 모든 경우의 수 탐색
U의 원소가 n개일 경우, 모든 경우의 수 2^n-1
-> 사실상 불가능

- approximation solution
1. init C (null)
2. while (U != null)
    2-1. select S : U의 원소를 가장 많이 포함하는 subset
    2-2. U - S : S의 원소들을 제외한 원소들만 U에 잔류
    2-3. add S to C
    2-4. remove S from F

- T.C
a. while loop : 최대 O(n), 최악의 경우 U의 원소 1개씩만 커버됨
b. F의 모든 S를 U와 대조 : 최대 O(n)
c. 특정 S와 U 대조 : 최대 O(n)
d. U - selected S : 최대 O(n)
-> a(b*c+d) = O(n(n^2+n)) = O(n^3)

- set이 처음부터 sorted list라고 가정, 교집합 산출 시 2n, O(n)

- virus signature?