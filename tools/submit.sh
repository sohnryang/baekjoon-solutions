problem_id=$(pwd | grep -Eo '[0-9]+$')
boj submit $problem_id $1
