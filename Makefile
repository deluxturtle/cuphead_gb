#
# Simple Makefile that compiles all .c and .s files in the same folder
#

# If you move this project you can change the directory 
# to match your GBDK root directory (ex: GBDK_HOME = "C:/GBDK/"
GBDK_HOME = "/opt/gbdk/"

LCC = $(GBDK_HOME)bin/lcc
SDAR = $(GBDK_HOME)/bin/sdar
# PNG2MTSPR = $(GBDK_HOME)bin/png2asset

ifndef RGBDS_HOME
#default location after installing rgbds :p
RGBDS_HOME = ../usr/local/bin
endif 

RGBASM = $(RGBDS_HOME)/rgbasm



# You can uncomment the line below to turn on debug output
#LCC = $(LCC) 

# You can set the name of the .gb ROM file here
PROJECTNAME    = Cuphead



# Add entries here to have them converted into metasprites
# PNGSOURCES   = sprite_player_idle.png sprite_player_fire.png
# PNG_CSOURCES = $(PNGSOURCES:%.png=%.c)
# PNG_CHEADERS = $(PNGSOURCES:%.png=%.h)


# List of all C source files except those generated by png2mtspr
SRCDIR      = src
OBJDIR      = obj
RESDIR      = res
BUILD_DIR   = build

BINS	    = $(BUILD_DIR)/$(PROJECTNAME).gb
CSOURCES    = $(foreach dir,$(SRCDIR),$(notdir $(wildcard $(dir)/*.c))) $(foreach dir,$(RESDIR),$(notdir $(wildcard $(dir)/*.c)))
ASMSOURCES  = $(foreach dir,$(SRCDIR),$(notdir $(wildcard $(dir)/*.s)))
OBJS       = $(CSOURCES:%.c=$(OBJDIR)/%.o) $(ASMSOURCES:%.s=$(OBJDIR)/%.o) $(OBJDIR)/hUGEDriver.o

all:	prepare $(BINS)

make.bat: Makefile
	@echo "REM Automatically generated from Makefile" > make.bat
	@make -sn | sed y/\\//\\\\/ | grep -v make >> make.bat

# Use png2mtspr to convert the png into C formatted metasprite data
# -sh 48   : Sets sprite height to 48 (width remains automatic)
# -spr8x16 : Use 8x16 hardware sprites
# -c ...   : Set C output file
# %.c:	%.png
# 	$(PNG2MTSPR) $< -sh 16 -spr8x8 -c $@ 

# Compile .c files in "src/" to .o object files
$(OBJDIR)/%.o:	$(SRCDIR)/%.c
	$(LCC) $(LCCFLAGS) -c -o $@ $<

# Compile .c files in "res/" to .o object files
$(OBJDIR)/%.o:	$(RESDIR)/%.c
	$(LCC) $(LCCFLAGS) -c -o $@ $<

# Compile .s assembly files in "src/" to .o object files
$(OBJDIR)/%.o:	$(SRCDIR)/%.s
	$(LCC) $(LCCFLAGS) -c -o $@ $<

# If needed, compile .c files in "src/" to .s assembly files
# (not required if .c is compiled directly to .o)
$(OBJDIR)/%.s:	$(SRCDIR)/%.c
	$(LCC) $(LCCFLAGS) -S -o $@ $<
	
# Link the compiled object files into a .gb ROM file
$(BINS):	$(OBJS)
	$(LCC) $(LCCFLAGS) -o $(BINS) $(OBJS)

prepare:
	mkdir -p $(OBJDIR)

clean:
#	rm -f  *.gb *.ihx *.cdb *.adb *.noi *.map
	rm -f  $(OBJDIR)/*.*
