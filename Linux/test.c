#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <fcntl.h>

void main ()
{
  char xxxx[2222];

  int h = open ( "bb" , O_RDONLY );
  
  read(h,xxxx,22);
  

  printf ( "Got %s \n" , xxxx );
  
}
