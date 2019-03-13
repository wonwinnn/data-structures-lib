TARGET = list

HEADERS = $(wildcard *.h)
SRC = $(wildcard *.c)
OBJS = $(SRC:.c=.o)

CC = gcc
#CFLAGS = -Wall -std=gnu99

#can be deleted, .c can be translated to .o automatically
#use this to "@echo"
%.o:%.c
	@$(CC) -o $@ -c $< 

$(TARGET) : $(OBJS)
	@$(CC) -o $@ $^

$(OBJS) : $(HEADERS)

.PHONY : clean
clean :
	rm $(TARGET) $(OBJS)

