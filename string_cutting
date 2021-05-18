def minCost(c,minimum_cost, p, min_pos):
    if c < minimum_cost:
        return c,p
    else:
        return minimum_cost, min_pos

def cutstr(n, m):
    if len(m) == 0:
        return [0, []]
        
    pos_min = []
    cost_min = n*(n+1)/2 + 1
    for c in m:
        l_cut = [cut_pos for cut_pos in m if cut_pos < c]
        r_cut = [cut_pos - c for cut_pos in m if cut_pos > c]
        
        cost_lcut = cutstr(c, l_cut)
        remain_size = n - c
        cost_rcut = cutstr(remain_size, r_cut)
        
        print('n=',n)
        print('c=',c)
        print('l side=',l_cut)
        print('r side=', r_cut)
        print('l cost: ',cost_lcut)
        print('r cost: ',cost_rcut)
        print()
        
        final_cost = n + cost_lcut[0] + cost_rcut[0]
        final_pos = [c] + cost_lcut[1] + [cut_pos + c for cut_pos in cost_rcut[1]]
        
        cost_min, pos_min = minCost(final_cost, cost_min, final_pos, pos_min)
        
    return (cost_min, pos_min)
        
        
#print(cutstr(20,[3,10,16]))  # (40, [10, 3, 16])

print(cutstr(20,[3,10])) # (30, [10, 3])

#print(cutstr(5,[1,2,3,4,5])) # (13, [2, 1, 3, 4, 5])

#print(cutstr(1,[1])) # (1, [1])
