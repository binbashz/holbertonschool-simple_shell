 Inside our main.c file, we need to create a new variable that will hold the return value of the getline function.
 This is supposed to be the total number of characters that were read by the function. It is however -1 if it fails or encounter the EOF character.

we will check if the return value is -1 and exit the shell if it is.
EOF

 if (readCharacterCount == -1)
    {
        printf("Exit shell\n");
        return (-1); 

si la variable "readCharacterCount" tiene un valor de -1, se imprime el mensaje "Exit shell" usando la función "printf",
 y luego se retorna -1 como valor de retorno de la función en la línea "return (-1);".
 Esto puede implicar que la función ha encontrado un error o una condición de salida anormal CTRL +D = -1

El siguiente paso después de leer lo que el usuario escribe en la shell es dividir (tokenizar = strtok) el comando en string  individuales
 para que podamos ejecutarlos como comandos.utiliza la bibiloteca <string.h>.
prototipo strtok	char *strtok(char *str, const char *delim);
			@str	 representa la cadena a tokenizar

			@delim   representa qué puede de los caracteres que esperamos separar la cadena que
			 debe usarse como guía para dividir la cadena en trozos más pequeños.
			( significa que se espera que haya ciertos caracteres específicos que actúen como
     			  delimitadores para dividir la cadena en tokens más pequeños.)
