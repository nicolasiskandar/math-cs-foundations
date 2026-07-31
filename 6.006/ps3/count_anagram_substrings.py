ORD_A = ord('a')


def lower_ord(c):
    return ord(c) - ORD_A


def count_anagram_substrings(T, S):
    '''
    Input:  T | String
            S | Tuple of strings S_i of equal length k < |T|
    Output: A | Tuple of integers a_i:
              | the anagram substring count of S_i in T
    '''
    m, n, k = len(T), len(S), len(S[0])
    D = {}
    F = [0] * 26
    for i in range(m):
        F[lower_ord(T[i])] += 1
        if i > k - 1:
            F[lower_ord(T[i - k])] -= 1
        if i >= k - 1:
            key = tuple(F)
            if key in D:
                D[key] += 1
            else:
                D[key] = 1

    A = [0] * n
    for i in range(n):
        F = [0] * 26
        for c in S[i]:
            F[lower_ord(c)] += 1
        key = tuple(F)
        if key in D:
            A[i] = D[key]

    return tuple(A)
