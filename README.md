## C - Simple Shell		


School project 
Write a UNIX command line interpreter.


Display a prompt and wait for the user to type a command. A command line always ends with a new line.
The prompt is displayed again each time a command has been executed.
The command lines are simple, no semicolons, no pipes, no redirections or any other advanced features.
The command lines are made only of one word. No arguments will be passed to programs.
If an executable cannot be found, print an error message and display the prompt again.
Handle errors.
You have to handle the “end of file” condition (Ctrl+D).

-----------------------------------------------------------------------------------------------------------

The shell is the interface between the user and the operating system.

The shell is an executable file (program) that acts as an intermediary between the operating system and the user who enters commands in text mode.
Its function is to read the command line, interpret its meaning, execute the command and then output the result via the outputs.



getline() reads an entire line from stream, storing the address
       of the buffer containing the text into *lineptr.  The buffer is
       null-terminated and includes the newline character, if one was
       found.
  
  
  ## /* site under construcction */

El programa utiliza las funciones fork(), execvp() y waitpid() para crear un proceso hijo que ejecuta comandos externos, y espera a que el proceso hijo termine antes de continuar. También incluye la implementación de una función execute_internal_command() para manejar comandos internos como "cd" o "exit".

El programa comienza con la declaración de dos funciones: execute_external_command() y execute_internal_command(). La primera función maneja la ejecución de comandos externos, mientras que la segunda maneja comandos internos.

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
		
