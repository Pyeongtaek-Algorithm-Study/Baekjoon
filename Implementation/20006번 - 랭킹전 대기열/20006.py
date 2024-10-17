import sys

input = sys.stdin.readline

p, m = map(int, input().split())
players = []
for _ in range(p):
    level, name = input().split()
    level = int(level)
    players.append([level, name])
    
def solution():
    cnt = 0
    room = [[] for _ in range(300)]
    for l, n in players:
        chk = True
        for i in range(cnt):
            max_level = room[i][0][0] + 10
            min_level = room[i][0][0] - 10
            if min_level <= l <= max_level and len(room[i]) < m:
                room[i].append([l, n])
                chk = False
                break
        if chk:
            room[cnt].append([l, n])
            cnt += 1
    
    for i in range(cnt):
        print('Started!' if len(room[i]) >= m else 'Waiting!')
        sorted_room = sorted(room[i], key=lambda x:x[1])
        for l, n in sorted_room:
            print(l, n)


if __name__ == '__main__':
    solution()
    pass