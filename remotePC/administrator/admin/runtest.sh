#!/bin/sh

# Compile
gcc -g -o main  main.c  									\
				./backup/backup.c							\
				../lib/hplib/filesystem.c 					\
				../lib/communication/communication.c 		\
				./serveAdmin/serveAdmin.c 					\
				./adminService/adminService.c 				\
				
# Run
./main 192.168.100.15 9000