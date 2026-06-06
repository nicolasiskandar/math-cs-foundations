square_me = function(n) {
  x = n * n
  return (x)
}

square_me(4)

hello_there = function(name, adjective) {
  phrase = paste("Hello ", name, "! You look ",
                 adjective, ".", sep="")
  print(phrase)
}

hello_there("Jerry", "fuzzy")