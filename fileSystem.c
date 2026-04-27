#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Project 3

int main() {

	// The user input determines which function to run
	char input[40];

	// Set up a virtual disk
	#define DISK_BLOCKS 100	         // Disk has 100 empty slots
	#define BLOCK_SIZE 512		 // Each disk can hold 512 bytes
	#define RESERVED_BLOCKS 10	 // blocks 0-9 and saves them for free map region
	printf("Formatting Disk...\n");

	// Define the simulated disk, the map for free space, and the file name per block
	static char disk[DISK_BLOCKS][BLOCK_SIZE];
	static unsigned char freeMap[DISK_BLOCKS];	// A 0 means a spot is free and 1 means full
	static char fileTable[DISK_BLOCKS][64];		// " " means no file

	printf("Disk formatted successfully. FreeMap blocks 0-9 are now allocated.\n");

	// Run forever
	while (true) {

		// Print the commands available
		printf("Available Commands:\n");
		printf("1: format\n2: create <filename>\n3: read <filename>\n4: write <filename> <type the content after the prompt>\n5: delete <filename>\n6: ls\n7: exit\n");

		// Ignore empty lines
		if (fgets(input, 40, stdin) == NULL){
			continue;
		}

		// 1. Reformats the entire disk
		if (strcmp(input, "format\n") == 0) {
			printf("\nReformatting disk...\n");
			//for (int i = 0; i < 100; i++){
			//	fwrite("{0}", 512, 1, virtualDisk);
			//}
			printf("\nDone!\n\n");
		}


		// 7. Exit the program
		if (strcmp(input, "exit\n") == 0){
			break;
		}

		// 2. Create a file (WIP)
		if (strcmp(input, "create\n") == 0){
			printf("\nPlease enter a file name:\n");

			char name[100];
			scanf("%s", name);
			//fopen(("disk.bin\{%s}",name), "w");
		}


	}
}
