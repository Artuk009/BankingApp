# Cplusplus-BankingApp

# Summarize the project and what problem it was solving.
The goal of this project was to develop an application that will allow the user to see how their investments will grow over time with different input variables. These variables included: the initial investment amount, monthly deposit, annual interest(compunded), and the number of years the user will be investing for. The program returns two charts based on the input from the user: one that shows the year end balance and interest earned without monthly deposits and a chart that shows the same information but with monthly depsoits included in the calculations.

# What did you do particularly well?
I did particularly well with implementing object oriented programing principals to make the main function as dry as possible. I also did well with utilitizing inheritance, abstraction, and encapsulation in that the desired input varibles initialized in private variables that were inherited by the input and setter/getter functions and then called from a separate class file. I also made use of try/catch blocks to effectively validate user input for the main function so that it would throw an error code if the input was a negative integer.

# Where could you enhance your code? How would these improvements make your code more efficient, secure, and so on?
I could have inhanced my code by utilizing polymorphism to prevent writing functions that were similar but only had minor differences in the string output. Also, in regards to the input functions, I could have utilized the getline method to create one input function as opposed to four individual ones. Finally, I ended up using a nested while loop within the main function which could have been avoided by creating an a program terminator function that could have been called as another class object.

# Which pieces of the code did you find most challenging to write, and how did you overcome this? What tools or resources are you adding to your support network?
I spent the most time on the user input functions and attempting to write the least amount of code while still validating user input. As stated above, I believe the getline method would have been the key to combining four functions into one. Going forward, considering this method will be essential, especially in applications requiring a multitude of user inputs. 

# What skills from this project will be particularly transferable to other projects or course work?
Going forward, the OOP principles I learned from completing this project will be essential in future C++ and Java development. These principles are essential for writing readable and secure code for future application development projects. Also, the importance of validating user input will be incredibly useful going forward beacause now I know how to prevent a program from crashing due to a user error. 

# How did you make this program maintainable, readable, and adaptable?
I made this program maintainable by including in line comments so that if other developers know why the program executes the way it does and can make alterations where necessary to improve functionality and readability. The program is readable because the main function has its own file, and the class functios are divided into a .h file and defined functions .cpp file. The program is adatptable because the same format can be carried over many different types of application uses as the foundation of this application can be utilized in many different ways (i.e. user input functions, setter/getter functions, terminator function, etc.)
