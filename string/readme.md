### ~fix
1. prefix
2. infix
3. postfix

### edit distance
source string -> target string
3 operation : insert, delete, substitute

1. simple solution
![alt text](images/image-1.png)

2. best solution
![alt text](images/image-2.png)

matrix 사용 
-> E[i,j]= i길이 source를 j길이 target으로 변환할 때 필요한 연산 횟수
![alt text](images/image-3.png)

3. pseudo code
str_source, length m
str_target, length n
init_matrix
    for i in range(0, m) E[i, 0] = i
    for j in range(0, n) E[0, j] = j

for i in range(1, m)
    for j in range(1, n)
        E[i, j] = min{E[i, j–1] +1, E[i–1, j] +1, E[i–1, j–1] + α}
return E[m, n]

4. T.C
sub problem 수 : source length * target length
sub 당 연산 횟수 : O(4), 좌상단 3개의 원소 중 최솟값 찾기 + 문자열이 같은지 비교
=> O(mn)