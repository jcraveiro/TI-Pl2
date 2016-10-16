
FLAGS  = -Wall -g
CC     = gcc
PROG   = GIFMain
OBJS   = writeImageBlockHeader.o GIFencoder.o GIFmain.o LZWCompress.o
all:	${PROG}

clean:
	rm ${OBJS} ${PROG}
  
${PROG}:	${OBJS}
	${CC} ${FLAGS} ${OBJS} -o $@

.c.o:
	${CC} ${FLAGS} $< -c

##########################

GIFencoder.o: GIFencoder.h GIFencoder.c

writeImageBlockHeader.o: GIFencoder.h writeImageBlockHeader.c

GIFmain.o: GIFencoder.h GIFmain.c stb_image.c

LZWCompress.o: LZWCompress.c LZWCompress.h

teste: writeImageBlockHeader.o GIFencoder.o GIFmain.o LZWCompress.o
