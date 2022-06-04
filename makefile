#Ben Elleman

overhead.zip:	makefile *.c *.h
	zip $@ $^

#change the last dependency for each new lab
all:  tags headers overhead

#this entry stays for C code labs
tags: *.c
	ctags -R .

#this entry stays for C code labs
headers: *.c tags
	headers.sh

# this entry takes care of C files depending on header files
# It has the flags for compiling the c code
# It you don't like makefiles, consider typing the following line a few
# thousand times this semester and reconsider.
# Be sure that this one doesn't get an inserted line break anywhere
%.o:%.c *.h
	gcc -ansi -pedantic -Wimplicit-function-declaration -Wreturn-type -Wconversion -g -c $< -o $@

overhead: settings.o encode.o overhead.o fields.o randomness.o
	gcc -g -o $@ $^ -lncurses -L. -lm 

