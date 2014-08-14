
OBJS = call_watcher.o
CFLAGS = -g -fPIC -D__USE_GNU=1
TARGETS=test call_watcher.so

all: $(TARGETS)

call_watcher.so: $(OBJS)
	$(CC)  -shared -nostdlib -o $@  $(OBJS) -ldl



test: test.o
	$(CC)  -o $@ $^ -ldl



clean:
	-rm -f $(TARGETS) *.o 


