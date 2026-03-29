CC = gcc
CFLAGS = -Wall -Wextra -std=c99
OBJS = cliente.o lista_dupla.o fila.o pilha.o interface.o main.o
TARGET = sistema_captacao

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	del /Q *.o $(TARGET).exe 2>NUL || rm -f *.o $(TARGET)
