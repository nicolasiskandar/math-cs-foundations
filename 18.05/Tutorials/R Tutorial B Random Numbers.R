x = 1:5
print(x)
y = sample(x, 3)
print(y)
y = sample(x, 5)
print(y)
# y = sample(x, 6) # error

y = sample(x, 3, replace=TRUE)
print(y)
y = sample(x, 12, replace=TRUE)
print(y)

y = sample(1:6, 12, replace=TRUE)
z = matrix(y, nrow=3, ncol=4)
print(z)
z = matrix(y, nrow=2, ncol=6)
print(z)

x = sample(1:6, 3, replace=TRUE)
print(x)
print(x == 6)
print(x < 6)

x = sample(1:6, 1000, replace=TRUE)
s = sum(x == 6)
print(s)
a = sum(x == 6)/1000
print(a)
print(1/6)

# x = matrix(sample(1:6, 4*10, replace=TRUE), nrow=4, ncol=10)
x = matrix(sample(1:6, 4*1000, replace=TRUE), nrow=4, ncol=1000)
print(x)
y = (x == 6)
print(y)
z = colSums(y)
print(z)
print(z > 0)
s = sum(z > 0)
print(s)
m = mean(z > 0)
print(m)
# Theoretical value = 0.518

print(dim(x))

# Estimate the probability of getting a sum of 7 when rolling two dices
ntrials = 10000
x = matrix(sample(1:6, 2 * ntrials, replace=TRUE), nrow=2, ncol=ntrials)
y = colSums(x)
print(mean(y == 7))
# Theoretical value = 1/6

# Estimate the probability of getting two sixes when rolling two dices
ntrials = 10000
x = matrix(sample(1:6, 2 * ntrials, replace=TRUE), nrow=2, ncol=ntrials)
y = colSums(x)
print(mean(y == 12))
# or
y = x[1,] == 6 & x[2,] == 6
print(mean(y))
# Theoretical value = 1/36
