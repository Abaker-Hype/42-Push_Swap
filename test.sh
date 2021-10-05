#!/bin/bash

shuffle() {
   local i tmp size max rand

   size=${#array[*]}
   max=$(( 32768 / size * size ))

   for ((i=size-1; i>0; i--)); do
      while (( (rand=$RANDOM) >= max )); do :; done
      rand=$(( rand % (i+1) ))
      tmp=${array[i]} array[i]=${array[rand]} array[rand]=$tmp
   done
}

array=($(seq $1 1 $2))

shuffle
echo "Shuffled Array"
echo ${array[*]}
echo "Push Swap Output"
./push_swap ${array[*]}
echo "Intra Checker"
./push_swap ${array[*]} | ./checker_Mac ${array[*]}
echo "Bonus Checker"
./checker ${array[*]}
