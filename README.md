# n-digits-ai-puzzle

A simple AI program to solve the number puzzle: Find a 10-digit number where the first digit is how many zeros in the number, the second digit is how many 1s in the number etc. until the tenth digit which is how many 9s in the number.

This was one of the final programs for my Artificial Inteligence 481 class, and as such it contains extra class structures that are not used for the current problem.

Search technique is based off the N-queens puzzle and uses a hill-climbing approach in order to solve this puzzle.  It will find solutions where n=5,7,8,9, or 10 and will search forever or give back a non-valid answer (IE saying there are 10 instances of a number).
