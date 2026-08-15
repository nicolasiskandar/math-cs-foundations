def short_company(C, P, n, k):
    '''
    Input:  C | Tuple of s = |C| strings representing names of companies
            P | Tuple of s lists each of size nk representing prices
            n | Number of days of price information
            k | Number of prices in one day
    Output: c | Name of a company with highest shorting value
            S | List containing a longest subsequence of 
              | decreasing prices from c that doesn't skip days
    '''

    S = []
    for i in range(len(C)):
        p = P[i]
        x = [1 for _ in range(n*k)]
        r = [None for _ in range(n*k)]
        best = 0
        for j in range(n*k - 1, -1, -1):
            f = min(j + (k - 1) - (j % k) + k, n*k - 1)
            for d in range(j + 1, f + 1):
                if (p[j] > p[d]) and (1 + x[d] > x[j]):
                    x[j] = 1 + x[d]
                    r[j] = d
            if x[best] < x[j]:
                best = j
        if x[best] > len(S):
            c, S = C[i], []
            while best != None:
                S.append(p[best])
                best = r[best]
            S = tuple(S)
    return (c, S)
