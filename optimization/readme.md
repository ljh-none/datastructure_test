### job scheduling
- 종류
Earliest start time first - realtime system (얘 뺴고 다 별로)
Earliest finish time first - realtime system
Shortest job first 
Longest job first

- 과정
job list sort
while job list is not empty
1. L에서 가장 이른 시작 시간 작업 ti를 가져온다.
2. if ti를 수행할 기계가 있으면 배정 else 새 기계에 ti를 배정
3. remove ti from list

- T.C
a. sort O(nlogn)
b. while loop O(n)
c. job 할당 O(m), m=기계수
-> a+b*c=O(nlogn+mn)

### fractional Knapsack knap

### 0-1 knap problem
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