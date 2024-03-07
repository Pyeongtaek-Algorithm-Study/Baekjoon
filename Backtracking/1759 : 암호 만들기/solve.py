# L 개의 알파벳 소문자로 구성
# 최소 한 개의 모음 (a, e, i, o, u)
# 최소 두 개의 자음으로 구성
# 암호 문자 정렬
# C 개의 문자 종류로 가능성 있는 암호들을 모두 출력

import sys

input = sys.stdin.readline

# L = 암호의 글자 수, C = 추측 문자 종류 수
L, C = map(int ,input().split())

pw = list(map(str, input().split()))

ex1 = ['a', 'e', 'i', 'o', 'u']
ex2 = ['b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n', 'p', 'q', 'r', 's', 't', 'v', 'x', 'z', 'w', 'y']
ex2.sort()

result = []

temp = []

def insertResult() :
    global temp, result

    temp.sort()

    word = ''.join(temp)

    # 모음 최소 1개 자음 최소 2개를 포함하는지 조건 확인
    ex1Count = sum(1 for i in temp if i in ex1)
    ex2Count = sum(1 for i in temp if i in ex2)

    # 조건에 만족하면 결과 리스트에 추가
    if ex1Count >= 1 and ex2Count >= 2 :
        result.append(word)
    
# start 와 count 를 파라미터로 받아 문자를 두 번 선택하는 경우를 방지
def chooseWord(start, count) :
    global temp

    # 한정 조건
    if count == L :

        # 결과에 추가할 조건을 확인하고 추가하는 함수 호출
        insertResult()

        return
    
    for i in range(start, C) :
        temp.append(pw[i])
        
        # 재귀 호출
        chooseWord(i + 1, count + 1)

        # 마지막으로 추가한 요소를 제거
        temp.pop()

pw.sort()
chooseWord(0, 0)
print('\n'.join(result))
