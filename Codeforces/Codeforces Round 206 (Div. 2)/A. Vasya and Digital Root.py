def digitRoot(num):
    sum = 0
    while(num!=0):
        sum+=num%10
        num//=10
    if(num<10):
        return sum
    else:
        return digitRoot(sum)

a = input().split()
k,d = a
k = int(k)
d = int(d)

if(d==0):
    if(k==1):
        print(0)
    else:
        print("No solution")

else:
    for i in range(10**(k-1),10**k):
        temp = digitRoot(i)
        if(temp==d):
            break
    print(i)