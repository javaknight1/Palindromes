The Task

Your assignment will be to test integers input by the user to determine if the integer is a palindrome or candidate lycherl and if not, to perform the reverse/add algorithm described above to create a palindrome showing all of the sums produced along the way.
Since we don't want your project to run forever, you'll need to check to see if the integer input by the user is a candidate lychrel first. If it is, don't attempt to perform the reversal and adds, just print a message and continue. See the sample output below. A list of candidate lychrels will be provided in a file that is read by your progam.

If the number input by the user is not a candidate lychrel, you should check to see if it is a palindrome. If it's not a palindrome, perform as many reverse/add iterations as necessary until a palindrome is formed, printing the numbers used and the sum at each iteration. After the palindrome has been formed you must display the number of reverse and add interation that were necessary to create it.

How does your program work?

Your program prompts the user for the name of the file containing candidate lychrels.
Your program prompts the user for an integer to test.
If the integer is zero, exit your program.
If the integer is a candiate lychrel, output an appropriate message and prompt for a new integer.
If the integer is a palindrome, output an appropriate message and prompt for a new integer.
Otherwise, perform the reverse/add algorithm above until a palindrome is found, printing all sums along the way. Print the number of iterations required to produce the palindrome. Prompt for a new integer.