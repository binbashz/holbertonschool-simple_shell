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

The shell is an executable file (program) that acts as an intermediary between the operating system and the user who enters commands in text mode.
Its function is to read the command line, interpret its meaning, execute the command and then output the result via the outputs.
Shell Programs
A shell program is an application that allows interacting with the computer. In a shell the user 
can run programs and also redirect the input to come from a file and output to come from a 
file. Shells also provide programming constructions such as if, for, while, functions, variables 
etc. Additionally, shell programs offer features such as line editing, history.


~~~
getline() reads an entire line from stream, storing the address
       of the buffer containing the text into *lineptr.  The buffer is
       null-terminated and includes the newline character, if one was
       found.
       
   Los procesos en Linux, o en cualquier sistema operativo unix, son creados en base a un proceso
   ya existente mediante un mecanismo de clonación, o fork.
   Un proceso en Linux genera un nuevo proceso para que realice una tarea determinada, y este
   nuevo proceso es considerado proceso hijo del proceso anterior, al que llamaremos padre
   El PID, o Process ID, es un número entero que identifica unívocamente a cada proceso en 
   una tabla de procesos administrada por el kernel Linux. Esta tabla de procesos mantiene
   una entrada por cada uno de los procesos que  están en ejecución en el sistema en el momento actual
   
  fork() — Create a new process
   System call fork() is used to create processes. It takes no arguments and returns a process ID. 
   The purpose of fork() is to create a new process, which becomes the child process of the caller. 
   After a new child process is created, both processes will execute the next instruction following 
   the fork() system call. 
   Therefore, we have to distinguish the parent from the child. This can be done by testing the
   returned value of fork():

If fork() returns a negative value, the creation of a child process was unsuccessful.
fork() returns a zero to the newly created child process.
fork() returns a positive value, the process ID of the child process, to the parent. 
The returned process ID is of type pid_t defined in sys/types.h. Normally, the process ID is an integer. 
Moreover, a process can use function getpid() to retrieve the process ID assigned to this process.
Therefore, after the system call to fork(), a simple test can tell which process is the child.
  ~~~
  
  La función  getline se utiliza para leer una línea de entrada de un flujo de entrada (en este caso, la entrada estándar, es decir, el teclado)
  
imputLength = getline(&lineptr, &n, stdin);
Esto asigna a lineptr el valor de la línea que se ingresa desde el teclado. El tamaño del búfer se almacena en n.
 La variable imputLength contendrá el número de caracteres leídos, incluyendo el carácter nulo final.

 en este programa los argumentos no son tomados directamente de la línea de comando, sino que se toman a través de la función getline() y se almacenan
 en una cadena de caracteres llamada lineptr. Luego, esta cadena es procesada para separar los argumentos
 utilizando la función strtok() y se almacenan en un array de cadenas de caracteres llamado argv
 En resumen, los argumentos son leídos desde la entrada estándar usando getline(), se almacenan en una cadena de caracteres, se separan utilizando strtok()
 y se almacenan en un array de cadenas de caracteres
  
  ## /* site under construcction */

El programa utiliza las funciones fork(), execvp() y waitpid() para crear un proceso hijo que ejecuta comandos externos,
y espera a que el proceso hijo termine antes de continuar. También incluye la implementación de una función execute_internal_command()
para manejar comandos internos como "cd" o "exit".

El programa comienza con la declaración de dos funciones: execute_external_command() y execute_internal_command(). La primera función maneja 
la ejecución de comandos externos, mientras que la segunda maneja comandos internos.

La función execute_external_command() recibe un arreglo de cadenas que contiene los argumentos para el comando externo. Primero crea un proceso hijo utilizando fork(). Si el valor de retorno de fork() es cero, el proceso hijo ejecuta el comando utilizando execvp(). Si el valor de retorno de fork() es negativo, se imprime un mensaje de error y se devuelve -1. Si el valor de retorno de fork() es mayor que cero, el proceso padre espera a que el proceso hijo termine utilizando waitpid(), y luego libera la memoria asignada para el arreglo de argumentos.

La función execute_internal_command() recibe un arreglo de cadenas que contiene los argumentos para el comando interno. En esta implementación, esta función no hace nada, ya que no se han implementado comandos internos.

La función principal del programa es main(). La función comienza con la declaración de algunas variables, incluyendo un mensaje de prompt para el usuario, un puntero a la línea ingresada por el usuario y el tamaño de la línea, un delimitador para el tokenizador, y contadores para los bucles.

Dentro del bucle while principal, el programa imprime el mensaje de prompt, lee la entrada del usuario utilizando getline(), y luego utiliza strtok() para dividir la línea ingresada en palabras. El programa utiliza malloc() para asignar memoria para un arreglo de punteros a char, y luego utiliza strtok() de nuevo para almacenar cada palabra en el arreglo.

Después de que el arreglo de argumentos se ha construido, el programa utiliza strcmp() para determinar si el comando ingresado es interno o externo. Si el comando es interno, se llama a la función execute_internal_command(), de lo contrario, se llama a la función execute_external_command().


/*			  
			  _strcmp
Compara dos cadenas de texto

<string.h> /* header */

Declaración: int strcmp(const char *cadena1, const char *cadena2);

Parámetros: Las dos cadenas a comparar

Valor devuelto: Un número entero

Detalles:
Devuelve 0 si las cadenas de texto son iguales (incluyendo mayúsculas y minúsculas); si la primera cadena es mayor que la segunda, devuelve un número positivo; si es mayor la segunda, devuelve un valor negativo. */
		
