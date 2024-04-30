# Matrix

### 기본 연산
실제 연산 전, 연산 횟수를 먼저 계산 후 최소 횟수가 되는 순서를 찾아 결합 법칙을 적용하여 해결

m by n * n by o
=> 연산 횟수 = m * n * o

- 연산 횟수 matrix
matrix에 연산 횟수 기록
n개의 matrix를 연산해야 한다면
M = n * n 정방행렬.
-> column : 곱셈을 시작할 matrix의 index
-> row : 곱셈을 끝낼 matrix의 index
-> upper triangle만 고려
-> 대각선 단위로 계산

- T.C
sub problem 수 : (n-1)+(n-2) + ... + 1 = (n-1)(n-2)/2
sub problem 당 연산 횟수 : 