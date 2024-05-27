CC = g++
CFLAGS = -Wall -Wextra
SRCDIR = src
OBJDIR = obj

SRCS = $(wildcard $(SRCDIR)/*.cpp)

OBJS = $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SRCS))

INCDIR = inc
EXEC = run

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CC) $(CFLAGS) -c -o $@ $< -I$(INCDIR)

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ 

clean:
	rm -f $(OBJDIR)/*.o $(EXEC)
