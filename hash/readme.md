# hash
데이터를 구조적으로 저장하는 기술
-> {key, value} 형태로 데이터 저장
hash function & hash table로 데이터 저장
-> h(key) = value
-> table, map, set, dic 등등으로 불림
O(1) 내에 특정 데이터 탐색 가능

### structure
1. hash function 
    h(x)    // x = key, 저장할 데이터
    collision을 최소화하도록 설계
2. hash code
    h(key)의 결과. 고유한 값을 가짐.
    보통 저장할 data structure의 index로 사용됨.
3. key, value
    h(key) = hash code
    table[hash code] = value
    => 그러나 일반적인 사용은 4번에 의해 table[key] = value 이다
4. hash table
    내부적으로 hash 기술을 사용하는 table.
    {key, value}의 집합.

### hash function
- 종류
분할 방법: 키 % 해시 테이블 크기
곱셈 방법: (키 * 상수) % 해시 테이블 크기
Universal Hashing: 충돌을 최소화하도록 설계된 해시 함수 패밀리

- 함수 설계 원칙
정의역인 key와 치역인 hash code의 일대일 대응
-> 모든 키 값에 대하여 일대일 대응이 이루어지기는 쉽지 않음, 다대일 대응이 될 수 있음

### collision
상기 이유 때문에 서로 다른 key에 대해 같은 hash code가 도출되는 상황

- Open addressing
충돌이 발생한 키 값을 테이블 내 다른 빈 공간(bucket)을 찾아서 저장하는 방법
주어진 키 값에 대한 해시 값에 일정한 상수를 더해서 다른 주소에 할당
-> 다른 해시 값에 대해서도 연속적으로 충돌이 발생하는 문제가 발생할 수 있음
    - Linear probing
    충돌이 발생한 위치에서 1씩 더하면서 할당할 위치를 지정 (𝑚은 해시 테이블의 최대 크기)
    h(k, i) = (h(k)+i) mode m
    - Quadratic probing
    충돌이 발생한 위치에서 제곱 수를 더하여 할당할 위치를 결정
    h(k, i) = (h(k) + i^2) mod m
    - Dobule probing
    충돌이 발생하는 경우 기존의 해시 함수와 다른 해시 함수를 사용
    h(k, i) = (h_1(k) + i*h_2(k)) mod m

체이닝(Chaining)
해시 값에 해당하는 위치에 다른 value가 포함되어 있다면, 해당 위치에 연결 리스트(linked-list)의 형태로 해당 value를 저장하는 방법
충돌이 발생한 위치에 많은 수의 value가 저장되어 있는 경우, 탐색에 소요되는 시간이 증가하는 문제점이 존재함

### use case
1) 문제의 해결 방법 과정에서 데이터를 일련의 키(key)와 값(value)의 쌍(pair)으로 표현할 수 있는 경우
2) “문자열”을 활용하여 데이터를 인덱싱하거나 검색해야 하는 경우, 특히, 문자열이 키(key)가 되고 각 문자열에 대한 값(value)들이 주어지는 경우
3) 특정 값이나 정보를 기준으로 빈번한 검색을 수행해야 하는 경우
4) 특정 정보와 매핑되는 값 사이의 관계를 확인해야 하는 경우