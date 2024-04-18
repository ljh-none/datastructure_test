# scheduling problem

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