def count_long_subarray(A):
    '''
    Input:  A     | Python Tuple of positive integers
    Output: count | number of longest increasing subarrays of A
    '''
    count = 0
    i = 0
    j = 0
    maxlength = 0
    n = len(A)
    
    while j < n:
      while j < n - 1 and A[j + 1] > A[j]:
        j += 1
        
      length = j - i + 1
      if length > maxlength:
        maxlength = length
        count = 1
      elif length == maxlength:
        count += 1
      
      j += 1
      i = j
    
    return count
