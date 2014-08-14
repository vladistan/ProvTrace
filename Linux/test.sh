export LD_PRELOAD=`pwd`/call_watcher.so:/lib/x86_64-linux-gnu/libdl.so.2
#export LD_DEBUG=all

echo XXXXXXXXXXXXXXXXXXXX ./test XXXXXXXXXXXXXXXXXXXX
./test
echo XXXXXXXXXXXXXXXXXXXX sha1sum XXXXXXXXXXXXXXXXXXXX
sha1sum test.c
echo XXXXXXXXXXXXXXXXXXXX python XXXXXXXXXXXXXXXXXXXX
python
