/*
##############
#
# Author: silentcat
# Date: 2018-03-20
# Description: Prunsigned longs out Pascal's Triangle to a certain number of rows.
#
##############
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Prunsigned longs out a row of Pascal's Triangle. */
void
print_row(unsigned long buffer[], unsigned long row_len)
{
	unsigned long i = 0;
	for (i = 0; i < row_len; i++) // Loop through the buffer row_len times.
	 	printf("%5ld ", buffer[i]); // Prunsigned long out the number in the index.
	printf("\n"); // Prunsigned long a newline to terminate the row.
	return;

}

/* Creates a new row given the previous one. */
unsigned long *
create_row(unsigned long buffer[], unsigned long row_len)
{
	unsigned long lrlen = row_len - 1, buff_cpy[lrlen], i, k = 0; // Create a copy to hold the current row.
	memcpy(buff_cpy, buffer, lrlen * sizeof(unsigned long)); // Copy the current row.
	memset(buffer, 0, row_len * sizeof(unsigned long)); // Clear the current buffer for the row.
	/* Assign the first and last values to 1. */
	buffer[0] = 1;
	buffer[lrlen] = 1;
	/* Loop through indices 1 to lrlen to determine the others. */
	for (i = 1; i < lrlen; i++)
	 {
		if (k < lrlen) // Check that k < lrlen (the length of buff_cpy);
			buffer[i] = buff_cpy[k] + buff_cpy[k + 1]; // Obtain the current index.
		else 
			break; // If k !< lrlen, then break the loop.
		++k; // Increment k.
	 }

	return buffer;
}

int
main(int argc, char *argv[])
{

	if (argc != 2) // Check for the correct number of arguments.
	 {
		fprintf(stderr, "Usage: ./pascal [row_num]\n"); // If not, then print the usage format out.
		return -1;
	 }

	unsigned long rlen = strtol(argv[1], NULL, 10); // Convert the argument unsigned longo an unsigned longeger.
	if (rlen == 0 && strcmp(argv[1], "0")) // Check if rlen = 0 but the argument given is not 0.
	 {
		perror("strtol");
		return -1;
	 }

	unsigned long *buffer = calloc(rlen, sizeof(unsigned long)); // Allocate memory to buffer.
	if (!buffer) // Check that the buffer was allocated.
	 {
		perror("calloc");
		return -1;
	 }

	memset(buffer, 0, rlen * sizeof(unsigned long)); // Clear the memory of the buffer.
	printf("%5d\n", 1); // Prunsigned long out the first 1 row.

	unsigned long sec_row[3] = { 1, 2, 1 }, i = 0, size = 3; 
	memcpy(buffer, sec_row, 3 * sizeof(unsigned long)); // Copy the buffer to the pre-created 1 2 1 row.
	for (i = 1; i < rlen; i++) // Set i to 1 (we prunsigned longed out the first row) and loop until the end.
	 {
		print_row(buffer, size); // Prunsigned long the row.
		create_row(buffer, ++size); // Create the next row (increment the size).
	 }

	free(buffer); // Deallocate memory to the buffer.
	return 0;
}
