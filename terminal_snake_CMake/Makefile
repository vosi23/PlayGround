# output paths
OUTPUT_PATH = output
MAIN_PATH = $(OUTPUT_PATH)/main
MENU_PATH = $(OUTPUT_PATH)/menu
DISPLAY_PATH = $(OUTPUT_PATH)/display

# OS_ENV == 1 -> Windows
# OS_ENV == 2 -> Linux 
OS_ENV1 = WINDOWS_ENV
OS_ENV2 = LINUX_ENV

# Compiler flags
COMPILER_FLAGS = -Wall

# mandatory parameter, if doesn't exist then the make will fail
ifndef OS_ARG
$(error Mandatory parameter not set, OS_ARG! Check the help menu: make help)
endif

# set the OS if the parameter exist's
ifeq ($(OS_ARG), 1)
	OS_ENV = $(OS_ENV1)
endif
ifeq ($(OS_ARG), 2)
	OS_ENV = $(OS_ENV2)
endif

# Check if disable warnings flag is settled and is equal with 1
ifdef warnings_s
ifeq ($(warnings_s), 1)
GCC = gcc -D$(OS_ENV)
endif
endif

ifndef GCC
GCC = gcc $(COMPILER_FLAGS) -D$(OS_ENV)
endif


#TODO: Create flag for Windows/Linux for linked file

.PHONY = create_output_folders
create_output_folders:
	@mkdir -p $(OUTPUT_PATH)
	@mkdir -p $(DISPLAY_PATH)
	@mkdir -p $(MENU_PATH)
	@mkdir -p $(MAIN_PATH)

all: display menu main
	$(GCC) $(MAIN_PATH)/main.o $(DISPLAY_PATH)/display.o $(MENU_PATH)/menu.o -o $(OUTPUT_PATH)/start_game

	@chmod +x $(OUTPUT_PATH)/start_game
#	Create symlink for the runnable
	@ln -f -s $(OUTPUT_PATH)/start_game start_game

display: create_output_folders display/display.c
	$(GCC) -c display/display.c -o $(DISPLAY_PATH)/display.o
#	Copy the templates folder to output
	@cp -r templates $(OUTPUT_PATH)/templates

menu: create_output_folders menu/menu.c
	$(GCC) -c menu/menu.c -o $(MENU_PATH)/menu.o

main: create_output_folders main.c
	$(GCC) -c main.c -o $(MAIN_PATH)/main.o

.PHONY = clean
clean:
#	Clean all output directory
# 	-f flag is used to avoid exiting with error if the folder doesn't exist 
	rm -r -f $(OUTPUT_PATH)
	rm -f start_game

# TODO: make help menu for flags and commands
