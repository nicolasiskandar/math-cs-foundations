let () = print_endline "OCaml"
let () = print_endline "is beautiful" ;;

print_endline "OCaml";
print_endline "is beautiful" ;;

(ignore 3); 5 ;;

(** [print_stat_ted name num] prints [name: num].*)
let print_stat_ted name num =
  print_string name;
  print_string ": ";
  print_float num;
  print_newline ()

let () = print_stat_ted "mean" 84.39

let print_stat name num =
  Printf.printf "%s: %F\n%!" name num

let () = print_stat "mean" 84.39

let string_of_stat name num = 
  Printf.sprintf "%s: %F" name num

let output_str = string_of_stat "mean" 84.39
let () = print_endline output_str
