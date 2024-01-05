(* Baekjoon Online Judge #15552 *)
(* https://www.acmicpc.net/problem/15552 *)
let solve i = fst i + snd i
let read_input () = Scanf.scanf "%d %d\n" (fun a b -> (a, b))
let t_input = Scanf.scanf "%d\n" Fun.id

let rec loop t =
  if t = 0 then ()
  else (
    () |> read_input |> solve |> Printf.printf "%d\n";
    loop (t - 1))
;;

loop t_input
