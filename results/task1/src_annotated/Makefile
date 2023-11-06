PRJ = HyperLCA
CC = icpx

#INCLUDEDIR=~/intel/oneapi/advisor/latest/sdk/include/advisor-annotate.h
#OBJDIR=~/intel/oneapi/advisor/latest/sdk/lib64/advisor-annotate.mod

SRCS  = Main_Compresor_HW.cpp HyperLCA_Transform_Operations.cpp
OBJS = $(SRCS:.c=.o)


CFLAGS += -g -Wall -O1
CPPFLAGS += -fopenmp #-I$(INCLUDEDIR)
LDFLAGS += -D VERBOSE -D BLOCK_DBG=1 #-l$(OBJDIR)


all : $(PRJ)

%.o : %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $^

$(PRJ): $(OBJS)
	$(CC) $(CPPFLAGS) $(LDFLAGS) $^ -o $@

mission.bin:
	megadl 'https://mega.nz/file/Z5JUkSoI#boptGx0TD4YU1FGz5WxVkxgB0-fav1sQiVVCk2lz_CA'

run: $(PRJ) mission.bin
	./$(PRJ)


clean:
	$(RM) -rf $(PRJ) *~ *.o compressedBitstream.bin output

cleanall: clean
	$(RM) -rf mission.bin
