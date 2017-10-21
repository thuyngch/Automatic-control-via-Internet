#!/bin/sh

# Compile
gcc -g -o main  main.c  											\
				../../lib/communication/communication.c 			\
				../../lib/bufferproc/bufferproc.c 					\
				../../lib/fileproc/fileproc.c 						\
				../../lib/frame/frame.c 							\
				./serveAdmin/serveAdmin.c 							\
				./adminService/adminService.c 						\
				./adminService/backup/backup.c						\
				./adminService/management/management.c 				\
				./adminService/login/admin_login.c 					\
				./adminService/history_viewer/history.c 			\
				./adminService/configuration/configuration.c 		\

				
# Run
./main 127.0.0.1 9000