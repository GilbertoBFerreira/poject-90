FLAGS= -std=c99 -O2 -D_GNU_SOURCE -ggdb3  
PKG = `pkg-config --cflags --libs glib-2.0` `pkg-config --libs glib-2.0`
COMPILER=gcc
HEADERS=includes
SRC=src
OBJ=obj

# all: main drivers parseDrives users parseUsers rides parseRides querries catalogo exec testes 
all : main datas users parseUsers exec

main: $(SRC)/main.c $(HEADERS)/main.h 
	$(COMPILER) $(FLAGS) -o $(OBJ)/main.o $(PKG) -c $(SRC)/main.c

# drivers: $(SRC)/drivers.c $(HEADERS)/drivers.h 
# 	$(COMPILER) $(FLAGS) -o $(OBJ)/drivers.o $(PKG) -c $(SRC)/drivers.c

# parseDrives: $(SRC)/parseDrives.c $(HEADERS)/parseDrives.h 
# 	$(COMPILER) $(FLAGS) -o $(OBJ)/parseDrives.o $(PKG) -c $(SRC)/parseDrives.c

 users: $(SRC)/users.c $(HEADERS)/users.h 
	$(COMPILER) $(FLAGS) -o $(OBJ)/users.o $(PKG) -c $(SRC)/users.c

 parseUsers: $(SRC)/parseUsers.c $(HEADERS)/parseUsers.h 
	$(COMPILER) $(FLAGS) -o $(OBJ)/parseUsers.o $(PKG) -c $(SRC)/parseUsers.c

 datas: $(SRC)/datas.c $(HEADERS)/datas.h 
	$(COMPILER) $(FLAGS) -o $(OBJ)/datas.o $(PKG) -c $(SRC)/datas.c

# rides: $(SRC)/rides.c $(HEADERS)/rides.h 
# 	$(COMPILER) $(FLAGS) -o $(OBJ)/rides.o $(PKG) -c $(SRC)/rides.c

# parseRides: $(SRC)/parseRides.c $(HEADERS)/parseRides.h 
# 	$(COMPILER) $(FLAGS) -o $(OBJ)/parseRides.o $(PKG) -c $(SRC)/parseRides.c

# querries: $(SRC)/querries.c $(HEADERS)/querries.h
# 	$(COMPILER) $(FLAGS) -o $(OBJ)/querries.o $(PKG) -c $(SRC)/querries.c

# catalogo: $(SRC)/catalogo.c $(HEADERS)/catalogo.h 
# 	$(COMPILER) $(FLAGS) -o $(OBJ)/catalogo.o $(PKG) -c $(SRC)/catalogo.c

exec: $(SRC)/main.c $(OBJ)/users.o $(OBJ)/parseUsers.o $(OBJ)/datas.o $(OBJ)/main.o 
	$(COMPILER) $(FLAGS) $(OBJ)/users.o $(OBJ)/parseUsers.o $(OBJ)/datas.o $(OBJ)/main.o $(PKG) -o exec

# exec: $(SRC)/main.c $(OBJ)/drivers.o $(OBJ)/parseDrives.o $(OBJ)/users.o $(OBJ)/parseUsers.o $(OBJ)/rides.o $(OBJ)/parseRides.o $(OBJ)/querries.o $(OBJ)/catalogo.o $(OBJ)/main.o
# 	$(COMPILER) $(FLAGS) $(OBJ)/drivers.o $(OBJ)/parseDrives.o $(OBJ)/users.o $(OBJ)/parseUsers.o $(OBJ)/rides.o $(OBJ)/parseRides.o $(OBJ)/querries.o $(OBJ)/catalogo.o $(OBJ)/main.o $(PKG) -o exec

# testes: $(OBJ)/drivers.o $(OBJ)/parseDrives.o $(OBJ)/users.o $(OBJ)/parseUsers.o $(OBJ)/rides.o $(OBJ)/parseRides.o $(OBJ)/catalogo.o $(OBJ)/querries.o $(OBJ)/main.o
# 	$(COMPILER) $(FLAGS) $(OBJ)/drivers.o $(OBJ)/parseDrives.o $(OBJ)/users.o $(OBJ)/parseUsers.o $(OBJ)/rides.o $(OBJ)/parseRides.o $(OBJ)/querries.o $(OBJ)/catalogo.o $(OBJ)/main.o $(PKG) -o testes 
