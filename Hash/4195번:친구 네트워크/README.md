# 4195번: 친구네트워크
### 문제해설
* 민혁이는 소셜 네트워크 사이트에서 친구 관계가 생긴 순서대로 주어졌을 때, 각각의 친구 네트워크에 몇 명이 있는지를 구하는 프로그램을 작성하려고 합니다.<br>
여기서 "친구 네트워크"는 서로 친구 관계인 사용자들이 이동할 수 있는 그룹을 말합니다. 각각의 그룹에 속한 사용자 수를 찾는 것이 목표입니다.
* * *
### 풀이과정
* 해시 알고리즘이라 딕셔너리에 [친구]: [속한 친구 리스트] 이런식으로 저장을 해줘야된다고 생각을 하였다.<br>
그런데, 메모리도 그렇고, 코드도 복잡해지고, 구현이 잘 안되어서 구글링을 해봤더니 union-find 알고리즘을 써야된다고 하였다<br>
우선 유니온-파인드 알고리즘이란 서로소 집합(disjoint set)을 효율적으로 다루기 위한 자료구조와 관련된 알고리즘이다.<br>
간단히 말하자면 유니온 파인드는 그래프 알고리즘으로 두 노드가 같은 그래프에 속하는지 판별하는 알고리즘이다.<br>
노드를 합치는 Union연산과 노드의 루트 노드를 찾는 Find연산으로 이루어진다.<br>
이 유니온 파인드 알고리즘을 활용하여 코드를 구현하였는데, 이를 설명하자면<br>
우선 find코드에 대해 설명을 하겠다<br>
<pre>
  <code>
    def find(x):
    if parent[x] != x:
        parent[x] = find(parent[x])
    return parent[x]
  </code>
</pre>
parent[x]=x로 메인에 원래 초기화를 해주었다. 만약 x가 아니면 parent[x]에 대한 parent값을 찾아 뿌리를 찾아주는 방식이다.<br>
union 코드에 대해 설명을 하겠다<br>
<pre>
  <code>
    def union(a, b):
    a = find(a)
    b = find(b)

    if a != b:
        parent[b] = a
        number[a] += number[b]
    print(number[a])
  </code>
</pre>
find함수로 부터 parent[a]값을 찾아 root값을 구해준다.<br>
이제 a,b 두개가 root값이 다르다면 parent[b]=a로 b의 뿌리를 a로 바꾼다음 서로 집합을 만들어준다.<br>
그리고 number[a]에 numner[b]를 더해준다음, 명수를 count해준다.
### 코드
<pre>
<code>
from sys import stdin

input = stdin.readline

def find(x):
    if parent[x] != x:
        parent[x] = find(parent[x])
    return parent[x]


def union(a, b):
    a = find(a)
    b = find(b)

    if a != b:
        parent[b] = a
        number[a] += number[b]
    print(number[a])


for _ in range(int(input())):
    num = int(input())
    parent, number = {}, {}
    for i in range(num):
        a, b = input().split()
        if a not in parent:
            parent[a] = a
            number[a] = 1
        if b not in parent:
            parent[b] =b
            number[b] = 1
        union(a, b)
</code>
</pre>

### 링크
<https://www.acmicpc.net/problem/4195>
