#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 1024

// A COPY OF COMMAND CAT, MOVE THE BIN FOR /USR/BIN FOR USE WITHOUT "./"

int main(int argc, char** argv)
{
  if (argc != 2)
  {
    printf("Usage: caty [FILE] \n");
    exit(EXIT_FAILURE);
  }

  if (strcmp(argv[1], "--help") == 0 || strcmp(argv[1], "-h") == 0)
  {
    printf("Usage: caty [FILE] \n only this lol!? \n ");
    exit(EXIT_SUCCESS);
  }

  // CODE. I DONT NEED FUNCTIONS !?

  char buffer[MAX_BUFFER_SIZE] = {0};
  int fd;
  ssize_t bytes_read;

  if ( (fd = open(argv[1], O_RDONLY)) == -1)
  {
    perror("Error");
    exit(EXIT_FAILURE);
  }

  while ( (bytes_read = read(fd, buffer, sizeof(buffer))) > 0 )
  {
    write(STDOUT_FILENO, buffer, sizeof(bytes_read));
  }

  close(fd);

  return 0;
}

// strcmp() -> compare two strings, s1 and s2 | return an integer indicating the result of the comparasion
// [0, if the s1 and s2 are equal, a negative value if s1 is less than s2, a positive value if s1 is greater than s2]