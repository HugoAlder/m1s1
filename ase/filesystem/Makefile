CC	= gcc
CFLAGS	= -m32 -Wall -ansi
CFLAGS  += -g

INCDIR  = -Iinclude
LIBS    = -Llib -lhardware

ALL = bin/mkhd bin/dmps bin/frmt bin/dvol bin/mkvol bin/rmvol bin/test_vol bin/if_nfile bin/if_pfile bin/if_dfile bin/if_cfile

all: $(ALL)

# - Partie 1 ------------------------------------------------------------------#

bin/mkhd: bin/mkhd.o
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

bin/dmps: bin/dmps.o bin/drive.o
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

bin/frmt: bin/frmt.o bin/drive.o
		$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

# - Partie 2 ------------------------------------------------------------------#

bin/dvol: bin/dvol.o bin/drive.o bin/mbr.o
		$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

bin/mkvol: bin/mkvol.o bin/drive.o bin/mbr.o bin/vol.o
		$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

bin/rmvol: bin/rmvol.o bin/drive.o bin/mbr.o bin/vol.o
		$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

# - Partie 3 ------------------------------------------------------------------#

bin/test_vol: bin/test_vol.o bin/drive.o bin/mbr.o bin/vol.o
		$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

# - Partie 4 ------------------------------------------------------------------#

bin/if_nfile: bin/if_nfile.o bin/mbr.o bin/drive.o bin/inode.o bin/vol.o bin/ifile.o
		$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

bin/if_pfile: bin/if_pfile.o bin/mbr.o bin/drive.o bin/inode.o bin/vol.o bin/ifile.o
		$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

bin/if_dfile: bin/if_dfile.o bin/mbr.o bin/drive.o bin/inode.o bin/vol.o bin/ifile.o
		$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

bin/if_cfile: bin/if_cfile.o bin/mbr.o bin/drive.o bin/inode.o bin/vol.o bin/ifile.o
		$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

bin/%.o: src/%.c
	$(CC) $(CFLAGS) -o $@ -c $< $(INCDIR)

%: %.c

.PHONY: clean realclean
clean:
	$(RM) bin/*
realclean: clean
	$(RM) vdiskA.bin vdiskB.bin
