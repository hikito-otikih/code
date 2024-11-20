[n, p, k] = [int(x) for x in input().split()]
a = [int(x) for x in input().split()]

a.sort()
Map = {}

Count = 0

for i in range(n):
    j = i
    while j + 1 < n and a[i] == a[j + 1]:
        j += 1
    x = (a[i] ** 4) - a[i] * k
    x %= p
    if x < 0:
        x += p
    if x in Map:
        Count += Map[x]
    if x not in Map:
        Map[x] = 0
    Map[x] += (j - i + 1); 
    if 2 * a[i] * (2 * (a[i] ** 2)) % p == k:
        Count += (j - i + 1) * (j - i) // 2 
    i = j

print(Count)