# 4358 : 생태학
---
## 풀이과정

1. 나무가 더이상 입력되지 않을 때 까지 while 반복문을 통해서 입력받고 입력받는다.
2. 딕셔너리에 key : 나무의 종류 value : 나무의 수 저장
3. 나무의 종류를 입력받을 때 마다 전체 나무의 수를 증가시킨다.
4. 딕셔너리에서 key 값만 추출하여 사전 순으로 정렬해 리스트화
5. 리스트를 반복문으로 돌며 딕셔너리에서 value 값을 추출해 퍼센트를 계산한 뒤 출력

## 코드

```python
import sys

input = sys.stdin.readline

# 나무 종류와 나무 갯수를 넣을 딕셔너리
hashMap = {}

# 총 나무의 수
total = 0

# 나무가 입력되지 않을 때 까지 반복
while True :
    tree = str(input().rstrip())

    # 나무가 입력되지 않았다면 종료
    if not tree :
        break

    # 나무 딕셔너리에 입력된 key 값이 있다면 value += 1
    if tree in hashMap :
        hashMap[tree] += 1
    # 나무 딕셔너리에 입력된 key 값이 없다면 value = 1
    else :
        hashMap[tree] = 1

    # 총 나무의 수 계산
    total += 1

# 나무의 종류를 리스트에 넣고 사전 순으로 정렬
trees = list(hashMap.keys())
trees.sort()

# 사전 순으로 정렬된 나무의 종류와 나무 딕셔너리를 비교하여 퍼센트를 계산
for i in trees :
    tree_count = hashMap[i]
    percent = (tree_count / total * 100)

    # round() 함수의 경우 반올림을 하지 않고 버림을 하기에 float 로 십진 소수를 정확하게 표현
    print("%s %.4f" %(i, percent))
```

## 문제 링크
[백준 4358 : 생태학](https://www.acmicpc.net/problem/4358)
