# output paths
OUTPUT_PATH = output
MAIN_PATH = $(OUTPUT_PATH)/main
DISPLAY_PATH = $(OUTPUT_PATH)/display

# Compiler flags
COMPILER_FLAGS = -Wall

# Check if disable warnings flag is settled and is equal with 1
ifdef warnings_s
ifeq ($(warnings_s), 1)
GCC = gcc
endif
endif

ifndef GCC
GCC = gcc $(COMPILER_FLAGS)
endif


#TODO: Create flag for Windows/Linux for linked file

.PHONY = create_output_folders
create_output_folders:
	@mkdir -p $(OUTPUT_PATH)
	@mkdir -p $(DISPLAY_PATH)
	@mkdir -p $(MAIN_PATH)

all: display main
	$(GCC) $(MAIN_PATH)/main.o $(DISPLAY_PATH)/display.o -o $(OUTPUT_PATH)/start_game

	@chmod +x $(OUTPUT_PATH)/start_game
#	Create symlink for the runnable
	@ln -f -s $(OUTPUT_PATH)/start_game start_game

display: create_output_folders display/display.c
	$(GCC) -c display/display.c -o $(DISPLAY_PATH)/display.o
#	Copy the templates folder to output
	@cp -r templates $(OUTPUT_PATH)/templates

main: create_output_folders main.c
	$(GCC) -c main.c -o $(MAIN_PATH)/main.o

.PHONY = clean
clean:
#	Clean all output directory
# 	-f flag is used to avoid exiting with error if the folder doesn't exist 
	rm -r -f $(OUTPUT_PATH)
	rm -f start_game

TODO: make help menu for flags and commands
