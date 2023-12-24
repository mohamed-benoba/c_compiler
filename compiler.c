#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 
  This code is designed to read a charcter by charcter from a file and put it in another file
  Date: 13/12/2023
  Name: Mohamed Ben Nouba
  StudentID: 2201805516
*/

void main() {
  // Open the file
  FILE* readFilePointer;
  readFilePointer = fopen("text_file.txt", "r");

  // Create a file
  FILE* writeFilePointer;
  writeFilePointer = fopen("output_text.txt", "w");

  // Set all value to \0 to avoid garbage
  char dataToBeWritten[1000] = {0};

  // if file doesn't exist
  if(readFilePointer == NULL) {
    printf("Input file not found");
    exit(0);
  }

  if(writeFilePointer == NULL) {
    printf("An error occure when creating the file");
    exit(0);
  }

  // Read charcter by charcter
  int charAsInteger;
  int i = 0;
  while ((charAsInteger = fgetc(readFilePointer)) != EOF) {
    dataToBeWritten[i] = charAsInteger;
    i++;
  }

  // Add null terminator to avoid garbage
  dataToBeWritten[i] = '\0';

  // Close the input file
  fclose(readFilePointer);

  // Write in the output file
  fputs(dataToBeWritten, writeFilePointer);

  // Close the output file
  fclose(writeFilePointer); 
  printf("Written Successfully!");


}