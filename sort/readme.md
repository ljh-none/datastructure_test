### selection sort
1. time complexity : O(n^2)
(n-1)+(n-2)+(n-3)+...+1 번 비교
-> (n-1)*n/2

### merge sort
1. time complexity : O(nlogn)
문제 분할 시 마다 부분문제로 이루어진 층이 하나 생긴다.
더이상 분할하지 못할 때 까지 수행하면 k개의 층이 생긴다.
입력이 n인 문제는 분할 때마다 반씩 줄어듦 
-> 마지막 층의 입력은 n/(2^k)
-> 총 log_2_n개의 층
각 층에서 합병 수행 시 O(n)만큼의 시간이 든다.
그러므로 총 수행 시간은 log_2_n x O(n) = O(nlogn)
2. 특징
합병 결과를 저장할 입력 크기만큼의 배열이 별도로 필요 -> 공간 복잡도 증가
외부 정렬, 정렬의 병렬화 시 사용

### quick sort
1. TC
최악 : pivot이 항상 작을 때. 
(n-1)+(n-2)+(n-3)+…+2+1 = n(n-1)/2 = O(n^2)
최선 : like merge sort. O(nlogn)
2. feature
pivot 왼/오른쪽에 작은/큰 수 배치
-> pivot 선정하고
-> 배열의 끝으로 이동(주로 왼쪽)
-> 양 끝 인덱스에서 시작해서 수를 비교해가며 정렬
-> 교차 시 종료. pivot 복귀
3. pivot 선정 방법
random
median of three
median of median
4. with insertion sort
성능 향상 방법. quick sort는 입력크기가 클 때 성능 좋음
sub problem의 크기가 작을 시 insertion sort 수행

### bubble sort

### insert sort

