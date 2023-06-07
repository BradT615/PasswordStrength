#Password Strength Meter

This is a simple program that evaluates the strength of passwords based on certain criteria. It checks for both required and optional tests to determine the password's strength. The program reads passwords from input files and provides an analysis of each password's strength.

Prerequisites
To compile and run this program, you need:

A C compiler
Standard C libraries
Usage
Ensure that the input files, named "Proposed passwords #1.txt", "Proposed passwords #2.txt", and "Proposed passwords #3.txt", are in the same directory as the program.

Compile the program using the C compiler. For example, if you're using GCC, run the following command:

shell
Copy code
gcc password_strength_meter.c -o password_strength_meter
Run the compiled program:

shell
Copy code
./password_strength_meter
The program will process each password file and display the analysis results on the console.

File Structure
password_strength_meter.c: The main source code file containing the password strength meter program.
Proposed passwords #1.txt: The first input file containing a list of passwords to be evaluated.
Proposed passwords #2.txt: The second input file containing a list of passwords to be evaluated.
Proposed passwords #3.txt: The third input file containing a list of passwords to be evaluated.
Program Logic

The program follows these steps to evaluate the strength of each password:
Read the password flags from the input file, including maximum and minimum password lengths, pass phrase settings, and optional test requirements.
Print the password file number and the specified password flags.
Read each password from the input file.
Perform the required tests on each password, including length checks and forbidden character sequences.
If pass phrases are allowed, check if the password meets the pass phrase criteria.
If optional tests are required, check if the password meets the optional test criteria (lowercase, uppercase, digits, special characters).
Display the analysis results for each password, including passed and failed tests, required test errors, pass phrase status, and password strength.
Contributing
Contributions to this project are welcome. You can suggest improvements or report issues by creating a new issue on the GitHub repository.

License
This project is licensed under the MIT License.
