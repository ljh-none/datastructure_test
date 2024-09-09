# Sort
- type of sort
1. Internal sort
    input size < main memory size 일 때
    –> bubble, selection, insert, merge, quick, heap, shell, Tim, 기수정렬, 이중 피봇 퀵정렬
2. External sort
    input size > main memory size 일 때
    read from drive -> sort -> write to drive의 반복
    –> p-way Merge, Polyphase Merge

- stable of sort
~ 2_1, 2_2, ~ 처럼 중복되는 숫자가 있을 때
stable : 정렬 후 같은 숫자끼리의 순서가 지켜짐 ex| ~, 2_1, 2_2, ~
unstable : 안지켜짐 ex| ~, 2_2, 2_1, ~

- T.C
average T.C가 같더라도 input size에 따라 성능이 다를 수 있음

- lower bound of comparison sort problem
= O(nlogn)
비교 횟수의 하한이 있기 때문에
root/non-terminal/terminal node

n개의 숫자 정렬 시 decision tree
-> n!의 경우의 수 존재
-> 
 decision tree 형성 시 최소 logn의 높이(binary tree의 경우)로 형성됨.
root -> terminal node까지의 과정 = 정렬까지의 비교 과정 이므로
비교 횟수의 하한은 logn

### selection sort
- feature
최솟값 select -> (0 ~ n-1) index의 원소와 교환
swap횟수가 가장 적음
input insensitive : 항상 일정한 T.C

- pseudo code
for i in range(0~n-2)
    temp=i
    for j in range(i+1, n-1)
        if(A[j] < A[temp]) temp=j
    swap(A[i], A[temp])

- T.C : O(n^2)
selected element를 (n-1)+(n-2)+(n-3)+...+1 번 비교
-> (n-1)*n/2 = O(n^2)

### merge sort
- feature
합병 결과를 저장할 입력 크기만큼의 배열이 별도로 필요 -> 공간 복잡도 증가
분할 시 입력 크기가 1/2씩 줄어듦.
외부 정렬, 정렬의 병렬화 시 사용

- T.C : O(nlogn)
a. 더이상 분할하지 못할 때 까지 분할 시 k층 생성.
-> 마지막 층의 입력은 n/(2^k)
-> k = log_2_n
b. 각 층에서 합병 수행 시 O(n)
=> a*b = log_2_n x O(n) = O(nlogn)

### quick sort
- feature
pivot 왼/오른쪽에 작은/큰 수 배치
-> pivot 선정하고
-> 배열의 끝으로 이동(주로 왼쪽)
-> 양 끝 인덱스에서 시작해서 수를 비교해가며 정렬
-> 교차 시 종료. pivot 복귀

- pivot 선정 방법 & T.C
always start
    (n-1)+(n-2)+(n-3)+...+1
    = (n-1)*n/2 
    = O(n^2)
random
    divide -> 2^k층 생성
    한 층 당 연산 O(n)
    = O(nlogn)  //average T.C
median of three
    best : 전체 수 중 중앙값 선택 = O(nlogn)
    worst : 전체 수 중 두 번째로 작은 값 선택(제일 작은 값이 meidan으로 선정될 수 없음) = O(n^2)
median of median
    best : O(nlogn)
    worst : 총 (n-1)/4번 분할 -> O(n^2) //사진 참고
    ![alt text](../images/image-5.png)

- with insertion sort
성능 향상 방법. quick sort는 입력크기가 클 때 성능 좋음
sub problem의 크기가 작을 시 insertion sort 수행

### bubble sort
- feature
세로로 보았을 때, 큰 수가 가라앉고 작은 수가 떠오르는 양상을 보임
pass : 시행횟수(round)

- pseudo code
create A[n]
for pass in range(1, n-1)
    for i in range(1,n-pass)
        if(A[i-1] > A[i]) swap(A[i-1],A[i])

- T.C
a. pass for문 : O(n-1)
b. 비교 loop문 : O(n-1)
c. swap : O(1)
=> a*(b+c)=O(n^2)
=> 또는 등차수열 n(n-1)/2 = O(n^2)

### insertion sort
- feature
앞부분(정렬되어있음)과 뒷부분(원래 상태)으로 나눈다.
뒷부분의 element를 앞부분에 insertion하여 앞부분을 점점 키워나감
단, insertion 수행 후 정렬된 상태여야 함.
거의 정렬된 입력 & 입력의 크기가 작을 때 아주 빠름

- pseudo code
create A[n]
for i in range(1, n-1)
    selected=A[i]   //not sorted 부분의 가장 왼쪽 원소
    for j in range(i-1, 0)  //처음 j=0 -> 아무 연산x
        if(A[j] < selected) break   //비교할 숫자가 작으면 stop
        else A[j+1]=A[j]     //아닐 경우 move to right
    A[j+1]=selected     //insert

- T.C
a. for loop : O(n-1)
b. for loop : 비교 횟수는 0 ~ n-2 사이. 최대 O(n)
c. insert : O(1)
=> a*(b+c)=O(n^2)

### shell sort
- feature
past insertion sort
insertion sort의 특성을 활용
small input size에 매우 좋음
Embedded system -> 각 그룹을 쓰레드에게 할당하여 정렬시킬 수 있어서 적합하다.

- 진행 과정
gap에 따른 group 형성 -> group 내에서 sort
gap == 1까지 줄여 가며 sort

- pseudo code
A[n]    //정렬할 배열
gap[g]=[gap1, gap2, ..., 1]     //간격의 array
for i in range(1, g-1)      //gap을 줄여 가며 정렬 진행
    for j in range(g[i], n-1)       //각 gap에 의해 구성된 group 내에서 정렬 진행
        temp=A[j]
        k=j
        while (k >= g[i]) and (A[k - g[i]] > temp)
            A[k] = A[k-g[i]]
            k = k - g[i]
        A[k] = temp

### heap sort
max heap
오름차순 정렬



other sort : memeory에 순차적 access
heap sort -> page fault


### radix sort
각 radix(숫자의 자릿수)에 대한 정렬

- LSD sort
Least Significant Digit sort
= Right to Left sort
stable sort를 써야만 정렬이 수행됨

- MSD sort
Most Significant Digit sort
= Left to Right sort
MSD를 우선 정렬 후 같은 수 끼리 grouping 후 정렬
마지막 radix는 이미 정렬되어있게 되므로 정렬수행 필요 x

일정한 자릿수 범위 안에 모여있는 데이터인 경우(전번 등) 효과적
MSD의 경우 병렬화로 효과적인 수행 가능

### External sort
read : 지정된 크기만큼만 read
sort : read한 데이터를 sort
write : sort할 데이터 영역과 다른 영역에 sort한 block 저장
-> 정렬된 각 data blocks가 혼재되어있는 데이터 영역이 존재하게 됨
=> 두 block에서 데이터를 하나씩 읽어와서 또다른 데이터 영역에 merge해가며 sort

- T.C
비교 연산 시간보다 read 시간이 압도적으로 기므로 read/write횟수와 속도를 최대한 줄여야 함

- 진행 과정
if memory = 1GB, data = 31GB,
1GB * 31개
1 pass -> 2GB * 15 / 1GB * 1
2 pass -> 4GB * 7 / 3GB * 1
3 pass -> 8GB * 3 / 7GB * 1
4 pass -> 16GB * 1 / 15GB * 1
5 pass -> 31 GB * 1
=> log(31/1) = log(31)의 올림
왜? 위처럼 남는 조각이 생성되어서 1pass가 더 실행되므로

### 2way merge


file system의 rewind -> tape를 젤 앞으로
lseek() -> disk

formal한 식
block 수가 2^k일 때 log(N/M)
block 수가 2^k+1일 때 log(N/M)+1


### Multi way merge
테이프 갯수가 l일 때
1번 실행 -> l/3
2번 실행 -> l/3^2
k번 실행 -> l/3^k = 1
k=log_3(l)

### polyphase merge
