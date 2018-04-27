export DEBUG

g=gcc -fexec-charset=GBK
ifeq ($(DEBUG), TRUE) 
	g+= -g
endif

build:
	$(g) "$(FILE)" -o debug/$(NAME)

rebuild:clean build

test:test.o
	$(g) debug/test.o -o debug/test

test.o:
	$(g) -c test.c

clean:
	@rm debug/$(NAME).o debug/$(NAME) debug/$(NAME).h.gch debug/$(NAME).exe
