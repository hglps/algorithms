# How to cut a rod of size n to obtain max selling price?
# p : prices of different sizes n of rod/stem
# n : sizes of rod/stem

def dyn_prog_haste(p, n):
    r=[0]
    s=[0]
    for i in range(1,n+1):
        r.append(-1)
        s.append(-1)
    r[0] = 0
    
    for i in range(1,n+1):
        for j in range(1, i+1):
            if r[i] < p[j]+r[i-j]:
                r[i] = max(r[i], p[j]+r[i-j])
                s[i] = j
    
    print('r = ',r)
    print('s = ',s)
    return r[n], r, s

p = [0, 1, 5, 8, 9, 10]

result, r, s = dyn_prog_haste(p,len(p)-1) 
print(result)

def sizes(s, n):
    if s[n] == n:
        print('haste size: ', n)
    else:
        print('haste size:', s[n])
        sizes(s, n-s[n])

sizes(s, 5)
