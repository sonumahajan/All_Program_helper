#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#define FOURMB 4194304

int fd,fd2;
long long int chunk, hunk, source_size;
float percentage;
char* BUFFER;
char* BUFFER2;
char* PROGRESS;

char* base(char* input) //gets basename of relative/absolute address
{ 
    if(strchr(input, '/') != NULL) return strrchr(input, '/') + 1;
    return input;
}

void reverse(long long int size, long long int source_size) //reverses contents of buffer
{ 
    read(fd, BUFFER, size); //reads chunk from source file

    for(long long int i = 0, j = size - 1; i < size; i++, j--) BUFFER2[i] = BUFFER[j]; //reversing buffer and storing in BUFFER2    
    
    write(fd2, BUFFER2, size); //writes reversed chunk to destination file
    lseek(fd, -(size + FOURMB), SEEK_CUR); //moves cursor to start of previous chunk

    sprintf(PROGRESS, "\r%.2f%%", percentage*100); //updating progress bar
    // write(1, PROGRESS, strlen(PROGRESS));
    percentage += (float)size/source_size;
}

int main(int argc, char* argv[])
{
    char dest[50] = "Final/1_";
    strcat(dest,base(argv[1])); //dest holds the name of the destination file

    mkdir("Assignment", 0700); //creating "Assignment" directory

    fd2 = open(dest, O_CREAT | O_RDWR | O_TRUNC, 0600); //creating the destination file with correct name
    if(fd2 == -1)
    {
        perror("File error");
        return 0;
    }
    fd = open(argv[1], O_RDONLY); //opening source file in read only mode
    if(fd == -1)
    {
        perror("File error");
        return 0;
    }

    source_size = lseek(fd, 0, SEEK_END); // holds size of file
    BUFFER = (char*)calloc(FOURMB,sizeof(char)); //buffer to read chunks of file
    BUFFER2 = (char*)calloc(FOURMB,sizeof(char)); //buffer that holds the contents of BUFFER but reversed
    PROGRESS = (char*)malloc(sizeof(char*)); //strings used to display progress bar

    chunk = source_size / FOURMB; //number of chunks in file
    hunk = source_size % FOURMB; //the remaining characters at EOF that arent in any chunk

    lseek(fd, chunk * FOURMB, SEEK_SET); //setting cursor at the beginning of hunk
    
    percentage = 0; 

    reverse(hunk, source_size); //reverses hunk, writes to the destination file, updates progress bar
    while(chunk--) reverse(FOURMB, source_size); //reverses chunk, writes to the destination file, updates progress bar

    // write(1, "\r100.00%\n",strlen("\r100.00%\n"));

    close(fd); //closing source file
    close(fd2); //closing destination file
}
