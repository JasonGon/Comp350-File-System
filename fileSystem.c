
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
	printf("\nFormatting Disk...\n");

	// Define the simulated disk, the map for free space, and the file name per block
	static char disk[DISK_BLOCKS][BLOCK_SIZE];
	static unsigned char freeMap[DISK_BLOCKS];	// A 0 means a spot is free and 1 means full
	static char fileTable[DISK_BLOCKS][64];		// " " means no file

	printf("\nDisk formatted successfully. FreeMap blocks 0-9 are now allocated.\n");

	// Run forever
	while (true) {

		// Flush the stream
		fflush(stdout);

		// Print the commands available
		printf("\nAvailable Commands:\n");
		printf("1: format\n2: create <filename>\n3: read <filename>\n4: write <filename> <type the content after the prompt>\n5: delete <filename>\n6: ls\n7: exit\n\n");

		// Ignore empty lines
		if (fgets(input, 40, stdin) == NULL){
			continue;
		}

		// 1. Reformats the entire disk
		else if (strcmp(input, "format\n") == 0) {
			printf("\nReformatting disk...\n");

			// Wipe the freeMap and fileTable
			for (int i = 10; i < 100; i++){

				// If the slot has something, remove it
				if (freeMap[i] == 1){
					freeMap[i] = 0;
					strcmp(fileTable[i], "");
				}
			}
			printf("\nDone!\n\n");
		}


		// 7. Exit the program
		else if (strcmp(input, "exit\n") == 0){
			break;
		}

		// 2. Create a file
		else if (strcmp(input, "create\n") == 0){
			printf("\nPlease enter a file name:\n");

			char name[100];		// Name will be the new file created
			scanf("%s", name);

			// Loop through the freeMap until you find an empty slot
			for (int i = 10; i < 100; i++){
				if (freeMap[i] == 0){
					// That spot becomes the new file
					freeMap[i] = 1;
					strcpy(fileTable[i], name);
					break;
				}
			}
			printf("\nDone!\n\n");
		}

		// 6. LS (Reads all files on the disk)
		else if (strcmp(input, "ls\n") == 0){

			// Loop through each spot
			for (int i = 10; i < 100; i++){

				// If there is something there, print it
				if (freeMap[i] == 1){
					printf("\n%s\n\n", fileTable[i]);
				}
			}
		}


	}
}
