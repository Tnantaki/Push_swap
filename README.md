# Push_swap
> This project will make you sort data on a stack, with a limited set of instructions, using the lowest possible number of actions. To succeed you’ll have to manipulate various types of algorithms and choose the most appropriate solution (out of many) for an optimized data sorting.

---
## 📢The Rule
-   You have 2 stacks. named a and b.
    -   **Stack a** for random amount of unique numbers.
    -   **Stack b** is empty stack for temporary keep the numbers between sorting.
-   You have to follows this actions :
    -   **sa (swap a)**: Swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements.
    -   **sb (swap b)**: Swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements.
    -   **ss** : **sa** and **sb** at the same time.
    -   **pa (push a)**: Take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
    -   **pb (push b)**: Take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
    -   **ra (rotate a)**: Shift up all elements of stack a by 1. The first element becomes the last one.
    -   **rb (rotate b)**: Shift up all elements of stack b by 1. The first element becomes the last one.
    -   **rr** : **ra** and **rb** at the same time.
    -   **rra (reverse rotate a)**: Shift down all elements of stack a by 1. The last element becomes the first one.
    -   **rrb (reverse rotate b)**: Shift down all elements of stack b by 1. The last element becomes the first one.
    -   **rrr** : **rra** and **rrb** at the same time.
## 📝Execution
The program takes a list of integers as an argument. Sorting ascending order by instruction at the rule and display instruction on the Terminal.
###  Ex - random numbers
```bash
$ ./push_swap 2 1 3 6 5 8
sa
pb
pb
pb
sa
pa
pa
pa
```
###  Example - in case of error
```bash
$ ./push_swap 0 one 2 3
Error
```
