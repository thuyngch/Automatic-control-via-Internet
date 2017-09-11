#!/bin/sh

# Compile
gcc -g -o main  main.c  									\
				./backup/backup.c							\
				../lib/hplib/filesystem.c 					\
				../lib/communication/communication.c 		\
				
# Run
./main 127.0.0.1 8000