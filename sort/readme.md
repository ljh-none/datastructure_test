# Sort
- Internal sort
input size < main memory size 일 때
–> 버블 정렬, 선택 정렬, 삽입 정렬, 합병 정렬, 퀵 정렬, 힙 정렬, 쉘 정렬, 기수정렬, 이중 피봇 퀵정렬, Tim sort

- External sort
input size > main memory size 일 때
read from drive -> sort -> write to drive의 반복
–> 다방향 합병(p-way Merge), 다단계 합병(Polyphase Merge)

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
    ![alt text](image.png)

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
거의 정렬된 입력 & 입력의 크기가 작을 때 good

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
