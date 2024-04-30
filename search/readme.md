### n-th number search

### binary search
divide한 두 블록 중 한 쪽 블럭만 탐색

### selection
quick sort와 유사.
k번째로 큰 숫자는 index가 k-1 이므로 해당 인덱스가 피봇이 될 때까지? 분할

- goob/bad divide
divide 시 sub problem의 크기가 input의 3/4를 넘으면 bad

- T.C
a. good divide -> 3/4 subproblem에서만 탐색 시
n + 3/4n + (3/4)^2n + .... + ((3/4)^i)n
= n(1 + 3/4 + (3/4)^2 + ... + (3/4)^i) = O(n)
b. good or bad divd의 경우
2번에 한 번 꼴로 good 출현 -> O(2)
=> a*b = 2O(n) = O(n)

