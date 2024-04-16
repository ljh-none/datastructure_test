### binary search

### selection
- selection
수행 과정 : 과제로 했으니 옮기셈요
T.C :
goob/bad divide : divide 시 크기가 input의 3/4를 넘으면 bad
정렬에 n번 연산
분할 후 크기 3/4 감소, 큰 한쪽에서 다시 selection 수행 -> 3/4n
n + 3/4n + (3/4)^2n + .... + (3/4)^in
= n(1 + 3/4 + (3/4)^2 + ... + (3/4)^i)
= O(n)