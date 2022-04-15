# push_swap
This 42's curriculum project implements a sorting algorithm exercise with 2 stacks

## Usage
```
make
make visualize100
ARG=`ruby -e "puts (1..50).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker -vcat $ARG
```
