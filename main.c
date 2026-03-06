#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

char *my_strrev(char *str)
{
    char* start = str;
    char* end = str;

    while (*end) {end++;}

    end--;

    while (start < end)
    {
        char temp = *start;
        *start = *end;
        *end = temp;

        start++;
        end--;
    }

    return str;

}

int main(void)
{

    char *p = malloc(20 * sizeof(char)); // char[19] -> final is '\0'

    if (p == NULL)
    {
        perror("Erro");
        exit(EXIT_FAILURE);
    }

    fgets(p, 19, stdin); // Adiciona \n \0 automaticamente no final

    write(STDOUT_FILENO, p, strlen(p));

    free(p);

    char wrd[11] = "malaquiano";
    my_strrev(wrd);
    printf(wrd);

    return 0;
}
