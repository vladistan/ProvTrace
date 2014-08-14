#include <unistd.h>
#include <stdio.h>
#include <dlfcn.h>


#define PREFIX "CALLWATCH: "



typedef struct interpose_s {

   void * new_func;
   void * old_func;

} interpose_t;


int my_open ( const char *, int, int );
void* my_dlopen(const char* path, int mode);
FILE *my_fopen (__const char *__restrict __filename,
                    __const char *__restrict __modes); 
int open (const char * __filename,  int flag, int mode );


static const interpose_t interposers[] \
	__attribute__  ((section("__DATA, __interpose"))) = {
  
	{ (void*) my_open, open },
	{ (void*) my_fopen, fopen },
	{ (void*) my_dlopen, dlopen }

};


void* my_dlopen(const char *file, int mode)
{
   printf ( PREFIX "LibOpen %s \n", file );
   
   return dlopen(file, mode); 
}


FILE *my_fopen (__const char *__restrict __filename,
                    __const char *__restrict __modes)  {

    printf ( PREFIX "Open %s \n", __filename );	

    return fopen(__filename, __modes);
}

int my_open (const char * __filename,  int flag, int mode )  {

    
    printf ( PREFIX "Open %s \n", __filename );	
    return open(__filename, flag, mode);

}



