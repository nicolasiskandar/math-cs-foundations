source('mit18_05_s22_colmatches.r')

ndays = 365
npeople = 41
ntrials = 10000
size_match = 2

year = 1:ndays

y = sample(year, npeople * ntrials, replace=TRUE)
trials = matrix(y, nrow=npeople, ncol=ntrials)
w = colMatches(trials, size_match)
prob_B = mean(w)
prob_B
