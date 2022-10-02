#include <iostream>
#include <bitset>
#include <time.h>

#include "BitOperationsUnsignedChar.h"

using namespace std;

#define UNS_INT_BIT 32
#define MAX_NUM 312500
#define BIT_SIZE MAX_NUM * 4

#define INPUT_FILE "unsorted.txt"
#define SORTED_FILE "sorted.txt"

void putIntoBitMap(unsigned int* bitmap, int num) {
	unsigned int currentIndex = num / UNS_INT_BIT;
	bitmap[currentIndex] |= (1 << (UNS_INT_BIT - 1 - (num % UNS_INT_BIT)));
}

void readFileToBitMap(unsigned int* bitmap, FILE* file) {
	while (!feof(file)) {
		int num;
		fscanf_s(file, "%d", &num);
		putIntoBitMap(bitmap, num);
	}
}

void printBitMapToFile(unsigned int* bitmap, FILE* file) {
	for (int i = 0; i < MAX_NUM; i += 1) {
		unsigned int maska = 1 << (UNS_INT_BIT - 1);
		for (int j = 0; j < UNS_INT_BIT; j += 1) {
			if ((bitmap[i] & maska) != 0) {
				const int num = j + (UNS_INT_BIT * i);
				fprintf(file, "%d", num);
			}
		}
	}
}

int main() {
	clock_t tStart = clock();

	FILE* unsortedFile;

	fopen_s(&unsortedFile, INPUT_FILE, "r");

	if (unsortedFile == NULL) {
		cout << "The file was not opened" << endl;
		return -1;
	}

	unsigned int* bitmap = (unsigned int*)calloc(MAX_NUM, sizeof(unsigned int));

	if (bitmap == NULL) {
		fclose(unsortedFile);
		cout << "Bitmap was not created" << endl;
		return -1;
	}

	readFileToBitMap(bitmap, unsortedFile);

	fclose(unsortedFile);

	FILE* sortedFile;

	fopen_s(&sortedFile, SORTED_FILE, "w+");

	if (sortedFile == NULL) {
		free(bitmap);
		cout << "The file was not opened" << endl;
		return -1;
	}

	printBitMapToFile(bitmap, sortedFile);

	fclose(sortedFile);
	free(bitmap);
	bitmap = NULL;

	cout << "Done in " << (double)(clock() - tStart) / CLOCKS_PER_SEC << "s." << endl;

	return 0;
}