#include <iostream>
#include <iomanip>

using std::cout;
using std::endl;
using std::fixed;
using std::setprecision;

// Function to print the array using pass by reference
void printArray(const int(&ref)[10]) {
	for (int i : ref) {
		cout << i << " ";
	}
	cout << endl;
}

// Function to calculate the sum of the array using pass by pointer (since array has decayed to a pointer)
int calculateSum(const int scores[], int size) {
	int sum = 0;
	for (int i = 0; i < size; i++) {
		sum += scores[i];
	}
	return sum;
}

// Function to calculate the average of the array using pass by value
double getAverage(double sum, int size) {
	return (sum) / size;
}

// Function to add a bonus to each score in the array using pass by pointer
void addBonus(int scores[], int size, int bonus) {
	for (int i = 0; i < size; i++) {
		scores[i] += bonus;
	}
}

// Function to find the minimum score in the array using pass by pointer
int findMinimum(const int scores[], int size) {
	int min = scores[0];
	for (int i = 1; i < size; i++) {
		if (scores[i] < min) {
			min = scores[i];
		}
	}
	return min;
}

// Function to count the number of high performers (scores >= 80) in the array using pass by pointer
int countHighPerformers(const int scores[], int size) {
	int count = 0;
	for (int i = 0; i < size; i++) {
		if (scores[i] >= 80) {
			count++;
		}
	}
	return count;
}

int main() {
	int scores[10] = { 75, 88, 62, 95, 50, 82, 70, 91, 45, 78 };
	const int size = 10;

	cout << "Original scores: ";
	printArray(scores);
	cout << endl << "Sum: " << calculateSum(scores, size) << endl;
	cout << "Average: " << fixed << setprecision(2) << getAverage(calculateSum(scores, size), size) << endl;
	addBonus(scores, size, 10);
	cout << endl << "Scores after +10 bonus: ";
	printArray(scores);
	cout << endl << "Minimum score: " << findMinimum(scores, size) << endl;
	cout << "Number of high performers (>= 80): " << countHighPerformers(scores, size) << endl;
}