#include <iostream>
#include <vector>


class Quicksort {
	public:
	
	std::vector<int> QArray;

	void InsertElement(int val);
	int Parition(int low, int high);
	void PrintArray();
	void Quicksort_(int low, int high);
};


void Quicksort::InsertElement(int val) {
	QArray.push_back(val);
}

int Quicksort::Parition(int low, int high) {
	
	int midpoint = low + ((high - low) / 2);
	int pivot = QArray[midpoint];
	//printf("Pivot :%i\n", pivot);
	
	int left = low;
	int right = high;

	bool done = false;

	while (!done) {

		// If we are on a smaller element than pivot, keep incrementing until we find an element that is greater than pivot.
		// Then stop.
		while (QArray[left] < pivot) {
			left++; 
		}

		//If we are on a larger element pivot, keep decrementing until we find an element that is less than pivot.
		// Then stop.
		while (QArray[right] > pivot) { 
			right--; 
		}

		

		if (left >= right) {
			//printf("Final Index left %i and right %i\n", left, right);
			done = true;
		}
		else {

			//printf("Swapping left %i with right %i\n", QArray[left], QArray[right]);

			int temp = QArray[left];
			QArray[left] = QArray[right];
			QArray[right] = temp;
			
			left++;
			right--;
		}
		
	}

	return right;
}

void Quicksort::PrintArray() {
	for (int i = 0; i < QArray.size(); i++) {
		std::cout << QArray[i] << " ";
	}
	std::cout << std::endl;
}

void Quicksort::Quicksort_(int low, int high) {
	
	if (low >= high) {
		return;
	}
	
	int lowEndIndex = this->Parition(low, high);
	
	this->Quicksort_(low, lowEndIndex);
	this->Quicksort_(lowEndIndex + 1, high);

}


int main() {

	Quicksort* sort = new Quicksort;

	sort->InsertElement(2); 
	sort->InsertElement(0); 
	sort->InsertElement(1); 
	sort->InsertElement(3); 

	
	sort->PrintArray();

	sort->Parition(0, sort->QArray.size() - 1);
	//sort->Quicksort_(0, sort->QArray.size() - 1);

	sort->PrintArray();

	return 0;
}