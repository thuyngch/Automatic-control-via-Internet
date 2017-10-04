#!/bin/sh

# Remove
rm main
clear

# Compile
gcc -g -o main  main.c  													\
				platform.c  												\
				../lib/frame/frame.c  										\
				../lib/platform/thread.c  									\
				../lib/communication/communication.c 						\
				../lib/fileproc/fileproc.c 									\
				../lib/bufferproc/bufferproc.c 								\
				../lib/json/json.c 											\
				../lib/logfile/logfile.c 									\
				../embedded-shell/embedded_login/embedded_login.c 			\
				../embedded-shell/clientService/clientService.c 			\
				../os-shell/os_shell.c										\
				../os-shell/adminService/backup/backup.c 					\
				../os-shell/adminService/management/management.c 			\
				../os-shell/adminService/history_viewer/history.c 			\
				../os-shell/adminService/configuration/configuration.c  	\
				../os-shell/adminService/adminService.c 					\
				../os-shell/login/login.c 									\
				../embedded-shell/embedded_shell.c 							\
				-lpthread													\
				-ljansson

# Run
./main 