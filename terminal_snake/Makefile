# output paths
OUTPUT_PATH = output
MAIN_PATH = $(OUTPUT_PATH)/main
DISPLAY_PATH = $(OUTPUT_PATH)/display

#TODO: Create flag for Windows/Linux

.PHONY = create_output_folders
create_output_folders:
	@mkdir -p $(OUTPUT_PATH)
	@mkdir -p $(DISPLAY_PATH)
	@mkdir -p $(MAIN_PATH)

all: display main
	gcc $(MAIN_PATH)/main.o $(DISPLAY_PATH)/display.o -o $(OUTPUT_PATH)/start_game

	chmod +x $(OUTPUT_PATH)/start_game
#	Create symlink for the runnable
	ln -f -s $(OUTPUT_PATH)/start_game start_game

display: create_output_folders display/display.c
	gcc -c display/display.c -o $(DISPLAY_PATH)/display.o
#	Copy the templates folder to output
	cp -r templates $(OUTPUT_PATH)/templates

main: create_output_folders main.c
	gcc -c main.c -o $(MAIN_PATH)/main.o

.PHONY = clean_all
clean_all:
#	Clean all output directory
# 	-f flag is used to avoid exiting with error if the folder doesn't exist 
	rm -r -f $(OUTPUT_PATH)
	rm -f start_game
