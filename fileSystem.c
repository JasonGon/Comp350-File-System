#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Project 3

int main() {

	// The user input determines which function to run
	char input[10];

	// Set up a virtual disk. Use w+ so that the file can be written to
	FILE *virtualDisk = fopen("disk.bin", "w+");
	printf("Formatting Disk...\n");

	// Ensure the disk has 100 empty slots. Each can hold 512 bytes
	for (int i = 0; i < 100; i++){
		fwrite("{0}", 512, 1, virtualDisk);
	}

	printf("Disk formatted successfully. FreeMap blocks 0-9 are now allocated.\n");

	// Run forever
	while (true) {

		// Print the commands available
		printf("Available Commands:\n");
		printf("1: format\n2: create <filename>\n3: read <filename>\n4: write <filename> <type the content after the prompt>\n5: delete <filename>\n6: ls\n7: exit\n");

		// Ignore empty lines
		if (fgets(input, 10, stdin) == NULL){
			continue;
		}



	}
}
