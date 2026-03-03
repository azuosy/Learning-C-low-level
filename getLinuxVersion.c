#include <fcntl.h>
#include <unistd.h>

////////////////////////////////////////
// FOR LEARNING, NOTHING IS LITERALLY //
////////////////////////////////////////

#define BUFFER_MAX_SIZE 1024
////////////////////////////
typedef int FILE_DIRECTORY;

int main(void)
{

 char buffer[BUFFER_MAX_SIZE] = {0};
 FILE_DIRECTORY file = open("version.txt", O_CREAT | O_WRONLY, 0644);
 FILE_DIRECTORY file_data = open("/proc/version", O_RDONLY);

 ssize_t bytes_read = read(file_data, buffer, sizeof(buffer));
 // ssize_t read() -> return bytes read
 // 0 -> EOF, -1 -> Error

 if (bytes_read > 0) 
 {
   write(file, buffer, bytes_read); 
 }

 close(file);
 close(file_data); 

 return 0;
}
