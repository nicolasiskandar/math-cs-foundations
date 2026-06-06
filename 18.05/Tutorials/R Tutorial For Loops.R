x = rep(0, 10)
print(x)
x = rep(2, 6) 
print(x)
x = rep('abc', 5)
print(x)
x = rep(1:4, 5)
print(x)

for (j in 1:5) {
  print(j ^ 2)
}

n = 5
x = rep(0, n)
for (j in 1:n)
  x[j] = j ^ 2
s = sum(x)
print(s)

nsides = 6
ntrials = 1000
trials = rep(0, ntrials)
for (j in 1:ntrials)
  trials[j] = sample(1:nsides, 1)
m = mean(trials ^ 2)
print(m)

n = 9
x = 1:n
ntrials = 10000
trials = rep(0, ntrials)
for (j in 1:ntrials) {
  y = sample(x, n)
  s = sum(y == x)
  trials[j] = (s == 0)
}
m = mean(trials)
print(m)
