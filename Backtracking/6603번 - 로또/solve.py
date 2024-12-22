from itertools import combinations


def func(arr):
    for i in arr:
        c_lst=list(combinations(i[1:],6))
        # print(c_lst)
        for j in c_lst:
            print(' '.join(map(str, j)))
        print()

arr=[]
while True:
    lst=list(map(int,input().split()))
    if lst[0]==0:
        break
    arr.append(lst)

func(arr)
