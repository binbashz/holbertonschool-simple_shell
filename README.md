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

![kernel layout](https://user-images.githubusercontent.com/124454895/234960626-c8162698-6715-4db6-8f7f-97f3848a8910.png)


### Processes in Linux ,
~~~
  or in any unix operating system, are created based on an existing process 
  by means of a cloning mechanism,or fork.existing process by means of a cloning mechanism, or fork.
  A Linux process spawns a new process to perform a given task, and this new process is considered a 
  child process of the previous process , which we will call parent.process is considered a
  child process of the previous process, which we will call parent.
  The PID, or Process ID, is an integer that uniquely identifies each process in a table of processes
  managed by the a process table managed by the Linux kernel. This process table maintains
  an entry for each of the processes currently running on the system.

   
 fork() — Create a new process
 System call fork() is used to create processes. It takes no arguments and returns a process ID. 
 The purpose of fork() is to create a new process, which becomes the child process of the caller. 
 After a new child process is created, both processes will execute the next instruction following 
 the fork() system call. 
 Therefore, we have to distinguish the parent from the child. This can be done by testing the
 returned value of fork():

if fork() returns a negative value, the creation of a child process was unsuccessful.
fork() returns a zero to the newly created child process.
fork() returns a positive value, the process ID of the child process, to the parent. 
The returned process ID is of type pid_t defined in sys/types.h. Normally,
the process ID is an integer. Moreover, a process can use function getpid() to retrieve 
the process ID assigned to this process.
Therefore, after the system call to fork(), a simple test can tell which process is the child.

getline() reads an entire line from stream, storing the address
       of the buffer containing the text into *lineptr.  The buffer is
       null-terminated and includes the newline character, if one was
       found.
  ~~~
  
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
and waits for the child process to terminate before continuing. It also includes the implementation of an execute_internal_command() function to handle internal commands such as "exit",  and "cd".


The program begins with the declaration of two functions: execute_external_command() and execute_internal_command(). The first function handles 
the execution of external commands, while the second handles internal commands.

The execute_external_command() function receives an array of strings containing the arguments for the external command. It first creates a child process using fork(). If the return value of fork() is zero, the child process executes the command using execvp(). If the return value of fork() is negative, an error message is printed and -1 is returned. If the return value of fork() is greater than zero, the parent process waits for the child process to finish using waitpid(), and then frees the memory allocated for the argument array.

The execute_internal_command() function receives a string array containing the arguments for the internal command. In this implementation, this function does nothing, since no internal commands have been implemented.

The main function of the program is main(). The function begins with the declaration of some variables, including a prompt message to the user, a pointer to the line entered by the user and the size of the line, a delimiter for the tokenizer, and counters for the loops.

Within the main while loop, the program prints the prompt message, reads the user input using getline(), and then uses strtok() to split the entered line into words. The program uses malloc() to allocate memory for an array of pointers to char, and then uses strtok() again to store each word in the array.

After the argument array has been constructed, the program uses strcmp() to determine whether the command entered is internal or external. If the command is internal, the execute_internal_command() function is called, otherwise the execute_external_command() function is called.



		  

