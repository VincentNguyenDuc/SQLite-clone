#################################### COMMANDS ##########################################

ifeq ($(OSTYPE),cygwin)
	CLEANUP=rm -f
	MKDIR=mkdir -p
	TARGET_EXTENSION=out
else ifeq ($(OS),Windows_NT)
	CLEANUP=del /F /Q
	MKDIR=mkdir
	TARGET_EXTENSION=exe
else
	CLEANUP=rm -f
	MKDIR=mkdir -p
	TARGET_EXTENSION=out
endif

#################################### DIR ###############################################

DB_DIR=./sqlite-db

#################################### MAIN ##############################################
main:
		gcc -o main.${TARGET_EXTENSION} ${DB_DIR}/main.c
		./main.${TARGET_EXTENSION}

##################################### CLEAN ############################################
clean:	
		${CLEANUP} *.${TARGET_EXTENSION}