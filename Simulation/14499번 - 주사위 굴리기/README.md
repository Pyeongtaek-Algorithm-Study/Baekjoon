### 14499번: 주사위 굴리기

문제 사이트 : [바로가기](https://www.acmicpc.net/problem/14499)

**문제 조건**
- 크기가 N x M 인 지도가 존재, 이 지도 위에는 주사위가 놓아져 있다.
- 초기 주사위는 모든 면이 0으로 설정되어 있으며, 주사위가 놓아져 있는 위치에 따라 2가지 방식이 있다.
    1. 주사위가 이동한 칸에 쓰여 있는 수가 0이면, 주사위의 바닥면에 적혀 있는 수가 지도로 복사
    2. 주사위가 이동한 칸에 0이 아닌 수라면, 주사위의 바닥면에는 이동한 칸의 숫자가 복사
- 주사위는 지도 바깥으로 이동할 수 없기에, 주사위가 이동한 칸이 지도 바깥이면 명령을 무시
- 입력 값 
    - 지도의 세로 크기 `N`, 가로 크기 `M`
    - 주사위의 놓는 좌표 `x`, `y` _( ※ 이 문제에서의 x 값은 지도의 세로, y 값은 지도의 가로를 의미, 일반적인 x와 y가 반대로 적용됨)_
    - 명령의 개수 `k`
    - 지도에 적혀있는 수
    - 주사위가 이동할 명령(동쪽 `1`, 서쪽 `2`, 북쪽 `3`, 남쪽 `4`)

**출력**  
- 주사위를 놓은 곳의 좌표와 이동시키는 명령이 주어졌을 때, 주사위가 이동할 때 마다 상단에 쓰여있는 숫자를 출력

### 풀이
1. `can_move()` 함수를 생성하여 주사위가 지도 바깥으로 가는지 확인하여 명령을 수행할지 안할지를 결정
    - 다음으로 이동할 칸을 `nx`, `ny`로 설정하여 이동 명령에 따라 지도 바깥으로 가는지 확인
2. **`roll_dice()` 함수를 통해 `vector<int> dice(6)`의 전개도 - (윗면, 아랫면, 상, 하, 좌, 우) 값으로 설정**
3. 주사위가 이동했으므로, 이동한 칸의 수가 0이면 주사위 아랫면을 지도에 복사하고, 수가 0이 아니면은 주사위 아랫면에 복사
4. 주사위의 윗면의 수를 출력하여 `k`개의 명령만큼 반복

### 핵심 코드
```
bool can_move(int order) {
    int nx = x;
    int ny = y;
    switch(order) {
        case 1:
            ny++;
            break;
        case 2:
            ny--;
            break;
        case 3:
            nx--;
            break;
        case 4:
            nx++;
            break;
    }
    if (nx < 0 || nx >= n || ny < 0 || ny >= m) return false;
    else {
        x = nx;
        y = ny;
        return true;
    }
}

```
- `switch`문을 이용하여 주사위 명령 이동인 `order`를 입력받아 `nx`, `ny`로 명령으로 이동할 칸을 저장
- 이동한 칸이 지도 바깥을 벗어나는지 확인

```
void roll_dice(int order) {
    // Copy the dice array to the tmp_dice array
    vector<int> tmp_dice = dice;
    
    switch(order) {
        case 1:
            dice[0] = tmp_dice[4]; // left -> top
            dice[1] = tmp_dice[5]; // right -> bottom
            dice[4] = tmp_dice[1]; // bottom -> left
            dice[5] = tmp_dice[0]; // top -> right
            break;
        case 2:
            dice[0] = tmp_dice[5]; // right -> top
            dice[1] = tmp_dice[4]; // left -> bottom
            dice[4] = tmp_dice[0]; // top -> left
            dice[5] = tmp_dice[1]; // bottom -> right
            break;
        case 3:
            dice[0] = tmp_dice[3]; // down -> top
            dice[1] = tmp_dice[2]; // up -> bottom
            dice[2] = tmp_dice[0]; // top -> up
            dice[3] = tmp_dice[1]; // bottom -> down
            break;
        case 4:
            dice[0] = tmp_dice[2]; // up -> top
            dice[1] = tmp_dice[3]; // down -> bottom
            dice[2] = tmp_dice[1]; // bottom -> up
            dice[3] = tmp_dice[0]; // top -> down
            break;
    }
}
```
- `vector<int> tmp_dice`에 `dice`를 임시 저장
- `switch`문을 활용하여 입력받은 `order` 명령으로 주사위가 이동하고 난 뒤의 값을 저장
- **주사위의 이동**
    - **동쪽 이동** : 좌 -> 윗면, 윗면 -> 우, 우 -> 아랫면, 아랫면 -> 좌
    - **서쪽 이동** : 우 -> 윗면, 윗면 -> 좌, 좌 -> 아랫면, 아랫면 -> 우
    - **북쪽 이동** : 하 -> 윗면, 윗면 -> 상, 상 -> 아랫면, 아랫면 -> 하 
    - **남쪽 이동** : 상 -> 윗면, 윗면 -> 하, 하 -> 아랫면, 아랫면 -> 상