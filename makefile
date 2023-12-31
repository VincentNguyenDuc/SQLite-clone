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

MAIN_DIR=./sqlite-db/main.c
INTERFACE_SRC_DIR=./sqlite-db/interface/src/*.c
BACKEND_SRC_DIR=./sqlite-db/backend/src/*.c

#################################### MAIN ##############################################

compile:
		gcc -o db.${TARGET_EXTENSION} ${MAIN_DIR} ${INTERFACE_SRC_DIR}  ${BACKEND_SRC_DIR}

test:
		pytest -vv

##################################### CLEAN ############################################
clean:	
		${CLEANUP} *.${TARGET_EXTENSION}
		${CLEANUP} test_db.db