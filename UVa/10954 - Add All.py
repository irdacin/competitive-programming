import heapq

while True:
    n = int(input())
    if(n==0): break

    pq = list(map(int, input().split()))
    heapq.heapify(pq)

    ans = 0
    while(len(pq)>1):
        a = heapq.heappop(pq)
        b = heapq.heappop(pq)

        ans += (a+b)
        heapq.heappush(pq, a+b)
    
    print(ans)