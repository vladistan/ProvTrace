#opejexport DYLD_PRINT_LIBRARIES=1
#export DYLD_PRINT_BINDINGS=1
export DYLD_INSERT_LIBRARIES=`pwd`/call_watcher.dylib 

echo XXXXXXXXXXXXXXXXXXXX python XXXXXXXXXXXXXXXXXXXX
python
echo XXXXXXXXXXXXXXXXXXXX ./test XXXXXXXXXXXXXXXXXXXX
./test
echo XXXXXXXXXXXXXXXXXXXX sha1sum XXXXXXXXXXXXXXXXXXXX
shasum test.c