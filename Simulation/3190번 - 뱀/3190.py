import sys
from collections import deque

input = sys.stdin.readline

def show_board():
    for i in range(n + 1):
        for j in range(n + 1):
            print(board[i][j], end=' ')
        print()
    print()

def solve(board, apple, moves):
    dd = [[0, 1], [1, 0], [0, -1], [-1, 0]]
    snake = deque()
    sec = 0
    s_x, s_y = 1, 1
    s_d = 0
    board[s_x][s_y] = 1
    snake.append((s_x, s_y))
    
    while True:
        sec += 1
        
        s_x += dd[s_d][0]
        s_y += dd[s_d][1]
        
        if s_x <= 0 or s_x > n or s_y <= 0 or s_y > n or board[s_x][s_y]:
            break
        
        snake.append((s_x, s_y))
        board[s_x][s_y] = 1
        if apple[s_x][s_y]:
            apple[s_x][s_y] = False
        else:
            tmp_x, tmp_y = snake.popleft()
            board[tmp_x][tmp_y] = 0
            
        # show_board()
        
        if moves and sec == moves[0][0]:
            turn = moves[0][1]
            moves.popleft()
            s_d = (s_d + turn + 4) % 4
    
    print(sec)

if __name__ == '__main__':
    n = int(input())
    board = [[0] * (n + 1) for _ in range(n + 1)]
    k = int(input())
    apple = [[False] * (n + 1) for _ in range(n + 1)]
    for _ in range(k):
        a, b = map(int, input().split())
        apple[a][b] = True
    l = int(input())
    moves = deque()
    for _ in range(l):
        a, b = input().split()
        moves.append((int(a), 1 if b == 'D' else -1))

    solve(board, apple, moves)