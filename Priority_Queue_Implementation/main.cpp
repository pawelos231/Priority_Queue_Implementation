#include <iostream>
#include <vector>



//First of all what even is a priority queue? It is a abstract data type that resembles normal queue, but in addition to that every element has it's own priority, the priority determines in which order should those elements be removed

//There are multiple ways to implement priority queue
/*
- Arrays
- Linked List
- Heap 
- Binary search tree
*/
//Below implementetion will cover all of the above implementetion methods

//Array Implementation

struct item {
	int value;
	int priority;
};


int PqSize = -1;
std::vector<item> PriorityQueue;

void enqueue(int value, int priority) {
	PqSize++;

	item temp{
		value,
		priority,
	};

	PriorityQueue.push_back(temp);

}

int peek() {
	int HighestPriority = INT_MIN;
	int index = -1;
	for (int i = 0; i <= PqSize; i++) {
		if (
			HighestPriority == PriorityQueue[i].priority &&
			index > -1 &&
			PriorityQueue[index].value < PriorityQueue[i].value)
		{
			HighestPriority = PriorityQueue[i].priority;
			index = i;
		}

		else if(HighestPriority < PriorityQueue[i].priority) {
			HighestPriority = PriorityQueue[i].priority;
			index = i;
		}

	}
	return index;
}

void dequeue() {
	int index = peek();
	for (int i = index; i < PqSize; i++) {
		int temp = i + 1;
		PriorityQueue[i] = PriorityQueue[temp];
	}
	PqSize--;
}

void ClearPriorityQueue() {
	PriorityQueue.clear();
}

void LogPriorityQueue() {
	for (const auto& s : PriorityQueue) {
		std::cout << "[" << std::endl;
		std::cout << "value: " << s.value << std::endl;
		std::cout << "priority: " << s.priority << std::endl;
		std::cout << "]" << std::endl;
	}
}

void FindElementWithGivenPriority(int priority) {
	int at = 0;
	for (const auto& s : PriorityQueue) {
		at++;
		if (s.priority == priority) {
			std::cout << "value: " << s.value << std::endl;
			std::cout << "index: " << at << std::endl;

		}
	}
}


int main() {

	enqueue(14, 4);
	enqueue(22, 5);
	enqueue(16, 4);
	enqueue(9, 3);
	LogPriorityQueue();
	FindElementWithGivenPriority(5);
	int index = peek();

	std::cout << PriorityQueue[index].value << std::endl;
	dequeue();

	index = peek();
	std::cout << PriorityQueue[index].value << std::endl;

	dequeue();

	index = peek();
	std::cout << PriorityQueue[index].value << std::endl;
	return 0;
}