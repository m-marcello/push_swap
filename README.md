# push_swap

This is a very simple and highly effective algorithm project:<br>
A set of integer wants to be sorted using only 2 stacks and a limited set of instructions to manipulate both stacks.<br>
The goal?<br>
Write 2 programs in C:
- The first, named `checker`, takes integer arguments and reads instructions on the standard output. Once read, checker executes them and displays OK if integers are sorted. Otherwise, it will display KO.
- The second one, called `push_swap`, calculates the smallest amount of push-swap instruction language operations that sorts integer arguments received and displays them on the standard output.

## push-swap instruction language

- `sa` *(swap **a**)*: swap the first 2 elements at the top of stack **a**. Do nothing if there is only one or no elements)
- `sb` *(swap **b**)*: swap the first 2 elements at the top of stack **b**. Do nothing if there is only one or no elements)
- `ss`: `sa` and `sb` at the same time
- `pa` *(push **a**)*: take the first element at the top of **b** and put it at the top of **a**. Do nothing if **b** is empty
- `pb` *(push **b**)*: take the first element at the top of **a** and put it at the top of **b**. Do nothing if **a** is empty
- `ra` *(rotate **a**)*: shift up all elements of stack **a** by 1. The first element becomes the last one
- `rb` *(rotate **b**)*: shift up all elements of stack **b** by 1. The first element becomes the last one
- `rr`: `ra` and `rb` at the same time
- `rra` *(reverse rotate **a**)*: shift down all elements of stack **a** by 1. The last element becomes the first one
- `rrb` *(reverse rotate **b**)*: shift down all elements of stack **b** by 1. The last element becomes the first one.
- `rrr`: `rra` and `rrb` at the same time

## compiling

At the root of the repository run `make`.

## usage

define a variable `ARG` as the set of integers to be sorted. For example:

	$> ARG="4 6 2 7 8 15"

### push_swap

	$> ./push_swap [options] $ARG
	options:
		-v	verbose
		-c	color

### checker

	$> ./push_swap $ARG | ./checker $ARG
