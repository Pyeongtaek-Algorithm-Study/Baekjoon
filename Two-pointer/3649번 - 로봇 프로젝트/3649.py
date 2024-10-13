while True:
    try:
        x = int(input()) * 10000000
        n = int(input())
        lego = [int(input()) for _ in range(n)]
        lego.sort()
        st, en = 0, n - 1
        while st < en:
            f = lego[st] + lego[en]
            if f == x:
                break
            elif f > x:
                en -= 1
            else:
                st += 1
        if st < en:
            print(f'yes {lego[st]} {lego[en]}')
        else:
            print('danger')
            
    except:
        break