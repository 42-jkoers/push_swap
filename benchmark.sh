#!/bin/bash
echo    "elements     $1"
echo -n "operations   "
NUMS=$(ruby -e "puts (1..$1).to_a.shuffle.join(' ')")
./push_swap $NUMS > /tmp/push_swap.out
wc -l < /tmp/push_swap.out
echo -n "checker says "
cat /tmp/push_swap.out | ./checker $NUMS
echo ""


# i="0"

# while [ $i -lt 100 ]
# do

# start=`date +%s.%N`
# ./push_swap $(ruby -e "puts (0..2).to_a.shuffle.join(' ')") | wc -l
# end=`date +%s.%N`

# # runtime=$( echo "$end - $start" | bc -l )
# # echo -n "time "
# # echo $runtime

# i=$[$i+1]
# done