CPPFILES = main.cpp add.cpp foo.cpp goo.cpp a.cpp
PROG = main
CC = g++
CPPFLAGS = -Wall -Weffc++ -Wextra -Wsign-conversion
OBJS = main.o add.o

$(PROG) : $(OBJS)
	$(CC) $(CPPFLAGS) -o $(PROG) $(CPPFILES)

clean:
	rm -f core $(PROG) $(OBJS)
