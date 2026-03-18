This project has been created as part of the 42 curriculum by hsrour

Push_Swap
Description
Push Swap is a sorting project where the goal is to sort a stack of integers using a limited set of operations and two stacks a and b. The challenge is not only to sort correctly, but to do so using the minimum number of operations.

The goal
The goal is to create 3 different sorting algorithms to sort stack a using stack b. The sorting algorithms should have 3 different time complexities:

O(n²)
O(n√n)
O(nlog(n))
Instructions
Allowed Operations
For Swapping:

sato swap the first two elements of stack a.
sbto swap the first two elements of stack b.
ssruns sa and sb at the same time.
For Pushing:

pato push the top element from b to a.
pbto push the top element from a to b.
For Rotating:

rato rotate stack a up.
rbto rotate stack b up.
rrruns ra and rb at the same time.
For Reverse Rotating:

rrato rotate stack a down.
rrbto rotate stack b down.
rrrruns rra and rrb at the same time.
Every operation prints its name when used, unless the --bench selector is used. When used, the --bench selector prints a summary of the work done by the program to the stderr. All the operations were implemented, included in the header file, and each algroithm used the necessary operations.

Compilation
To compile, we use:

make
To clean object files:

make clean
To remove all generated files:

make fclean
To recompile:

make re
Testing
to test the code:

./push_swap "753 537 84 83 72 71 20 19 17 10 8 7 1 0 -32"
to test random generated numbers:

shuf -i 0-9999 -n 500 > args.txt ; ./push_swap $(cat args.txt)
to count the operations, you add:

| wc -l
Error Handling
The program displays Error and exits if:

Non-numeric arguments are provided "which only accepts having a maximun of 2 non duplicate selectors, not of the same type and should start with --".
Duplicate Numbers are detected.
Numbers exceed integer limits.
If Numbers are not stacked at the end of the line.
Constraints
Written in C
No memory leaks
Norm-compliant (42 Norminette)
Norminette
Resources
AI was used to make the README.md file more formal.

Algorithms
The Selection Sort
This Algorithm is a O(n²). This Sorting Algorithm is used if the selectore is "--simple" or if "--adaptive" and the disorder < 0.2 or no selectore precised. The code sorts numbers using two stacks A and B by repeatedly taking the smallest element from stack A and moving it to stack B.

The steps:

While stack A is not empty:

Find where the smallest value is and move it to the top, but to minimizes the number of operations, we can:
"rotate (ra) if it’s closer to the top or revrotate (rra) if it’s closer to the bottom".
Push it to stack B;(pb).
Stack B now contains all elements, ordered from largest (top) to smallest (bottom).
After A is empty, While B is not empty:

Push everything back from stack B to stack A;(pa).
Stack A ends up fully sorted in ascending order.

The Medium Sort
This Algorithm is a O(n√n). This Sorting Algorithm is used if the selectore is "--medium" or if "--adaptive" and 0.2 ≤ disorder < 0.5 or no selectore precised. The code sorts numbers using two stacks A and B by repeatedly taking chunks of the smallest elements from stack A and moving it to stack B.

The Steps:

While stack A is not empty:

Take chunks of size (√n) where n is the number of elements by repeatedly rotating (ra) if it’s closer to the top or revrotating (rra) if it’s closer to the bottom.
Pushing the elements to stack B;pb when found.
Stack B now contains all elements, ordered from largest (top) to smallest (bottom).
After A is empty, while B is not empty:

We extract the largest from B, and then we push it to A
Stack A ends up fully sorted in ascending order.

The Complex Sort
The complexity is (nlog(n)) This Sorting Algorithm is used if the selectore is "--complex" or if "--adaptive" and disorder >=0.5 or no selectore precised. The code sorts numbers using two stacks A and B by repeatedly taking chunks of the smallest elements from stack A and moving it to stack B.

The Steps:

While stack A is not empty:

Take (log(n)) chunks of n / (log(n)) size where n is the number of elements by repeatedly rotating (ra) if it’s closer to the top or revrotating (rra) if it’s closer to the bottom.
Pushing the elements to stack B;pb when found.
Stack B now contains all elements, ordered from largest (top) to smallest (bottom).
After A is empty, while B is not empty:

We extract the largest from B, and then we push it to A
Stack A ends up fully sorted in ascending order.

