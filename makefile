CC = g++
STD = -std=c++11

src1 = $(wildcard ./*.cc)
#src2 = $(wildcard ./src/*.cc)
obj1 = $(patsubst %.cc,%.o,$(src1))
#obj2 = $(patsubst %.cc,%.o,$(src2))
src = ./

target = $(patsubst %.cc,%,$(src1))

INCS += -I ./

LIB_PATCH = -L /usr/lib/x86_64-linux-gnu

CFLAGS += -g

LFLAGS += -lpthread

$(target):$(obj1) #$(obj2)
	$(CC) $(STD) -o $@ $^ $(INCS) $(LIB_PATCH) $(CFLAGS) $(LFLAGS) # -lcurses

%.o:$(src)%.cc
	$(CC) $(STD) -c $< -o $@ $(INCS) $(LIB_PATCH) $(CFLAGS) $(LFLAGS)

# %.o:%.cc
# 	g++ -std=c++11 -c $< -o $@ $(INCS) $(LIB_PATCH) $(CFLAGS) $(LFLAGS)

clean:
	rm -f $(target) $(obj1) $(obj2)
