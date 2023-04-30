## C - Simple Shell		


School project 
##### Write a UNIX command line interpreter.


>>> Display a prompt and wait for the user to type a command. A command line always ends with a new line.
The prompt is displayed again each time a command has been executed.
The command lines are simple, no semicolons, no pipes, no redirections or any other advanced features.
The command lines are made only of one word. No arguments will be passed to programs.
If an executable cannot be found, print an error message and display the prompt again.
Handle errors.
You have to handle the “end of file” condition (Ctrl+D). 
-----------------------------------------------------------------------------------------------------------

#### The shell is the interface between the user and the operating system.

The shell is an executable file (program) that acts as an intermediary between the operating system and the user who enters
commands in text mode.
Its function is to read the command line, interpret its meaning, execute the command and then output the result via the outputs.
Shell Programs
A shell program is an application that allows interacting with the computer. In a shell the user 
can run programs and also redirect the input to come from a file and output to come from a 
file. Shells also provide programming constructions such as if, for, while, functions, variables 
etc. Additionally, shell programs offer features such as line editing, history.

![kernel layout](https://user-images.githubusercontent.com/124454895/234965806-232ecab7-9666-468d-8de1-029d39bed253.png)



### Processes in Linux ,
~~~
In Linux or any Unix operating system, processes are created using a cloning mechanism known as fork. This mechanism creates
a new process based on an existing one. The new process is considered a child process of the previous process, which we will
call the parent. The process ID (PID) is a unique integer that identifies each process in a table managed by the Linux kernel.

To create a new process, the system call fork() is used. This call takes no arguments and returns a process 
ID. The purposeof fork() is to create a child process of the caller. Once the child process is created, both the parent
and child will execute the next instruction following the fork() system call. To distinguish between the parent and the 
child process, the return value of fork() needs to be tested:

If fork() returns a negative value, the child process creation was unsuccessful.
If fork() returns zero, the newly created process is the child process.
If fork() returns a positive value, the process ID of the child process is returned to the parent. The process ID is of
type pid_t defined in sys/types.h, and it is usually an integer.
The getpid() function can be used to retrieve the process ID assigned to a process.
In summary, fork() is used to create child processes in Linux or any Unix operating system. The return value of fork() 
can be used to determine whether the process is the parent or the child. The process ID uniquely identifies each process
in a table maintained by the Linux kernel.

getline() reads an entire line from stream, storing the address
       of the buffer containing the text into *lineptr.  The buffer is
       null-terminated and includes the newline character, if one was
       found.
  ~~~
  
  
  ![process readme](https://user-images.githubusercontent.com/124454895/234963916-7dba232f-8948-4be6-90ce-3b2b2d8e7f76.png)

  ------------------------------------------------------------------------------------------------------------------------------
  
  The getline function is used to read an input line from an input stream (in this case, the standard input, i.e. the keyboard).
  
imputLength = getline(&lineptr, &n, stdin);
This assigns to lineptr the value of the line entered from the keyboard. The size of the buffer is stored in n.
 The variable imputLength will contain the number of characters read, including the final null character.

 in this program the arguments are not taken directly from the command line, but are taken via the getline() function and stored in a string 
 called lineptr.string called lineptr. This string is then processed to separate the arguments using the strtok() function and stored 
 in an array of strings.using the strtok() function and stored in an array of character strings called argv
 In summary, the arguments are read from the standard input using getline(), stored in a string, separated using strtok()
 and stored in an array of character strings


 #### Flow of the built "shell"
The program uses the fork(), execvp() and waitpid() functions to create a child process that executes external commands,
and waits for the child process to terminate before continuing. It also includes the implementation of an execute_internal_command() function to handle internal commands such as "exit".


The program begins with the declaration of two functions: execute_external_command() and execute_internal_command(). The first function handles 
the execution of external commands, while the second handles internal commands.

The execute_external_command() function receives an array of strings containing the arguments for the external command. It first creates a child process using fork(). If the return value of fork() is zero, the child process executes the command using execvp(). If the return value of fork() is negative, an error message is printed and -1 is returned. If the return value of fork() is greater than zero, the parent process waits for the child process to finish using waitpid(), and then frees the memory allocated for the argument array.

The execute_internal_command() function receives a string array containing the arguments for the internal command. In this implementation, this function does nothing, since no internal commands have been implemented.

The main function of the program is main(). The function begins with the declaration of some variables, including a prompt message to the user, a pointer to the line entered by the user and the size of the line, a delimiter for the tokenizer, and counters for the loops.

Within the main while loop, the program prints the prompt message, reads the user input using getline(), and then uses strtok() to split the entered line into words. The program uses malloc() to allocate memory for an array of pointers to char, and then uses strtok() again to store each word in the array.

After the argument array has been constructed, the program uses strcmp() to determine whether the command entered is internal or external. If the command is internal, the execute_internal_command() function is called, otherwise the execute_external_command() function is called.



<img width="440" alt="flow my shell" src="https://user-images.githubusercontent.com/124454895/235257036-40a8e350-7a85-4d7d-8a3d-79d8a6850189.png">

		  

