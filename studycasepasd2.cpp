#include <iostream>
using namespace std;

// QUICK SORT (descending)
void quick(string array[], int awal, int akhir) {

	int low = awal, high = akhir;
	string pivot = array[(awal + akhir) / 2];

	do {
		while (array[low] > pivot)   // dibalik utk descending
		low++;

		while (array[high] < pivot)  // dibalik utk descending
		high--;
	
		if (low <= high) {
			swap(array[low], array[high]);
			low++;
			high--;
		}
		
	} while (low <= high);

	if (awal < high)
		quick(array, awal, high);
	if (low < akhir)
		quick(array, low, akhir);
}

int main() {

	int n;
	cout << "Masukkan jumlah mahasiswa: ";
	cin >> n;
	cin.ignore();
	string nama[n];

	// input nama
	for (int i = 0; i < n; i++) {
		cout << "Masukkan nama ke-" << i+1 << ": ";
		getline(cin, nama[i]);
	}

	string namaquick[n];
	for (int i = 0; i < n; i++) {
		namaquick[i] = nama[i];
	}

	// BUBBLE SORT (ascending)
	for (int i = 0; i < n-1; i++) {
		for (int j = 0; j < n-1-i; j++) {
			if (nama[j] > nama[j + 1]) {
				string temp = nama[j + 1];
				nama[j + 1] = nama[j];
				nama[j] = temp;
			}
		}
	}

	cout << "\nData setelah Bubble Sort (Ascending):" << endl;
	for (int i = 0; i < n; i++) {
		cout << nama[i] << endl;
	}

	// QUICK SORT (descending)
	quick(namaquick, 0, n-1);

	cout << "\nData setelah Quick Sort (Descending):" << endl;
	for (int i = 0; i < n; i++) {
		cout << namaquick[i] << endl;
	}

	return 0;
}
