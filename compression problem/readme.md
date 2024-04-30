### Huffman compression
- ASCII code : 문자 하나 당 8bit

- solution
문자 별 빈도수 산출
-> 빈번한 문자 - 짧은 이진코드
-> 드문 문자 - 긴 이진 코드
-> 고정 크기 문자 - ASCII code 

- 문제점
글자가 같을 경우 - 글자구분가능
다를경우 - 어디서부터 어디까지가 문자 하나인지 구분 불가능

- prefix property
각 문자에 할당된 이진 코드는 어떤 다른 문자에 할당된 이진 코드의 prefix가되지 않는다.
-> code 구분자 없이 huffman tree를 사용
Ex | a = 101 -> b가 가질 수 없는 binary code : 1, 10, 101, 101~~~

- Huffman tree
문자 별 빈도수 트리를 생성하여 이를 기반으로 각 문자에 binary code 할당
"해당 코드로 압축한 파일"과 "문자 별 빈도수"를 송신
-> 수신측에서도 Huffman tree 생성 후 압축해제

- 과정
1. 빈도수 node 생성
2. 우선순위 Queue 생성 후 node 삽입(정렬 리스트도 가능)
while (length of queue > 1)
    3. 빈도수가 가장 적은 node 2개 추출
    4. 이를 자식으로 둔 parent node 생성. 빈도수는 두 node의 합
    5. parent node를 enqueue
![alt text](image.png)

- 압축률
빈도수 * binary code의 bit수

- T.C
a. node 생성 O(n)
b. queue에 입력 O(n)
c. while loop O(n-1)
d. queue의 삭제&삽입 연산 O(logn)   (heap의 삭제&삽입 연산의 T.C)
-> a+b+c*d = O(n)+O(nlogn) = O(nlogn)

