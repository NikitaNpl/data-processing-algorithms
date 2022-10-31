#include <iostream>
#include <vector>
#include <string>
#include <ctime>

using namespace std;

vector<int> computePrefix(string P) {
	const int prefixLength = P.length();
	
	/*
		in the i-th element the number of mathing 
		characters at the beginning and end for a
		substring of length i.

		pi[0] = 0 - always;
		pi[1] = 1 - if start with
		two identical elements;
	*/
	vector<int> pi(prefixLength);

	int maxLengthMatchingPrefixAndSuffix = 0;
	for (int i = 1; i < prefixLength; i += 1) {
		while (maxLengthMatchingPrefixAndSuffix > 0 && (P[maxLengthMatchingPrefixAndSuffix] != P[i])) {
			maxLengthMatchingPrefixAndSuffix = pi[maxLengthMatchingPrefixAndSuffix - 1];
		}

		if (P[maxLengthMatchingPrefixAndSuffix] == P[i]) {
			maxLengthMatchingPrefixAndSuffix += 1;
		};

		pi[i] = maxLengthMatchingPrefixAndSuffix;
	}

	return pi;
}

enum kmpMathcerOperations {
	DELETE,
	FIND,
};

void kmpMathcer(string S, string P, kmpMathcerOperations operation = FIND) {
	int patternLength = P.length();

	vector<int> pi = computePrefix(P);

	for (int i = 0, j = 0; i < S.length(); i += 1) {
		// when the symbol does not match, it is necessary to shift the sample by a length equal to the check
		while (j > 0 && (P[j] != S[i])) {
			j = pi[j - 1];
		}

		// character-by-character comparison of a string with a substring
		if (P[j] == S[i]) {
			j += 1;
		}

		// found occurrence of a substring in a string
		if (j == patternLength) {
			if (operation == DELETE) {
				S.erase(i - patternLength + 1, patternLength);
			} else {
				cout << "Образец находится со смещением: " << i - patternLength + 1 << endl;
			}

			j = pi[j - 1];
		}
	}

	cout << S << endl;
}

int main() {
	setlocale(LC_ALL, "Russian");

	clock_t start = clock();

	kmpMathcer("Давно выяснено, что при оценке дизайна и композиции читаемый текст мешает сосредоточиться. Lorem Ipsum используют потому, что тот обеспечивает более или менее стандартное заполнение шаблона, а также реальное распределение букв и пробелов в абзацах, которое не получается при простой дубликации Здесь ваш текст..Здесь ваш текст..Здесь ваш текст.. Многие программы электронной вёрстки и редакторы HTML используют Lorem Ipsum в качестве текста по умолчанию, так что поиск по ключевым словам lorem ipsum сразу показывает, как много веб-страниц всё ещё дожидаются своего настоящего рождения. За прошедшие годы текст Lorem Ipsum получил много версий. Некоторые версии появились по ошибке, некоторые - намеренно (например, юмористические варианты).", "текст", DELETE);

	cout << "Done is: " << (clock() - start) / (double)CLOCKS_PER_SEC << " ms." << endl;

	return 0;
}
