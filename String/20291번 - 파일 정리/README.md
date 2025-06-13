### 20291번: 파일 정리

1. **문제 사이트** : [바로가기](https://www.acmicpc.net/problem/20291)
2. **도움 블로그** : 

**문제 조건**
- 중고 노트북의 바탕화면에 온갖 파일들이 정리가 안되어 있음.
- 보물의 절반의 보상으로 파일의 정리를 요청
    - 파일을 확장자 별로 정리해서 몇 개씩 있는지 알기
    - 확장자들을 **사전 순**으로 정렬

**출력**  
- 확장자의 이름과 그 확장자 파일의 개수를 각 줄에 출력
- 확장자가 여러 개 있는 경우 **확장자 이름을 사전순**으로 출력

### 풀이
1. 각 입력 값에서 .의 위치를 뒷 부분부터의 문자열을 따로 저장
2. _Map_ 자료형(오름차순)으로 해당 확장자를 _Key_ 로 값이 있는지 확인
3. 값이 있으면 1을 증가, 없으면은 _Value_ 값을 1로 저장
4. 위 과정을 모든 파일명에 적용
5. 최종적으로 구한 Map에서 확장자명인 _Key_ 와 개수인 _Value_ 를 출력

### 핵심 코드

<details>
<summary>코드 보기</summary>

```cpp
void solve() {
    for(string &file : files) {
        // solve_1
        // vector<string> split_str = split(file, '.');
        
        // // 확장자를 따로 저장한다.
        // string ext = split_str[1];
        
        // solve_2
        string ext = file.substr(file.find('.') + 1);
        
        
        if(ext_cnt.find(ext) != ext_cnt.end()) {
            ext_cnt[ext]++;
        }
        else {
            ext_cnt.insert({ext, 1});
        }
    }
    
    for(auto &[ext_w, ext_c] : ext_cnt) {
        cout << ext_w << ' ' << ext_c << '\n';
    }
}
```
- 반복문을 통해 파일명이 들어있는 `files`에서 문자열 `file`로 추출
- 확장자인 `ext`로 `file` 문자열에서 . 위치에서 +1 한 위치부터 문자열을 자르면 확장자 문자열만 구할 수 있음
- _Map_의 `Key`에 `ext`값이 없을 때는 개수를 1로 넣고, 있으면은 개수를 1증가
- 위 과정을 모든 파일을 기준으로 해서 `ext_cnt`에 저장되어 있는 확장자명, 개수를 각각 출력
</details>

### 후기
- 처음에는 `split()` 함수를 구현해서 했지만, `substr()`을 이용하는 것이 속도적으로 더 좋았음.