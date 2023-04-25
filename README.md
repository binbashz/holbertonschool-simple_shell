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
			  
El codigo tiene una función execute_external_command que crea un proceso hijo utilizando la función fork() y luego ejecuta un comando externo en el proceso hijo utilizando la función execvp(). El proceso padre espera a que el proceso hijo termine utilizando la función waitpid(). Esta función también libera la memoria asignada a la variable argv. Esta función devuelve 0 si tiene éxito y -1 si falla.

El programa también tiene una función execute_internal_command que maneja comandos internos como "cd" o "exit". Sin embargo, esta función no hace nada y siempre devuelve 0.

El bucle principal del programa (main()) imprime un mensaje de indicador ((my_sh) c:\\>>$ ), lee la entrada del usuario con getline(), y utiliza strtok() para dividir la línea ingresada en tokens (palabras) utilizando como delimitadores los caracteres espacio, tabulación, retorno de carro, nueva línea y alarma.

Luego, el programa cuenta la cantidad de tokens, asigna memoria para un array de punteros a char y almacena cada token en este array.

Finalmente, el programa determina si el comando ingresado es interno o externo. Si es un comando interno, llama a execute_internal_command(). Si es un comando externo, llama a execute_external_command(). El bucle principal se repite hasta que el usuario ingrese EOF o el comando "exit".
			  
			  
		
