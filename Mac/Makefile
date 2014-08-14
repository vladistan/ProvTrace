
OBJS = call_watcher.o
TARGETS=test call_watcher.dylib
CC = gcc

all: $(TARGETS)

call_watcher.dylib: $(OBJS)
	gcc  -o $@  -dynamiclib $^



test: test.o
	$(CC)  -o $@ $^ -ldl



clean:
	-rm -f $(TARGETS) *.o 


