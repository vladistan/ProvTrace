#include <unistd.h>
#include <stdio.h>
#include <dlfcn.h>

# define RTLD_NEXT      ((void *) -1l)

#define PREFIX "CALLWATCH: "


void* dlopen(const char *file, int mode)
{
    printf ( PREFIX "LibOpen %s \n", file );	

    static void* (*original) ( const char *file, int mode )= NULL;
    
    if ( original == NULL ) {
       original = (void*(*)(const char *file, int mode)) dlsym(RTLD_NEXT, "dlopen");
    }
    return (*original)( file, mode );
}



FILE *fopen (__const char *__restrict __filename,
                    __const char *__restrict __modes)  {


    static FILE* (*original) (__const char *__restrict , __const char *__restrict ) = NULL;  
    printf ( PREFIX "Open %s \n", __filename );	

    if (original == NULL)  { 
       original = (void*)dlsym(RTLD_NEXT, __func__); 
     }

    return original(__filename, __modes);
}

int open (const char * __filename,  int flag, int mode )  {

    typedef int (*func_t)(const char * name, int perm, int mode);
   
    printf ( PREFIX "Open %s \n", __filename );	

    static func_t original = NULL;

    if ( original == NULL )  { 
       original = (func_t)dlsym(RTLD_NEXT, __func__);
    }
    
    return original(__filename, flag, mode);

   
}


