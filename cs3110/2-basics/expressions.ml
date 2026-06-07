print_endline (string_of_int (65 / 60));
65 mod 60 |> string_of_int |> print_endline;

(begin
  try ignore (65 / 0)
  with Division_by_zero ->
    print_endline "division by zero"
end);

3.14 *. 2. |> string_of_float |> print_endline;
3.14 *. (float_of_int 2) |> string_of_float |> print_endline;
0.1 +. 0.2 |> string_of_float |> print_endline;

"abc" ^ "def" |> print_endline;
String.make 1 'z' |> print_endline;

int_of_string "123" |> string_of_int |> print_endline;
String.make 1 "abc".[0] ^ String.make 1 "abc".[1] |> print_endline;

print_endline (if 3 + 5 > 2 then "yay!" else "boo!");

print_int (let x = 42 in x + 1);;

let a = "big";;
let b = "red";;
let c = a ^ b;;
(* Is equivalent to: *)
let a = "big" in
let b = "red" in
a ^ b
