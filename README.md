# DC_DP_M
using a Divide and conquer, dynamic programming, memoization algorithms to solve the binomial coefficent and comparing runtimes.

# Binomial Coefficient
C(n,k) = n! / k!(n-k)!
Combinations of "n choose k"
equal to n factorial divided by k factorial times n minus k factorial

Using the example of a 52-card deck and wanting a unique 5-card hand.


# Divide and Conquer
utilizes a simple divide and conquer strategy. Problem is the algorithm calculating subproblems that results in a long runtime.

# Dyanmic Programming
A bottom-up algorithm that solves stores values and skips them if they have already been calculated. This solves the issue of calculating subproblems that have already been solved by analyzing them from smallest to largest until the original problem has been solved.


# Memoization
A top-down dynamic programming algorithm that solves only the needed smaller problems and avoids redundant calculations by solving smaller-problems once and storing their solutions.
This algorithm checks the solution in it's table and stores it if it's not there like dynamic programming except it calls a special function to help it's calculation.