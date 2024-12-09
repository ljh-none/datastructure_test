# weight rule이 적용된 union 연산
def do_union(a,  b):
        # 각 집합의 root node를 찾는다
        while ary[a] >= 0:
            a = ary[a]
        while ary[b] >= 0:
            b = ary[b]
        
        # 두 집합이 같은 root를 가지고 있으면 같은 집합이므로 return
        if a == b:
            return
        
        # 두 집합 중 원소가 적은 집합이 많은 집합의 자식으로 들어간다
        temp = ary[a] + ary[b]
        if -ary[a] < -ary[b]:
            ary[a] = b
            ary[b] = temp
        else:
            ary[b] = a
            ary[a] = temp

# 간단한 find 연산
def do_find(i):
    #root node를 찾아 리턴
    while ary[i] >= 0:
        i = ary[i]
    return i

# main
std_input = input() #첫 입력 받기
buf = std_input.split() #입력받은 문자열 처리
n = int(buf[0])
m = int(buf[1])

# 트리를 나타내는 배열 초기화
ary = [-1] * (n+1)

# m번 입력받는다
for i in range(m):
    std_input = input() # 입력 받기
    buf = std_input.split() #문자열 처리
    inst = int(buf[0])
    a = int(buf[1])
    b = int(buf[2])

    # 인덱스 범위 체크
    if a < 0 or a > n or b < 0 or b > n:
        continue

    if inst == 0:
        # union 연산
        do_union(a, b)
    elif inst == 1:
        # find 연산
        temp_a = do_find(a)
        temp_b = do_find(b)
        # find 연산의 결과는 root 노드의 값. 
        # 이 두 값이 같으면 같은 집합 내에 있음.
        if temp_a == temp_b:
            print("YES")
        else:
            print("NO")
    else:
        continue
