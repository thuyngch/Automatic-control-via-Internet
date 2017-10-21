


#!/bin/sh

# clear screen
clear

# Compile
gcc -g -o main  main.c  											\
				../lib/communication/communication.c 					\
				../lib/bufferproc/bufferproc.c 						\
				../lib/fileproc/fileproc.c 							\
				../lib/frame/frame.c 								\
				./serveAdmin/serveAdmin.c 							\
				./adminService/adminService.c 						\
				./adminService/backup/backup.c						\
				./adminService/management/management.c 					\
				./adminService/login/admin_login.c 						\
				./adminService/history_viewer/history.c 					\
				./adminService/configuration/configuration.c 				\

				
# Run
./main 192.168.1.213 9000

# remove old exe file
rm main
