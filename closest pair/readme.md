# closest pair
input : 2차원 평면 상 n개의 점

- simple solution : 모든 경우의 수
O(nC2) = O(n^2)

- divide & conquer
x좌표 오름차순 정렬 기준, 두 영역으로 분할.
단, 좌표 기준으로 분할하므로(x축 상의 범위로 분할하지 않음) 중간 영역의 고려가 필요

- 중간계 비교 시 고려사항
1. 선택한 점의 반대 영역의 좌표와만 비교 (원래 영역은 이미 수행했으므로)
2. y좌표를 오름차순으로 정렬 후 그 값이 작은 좌표부터 비교 시, y값이 큰 점끼리만 비교
3. 2번에서, 최단 distance를 계산하여 cache하면, y+d 또는 x+d 내의 점에서만 비교를 수행하여서 연산 횟수를 더 줄일 수 있다.

- pseudo code
x_sort_array
y_sort_array

find_closest_pair(x_sort_array)
    if(number of point <= 3) 
        return pair     //closest pair 좌표 return
    left_pair = find_closest_pair(x_sort_array/2)     //왼쪽 반절
    right_pair = find_closest_pair(x_sort_array/2)    //오른쪽 반절
    distance = min(left_pair, right_pair)
    middle_pair = find_pair_on_middle_area(distance)
    return pair     //세 pair 중 distance가 가장 작은 pair

find_pair_on_middle_area(distance)
for pair in y_sorted_array
    for y in range(y, y+distance)
        if find min distance on range
            cache pair
return pair

- T.C
a. x, y축 정렬 : O(nlogn) * 2
b. 분할 과정으로 k개의 층 생성. k=logn  (input == n개의 point)
c. 이 때, 각 층에서의 연산 : O(n)
    c-1. pair 수가 3개 이하일 경우 closest pair 계산 -> O(3)    // 상수
    c-2. 중간 영역에서 closest pair 계산 -> 상수 ~ O(n)         //최악의 경우 n개
=> a+b*c = O(nlogn)     //상수, 계수 제하였다.

최초로 y-좌표로 정렬하기 위해 O(n log n)이 소모되지만,
이후에는 [분할에 O(n)만 추가되고] y-좌표로 정렬할 필요가 없어지므로 각 층의 수행시간은 O(n)이 된다. 
층 개수가 log n이므로 분할 정복에 사용되는 시간복잡도는 O(n log n)이 된다. 
정렬시간과 통합하면 전체 시간복잡도는 O(n log n)으로 동일하다.