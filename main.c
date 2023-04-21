#include "main.h"

int main(int arc, char **argv)
{
    char *user_imput = "(my_sh) c:\\>>$ ";  /* prompt */
    char *lineptr = NULL; /* to store buffer direction, contains what is written.  [getline function] */
    char *lineptr_duplicate = NULL; /* variable to contain the copy of the string to be passed to strtok. */
    size_t n = 0; /* size_t store the assigned size in bytes;  [getline function] */
    size_t readCharacterCount; /* read number of characters the user types */
    const char *delim = "\n"; /* variable to contain the delimiters  [strtok] */
    int number_tokens = 0;
    char *token;
    int i;
     
     
     /* declaring void variables */
    (void)arc; 

while (1) /* create a infinite loop for prompt*/
{ 
    printf("%s", user_imput); 
    readCharacterCount = getline(&lineptr, &n, stdin); /* [getline function]  stdin = stream; */
                                    /* represents the source from which we want the function to get the data from. */
    
    /* Ensure that the getline function didn't encounter any errors, reached the end of file, or if the user used CTRL + D */
    if (readCharacterCount == -1)
    {
        printf("Exit shell\n");
        return (-1); /* ctrl + d = -1 ) exit */
    }

    /* ################################################################################################################### */

 /* allocate space for a copy of the lineptr [getline] */
        lineptr_duplicate = malloc(sizeof(char) * readCharacterCount);
        if (lineptr_duplicate == NULL)
        {
            perror("memory allocation error");
            return (-1);
        }

     /* copy lineptr to lineptr_duplicate */
        _strcpy(lineptr_duplicate, lineptr);


        /********** split the string (lineptr) into an array of words ********/
        /* calculate the total number of tokens */
        token = strtok(lineptr, delim);

        while (token != NULL){
            number_tokens++;
            token = strtok(NULL, delim);
        }
            number_tokens++;
    
    /* Allocate space to hold the array of strings */
        argv = malloc(sizeof(char *) * number_tokens);

    /* Store each token in the array argv  */
        token = strtok(lineptr_duplicate, delim);

        for (i = 0; token != NULL; i++)
        {
            argv[i] = malloc(sizeof(char) * strlen(token));
            _strcpy(argv[i], token);

            token = strtok(NULL, delim);
        }
        argv[i] = NULL;



    printf("%s\n", lineptr); /* printing what was written or saved in *lineptr.  */





    free(lineptr); /* [getline] allocates memory, must be freed */
} 
    
    
    
    return (0);
}
