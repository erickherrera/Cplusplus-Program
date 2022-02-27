#Summarize the project and what problem it was solving.
This application is able to read a given text file to perform various functions trigerred through a menu. The functions are the following: 1-Display each item and the amount it appears on the given text file. 2-Lets the user enter what item they want to find out the frequency for. 3-Displays a histogram for each item on the list(Histogram is stored on frequency.dat). 4-Exit the program

#What did you do particularly well?
Used python to efficiently create an object of jey value pairs to store the items on the list and the amount it appears on the least. These python function are triggered through a switch structure that only creates the necessary objects when triggered by the user choice, and the objects are automatically removed from the call stack eveyrimte the user enter a case.

#Where could you enhance your code? How would these improvements make your code more efficient, secure, and so on?
I should build a try catch strcuture to make sure the code doesnt crash when a string is entered instead of an integer. 

#Which pieces of the code did you find most challenging to write, and how did you overcome this? What tools or resources are you adding to your support network?
The creation of the Python functions, and triggering them from the C++ file was the most challenging piece of this program. Initially I was getting an access violation issue when calling the C++ function that creates the Python object that will then perform the function that was called. After fixing this issue, I realized the code was not printintg anything like it was supposed to so I had to debug using PyErr() and print statements to then learn my program was not finding the text file it needed to read. To fix this I needed to specify the location of the file when using the open operator to read and write. 

#What skills from this project will be particularly transferable to other projects or course work?
Being able to use Python in conjuntcion with C++ can be transferrable to many projects as it promotes leveraging the strengths of each programming language, plus it also increases my efficiency as a programmer because I can also leverage the libraries found in each of the programming langauges. Leraning the special libraries for each programming language will help me solve problems that maybe with C++ would be complicated by Python might have a library to resolve that specific issue.

#How did you make this program maintainable, readable, and adaptable?
This program is maintainable beacuse it utiilizes SOLID principles for the code structure. This program is readable because it has comments and the variable name are descriptive. This program is adaptable because it utilizes encapsulation and seperate files that help comparmentalize the functions of the application. 
