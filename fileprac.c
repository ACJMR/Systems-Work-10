#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

int main(){
  int fd;
  int * ray = calloc(10,4);
  int bytes;
  fd = open("/dev/random",O_RDONLY);
  if(fd < 0){
    printf("Error opening random\n");
  }
  else{
    printf("random opened with fd %d\n",fd);
  }
  bytes = read(fd,ray,40);
  if(bytes < 0){
    printf("Error reading random\n");
  }
  else{
    printf("read %d bytes from random\n",bytes);
  }
  close(fd);

  printf("=====Generating random numbers=====\n");
  for (int i = 0; i<10; i++){
    printf("Random number %d: %d\n",i,ray[i]);
  }

  int fd2;
  fd2 = open("file", O_RDWR | O_CREAT,111111111);
  if(fd2 < 0){
    printf("Error opening file\n");
  }
  else{
    printf("file opened with fd %d\n",fd2);
  }
  printf("=====Writing to file=====\n");
  bytes = write(fd2,ray,40);
  if(bytes < 0){
    printf("Error writing to file\n");
  }
  else{
    printf("wrote %d bytes to file\n",bytes);
  }
  close(fd2);

  int fd3;
  fd3 = open("file",O_RDWR);
  if(fd3 < 0){
    printf("Error opening file\n");
  }
  else{
    printf("file opened with fd %d\n",fd3);
  }

  printf("=====Reading from file=====\n");
  int* ray2 = calloc(10,4);
  bytes = read(fd2,ray2,40);
  if(bytes < 0){
    printf("Error reading file\n");
  }
  else{
    printf("read %d bytes from file\n",bytes);
  }
  for (int i = 0; i<10; i++){
    printf("Random number %d: %d\n",i,ray2[i]);
  }
  close(fd3);
}
