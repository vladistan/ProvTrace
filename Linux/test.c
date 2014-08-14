#include <stdio.h>
#include <dlfcn.h>

int main()
{
    void* handle;

    open( "12345", 12 );
    handle = dlopen( "somefile", 0 );
}
