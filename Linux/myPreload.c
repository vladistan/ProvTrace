#include <unistd.h>
#include <stdio.h>
#include <dlfcn.h>

char Arena[2048] = "Bob The Operator";

int  (*xx_open)(char *,int,int) = NULL; 
int  (*xx_printf)(char *,...) = NULL; 

int _init();

int nn_open ( char * file , int flags , int mode )
{
   
   if ( xx_open == NULL ) 
		{ 
		  _init();
		}
   // xx_printf ( "Calling open with %s and %d\n" , file , flags );
   return xx_open( file , flags , mode );
}

int _init ()
{
    
  void * handle; 
  char * error;

  handle = dlopen ( "/lib/libc.so.6" , RTLD_NOW | RTLD_GLOBAL );

  xx_open = dlsym(handle, "open");
  xx_printf = dlsym(handle, "printf");
  access ( Arena , W_OK );

  return 0;

}


