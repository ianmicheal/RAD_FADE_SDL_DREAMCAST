#
# INTRO FADE WAV MOD CROSS FADE
# (c)2003 reaper2k2   RADsoft
#   

TARGET = modpic.elf
OBJS =  modpic.o

KOS_LOCAL_CFLAGS += -I$(KOS_BASE)/include/SDL_mixer
KOS_LOCAL_CFLAGS += -I$(KOS_BASE)/include/SDL_image
KOS_LOCAL_CFLAGS += -I$(KOS_BASE)/include/SDL_ttf



all: rm-elf $(TARGET)

include $(KOS_BASE)/Makefile.rules

KOS_CFLAGS +=  -ml -m4-single-only -pipe

clean:
	-rm -f $(TARGET) $(OBJS) romdisk.*

rm-elf:
	-rm -f $(TARGET) romdisk.*

$(TARGET): $(OBJS) romdisk.o
	$(KOS_CC) $(KOS_CFLAGS) $(KOS_LDFLAGS) -o $(TARGET) $(KOS_START) \
		$(OBJS) romdisk.o $(OBJEXTRA) -L$(KOS_BASE)/lib -lgcc -lRAD_fade  -lSDL -lSDL_image -lpng -lz -ljpeg  -lSDL_mixer -lSDL -loggvorbisplay -ltremor -lk++ -lm  $(KOS_LIBS)

romdisk.img:
	$(KOS_GENROMFS) -f romdisk.img -d romdisk -v

romdisk.o: romdisk.img
	$(KOS_BASE)/utils/bin2o/bin2o romdisk.img romdisk romdisk.o

run: $(TARGET)
	$(KOS_LOADER) $(TARGET)


