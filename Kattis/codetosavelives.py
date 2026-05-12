for _ in range(int(input())):
    n = list(map(int,input().split()));
    m = list(map(int,input().split()));

    num1 = 0
    for num in n:
        num1 = num1*10 + num

    num2 = 0
    for num in m:
        num2 = num2*10 + num

    res = num1+num2
    print(' '.join(str(res)))