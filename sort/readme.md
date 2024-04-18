### selection sort
- T.C : O(n^2)
selected element를 (n-1)+(n-2)+(n-3)+...+1 번 비교
-> (n-1)*n/2 = O(n^2)

### merge sort
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

- pivot 선정 방법
random
median of three
median of median

- T.C : TC
최악 : pivot이 항상 작을 때. 
(n-1)+(n-2)+(n-3)+…+2+1 = n(n-1)/2 = O(n^2)
최선 : like merge sort. O(nlogn)

- with insertion sort
성능 향상 방법. quick sort는 입력크기가 클 때 성능 좋음
sub problem의 크기가 작을 시 insertion sort 수행

### bubble sort

### insert sort

