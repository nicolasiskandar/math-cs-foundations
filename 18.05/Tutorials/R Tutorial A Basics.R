2+3
2*3
2/3
2^3
2*(3+1)^2

x = 2 + 3
print(x)
y = 1 + 2
print(x * y)
z = x ^ y
print(z)

x <- 3
print(x)
x <- 5.412
print(x)

x = c(1.1, 0.0, 3.14, 2.718)
print(x)

x <- c(2, 4, 6)
print(x)

x = 1:4
print(x)

x = 3:10
print(x)

x = 9:2
print(x)

x = 1:40
print(x)

x = c(1, 3, 5)
y = x + 7.1
print(y)

x = c(1, 3, 5)
7 * x
x / 7
7 / x
x^6
x^7
7^x

x = c(1, 2, 3)
y = c(4, 5, 6)
print(x + y)
print(x - y)
z = x * y
print(z)
z = x / y
print(z)
print(x ^ y)

x = c(2, 4, 6, 8, 10)
print(x[1])
print(x[2])
print(x[3])
print(x[4])

x = 2 * c(1, 2, 3, 4, 5, 6, 7, 8)
print(x)

y = x[c(1, 2)]
print(y)
y = x[c(1, 3, 5)]
print(y)

y = x[c(2, 2, 2, 1)]
print(y)

y = x[2:5]
print(y)

x = sin(1)
print(x)

x = sin(1.4)
print(x)

x = sin(3)
print(x)

print(pi)
print(sin(pi/2))

x = exp(0)
print(x)

x = exp(1)
print(x)

x = c(1, 2, 3, 4)
print(x)
y = sin(x)
print(y)
y = exp(x)
print(y)

x = 1:6
print(x)
s = sum(x)
print(s)
m = mean(x)
print(m)

x = 1:1024
s = sum(x)
print(s)

s = sum(1:1024)
print(s)

x = 1:1024
s = sum(x ^ 2)
print(s)
s = sum((1:1024)^2)
print(s)


x = 1:10
print(x)
y = matrix(x, nrow=2, ncol=5)
print(y)
z = matrix(x, nrow=5, ncol=2)
print(z)
z = matrix(x, nrow=2, ncol=5, byrow=TRUE)
print(z)

print(y[1, 1])
print(y[2, 3])

print(y)

s = colSums(y)
print(s)

s = rowSums(y)
print(s)

m = colMeans(y)
print(m)

m = rowMeans(y)
print(m)

?mean
