let inc_anonymous = fun x -> x + 1
let inc x = x + 1

let () = inc_anonymous 3 |> string_of_int |> print_endline
let () = inc 3 |> string_of_int |> print_endline

(** [fact n] is [n!].
    Requires: [n >= 0].*)
let rec fact n = if n = 0 then 1 else n * fact (n - 1)
let () = fact 0 |> string_of_int |> print_endline
let () = fact 1 |> string_of_int |> print_endline
let () = fact 5 |> string_of_int |> print_endline

(** [pow x y] is [x] to the power of [y].
Requires: [y >= 0]. *)
let rec pow x y = if y = 0 then 1 else x * pow x (y - 1)
let () = pow 6 0 |> string_of_int |> print_endline
let () = pow 2 5 |> string_of_int |> print_endline

let rec even n =
  n = 0 || odd (n - 1)
and odd n = 
  n <> 0 && even (n - 1)

let () = even 0 |> string_of_bool |> print_endline
let () = even 3 |> string_of_bool |> print_endline
let () = odd 100 |> string_of_bool |> print_endline

let () = succ 2 * 10 |> string_of_int |> print_endline
let () = succ @@ 2 * 10 |> string_of_int |> print_endline

let square x = x * x
let () = square (succ 5) |> string_of_int |> print_endline
let () = 5 |> succ |> square |> string_of_int |> print_endline
let () = 5 |> succ |> square |> square |> succ |> string_of_int |> print_endline

let id x = x
let () = id 3 |> string_of_int |> print_endline
let () = id "Hello" |> print_endline
let id_int' : int -> int = id
let () = id_int' 3 |> string_of_int |> print_endline
let id' : 'a -> 'a = fun x -> x + 1
let () = id' 3 |> string_of_int |> print_endline

let first x y = x
let first_int : int -> 'b -> int = first

let s ~num1 ~num2 = num1 + num2
let () = s ~num1:1 ~num2:2 |> string_of_int |> print_endline
let s2 ?num1:(num1=0) ?num2:(num2=0) () = s ~num1 ~num2
let () = s2 () |> string_of_int |> print_endline
let () = s2 ~num1:3 () |> string_of_int |> print_endline
let () = s2 ~num1:3 ~num2:5 () |> string_of_int |> print_endline

let add x y = x + y
let addx x = fun y -> x + y
let add5 = addx 5
let () = add5 2 |> string_of_int |> print_endline

(*
Every OCaml function takes exactly one argument :o 
*)

let () = ( + ) 1 2 |> string_of_int |> print_endline
let add3 = ( + ) 3
let () = add3 2 |> string_of_int |> print_endline
let () = ( * ) 1 2 |> string_of_int |> print_endline
let () = ( = ) 1 2 |> string_of_bool |> print_endline
let () = ( /. ) 3.5 2. |> string_of_float |> print_endline

let ( <^> ) x y = max x y
let () = 1 <^> 2 |> string_of_int |> print_endline
let () = ( <^> ) 1 2 |> string_of_int |> print_endline

(** [count n] is [n], computed by adding 1 to itself [n] times.  That is,
    this function counts up from 1 to [n]. *)
let rec count n =
  if n = 0 then 0 else 1 + count (n - 1)
let () = count 10 |> string_of_int |> print_endline
let () = count 100_000 |> string_of_int |> print_endline
(* Stack Overflow: let () = count 1_000_000_000 |> string_of_int |> print_endline *)
let rec count_aux n acc = if n = 0 then acc else count_aux (n - 1) (acc + 1)
let count_tr n = count_aux n 0 (* tr = tail recursive *)
let () = count_tr 1_000_000_000 |> string_of_int |> print_endline

(** [fact n] is [n] factorial. *)
let rec fact n = if n = 0 then 1 else n * fact (n - 1)
let rec fact_aux n acc = if n = 0 then acc else fact_aux (n - 1) (n * acc)
let fact_tr n = fact_aux n 1
(* int overflow, use zarith *)

let rec zfact_aux n acc = if Z.equal n Z.zero then acc else zfact_aux (Z.pred n) (Z.mul acc n)
let zfact_tr n = zfact_aux n Z.one
let () = zfact_tr (Z.of_int 50) |> Z.to_string |> print_endline
