
all: seconds

seconds: seconds.c
	gcc -Wall seconds.c -o seconds

clean:
	rm -f seconds

dist:
	tar -cvzf dist1.tgz Makefile seconds.c
