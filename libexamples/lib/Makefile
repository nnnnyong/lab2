CC = gcc
CFLAG = -pg -Wall
TARGET1 = libshared.so
TARGET2 = libstatic.a
objects = add.o sub.o mul.o div.o

all : $(TARGET1) $(TARGET2) 

$(TARGET1) : $(objects) 
	gcc -shared -o $@ $^ -pg

$(TARGET2) : $(objects)
	ar -rcs -o $@ $^

.c.o : 
	$(CC) $(CFLAG) -c $^

clean : 
	rm -f libstatic.a libshared.so $(objects)
