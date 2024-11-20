from typing import List, Tuple
import numpy as np

# TODO: Implement the function to return the nth Fibonacci number and the list of Fibonacci numbers up to n
# The function should take an integer n as input and return a tuple:
# - The first element of the tuple should be the nth Fibonacci number
# - The second element should be a list of all Fibonacci numbers up to the nth number
# For example, if n = 3, the function should return (2, [1, 1, 2])
# It is recommended to use dynamic programming or an iterative approach for efficiency
def fibo(n) -> Tuple[int, List]:
    
    # Example return value for n = 3
    # results contain the nth Fibonacci number and the list of Fibonacci numbers up to n
    # results = (2, [1, 1, 2])
    if n == 1 :
        return (1, [1])
    results_list = [1, 1]
    for i in range (2, n) :
        results_list.append(results_list[i - 2] +results_list[i - 1])
    
    return (results_list[-1], results_list)
    
    
# Instructions: Complete only the func implementation. You may add print statements to test when using the "Run" button, 
# but only the func will be used for grading upon submission.
