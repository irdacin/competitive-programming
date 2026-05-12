MAXN = 5000
catalan = [0] * (MAXN + 1)

catalan[0] = catalan[1] = 1
for i in range(1, MAXN + 1):
    catalan[i] = catalan[i - 1] * (4 * i - 2) // (i + 1)

for i in range(int(input())):
    print(catalan[int(input())])