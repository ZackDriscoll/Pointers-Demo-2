#include <iostream>
#include <chrono>


//Prototype functions
void PassByValueInventory(int bookNumber, std::string bookSummary);
void PassByPointersInventory(const int* bookNumber, const std::string* bookSummary);


int main()
{
	//Title
	std::cout << "\n\n\t\t*** Inventory ebook Summaries ***\n\n";

	//Book summary information
	std::string bookSummary = "Based upon the book's ideas you will certainly feel confident forming your own SEO methodologies and strategies at the end— either for your personal applications or using them for your clients— upon answering to the following questions: - What could or should be the most probable previews for SEO 2018? - What shall be the principal strategies you might be focusing upon? - How shall you build and develop your personal marketing strategies vis-à-vis the constant evolution of Google search and its latest innovations?";

	//Setup the max number of shared function calls so they're the same when we compare functions that take 
	//arguments by value vs other functions which takes arguments by pointers.

	const int maxFunctionCalls = 1000000;

	//******************** Start calling function passing by value ********************

	//Start snapshot of time to use to figure out how long all these function calls take passing by value
	auto startTimePassByValue = std::chrono::high_resolution_clock::now();

	//Start calls to function here
	for (int i = 0; i < maxFunctionCalls; i++)
	{
		PassByValueInventory(i, bookSummary);
	}
	//Stop snapshot of time
	auto stopTimePassByValue = std::chrono::high_resolution_clock::now();

	// Figure out the time that has passed between our start and stop
	auto duration1 = std::chrono::duration_cast<std::chrono::microseconds>(stopTimePassByValue - startTimePassByValue).count();
	long milliseconds1 = (long)(duration1 / 1000) % 1000;
	long seconds1 = (((long)(duration1 / 1000) - milliseconds1) / 1000) % 60;

	// Summary
	std::cout << "\n\n\t**** Pass by Value microseconds (million of a sec.) = " << duration1 << std::endl;
	std::cout << "\n\n\t**** Pass by Seconds = " << seconds1 << std::endl;

	//******************** End calling function passing by value ********************

	//******************** Start calling function passing by pointers ********************

	//Start snapshot of time to use to figure out how long all these function calls take passing by value
	auto startTimePassByPointers = std::chrono::high_resolution_clock::now();

	//Start calls to function here
	for (int i = 0; i < maxFunctionCalls; i++)
	{
		PassByPointersInventory(&i, &bookSummary);
	}
	//Stop snapshot of time
	auto stopTimePassByPointers = std::chrono::high_resolution_clock::now();

	// Figure out the time that has passed between our start and stop
	auto duration2 = std::chrono::duration_cast<std::chrono::microseconds>(stopTimePassByPointers - startTimePassByPointers).count();
	long milliseconds2 = (long)(duration2 / 1000) % 1000;
	long seconds2 = (((long)(duration2 / 1000) - milliseconds2) / 1000) % 60;

	// Summary
	std::cout << "\n\n\t**** Pass by Pointer microseconds (million of a sec.) = " << duration2 << std::endl;
	std::cout << "\n\n\t**** Pass by Pointer Seconds = " << seconds2 << std::endl;

	//******************** End calling function passing by pointers ********************


	//End of program
	std::cout << "\nTo exit this program ";
	system("pause");


	return 0;
}

//Function to copy the inventory
void PassByValueInventory(int bookNumber, std::string bookSummary)
{
	//Bogus stuff
	int foo = bookNumber + 333;
	std::string bar = "Add text for no reason.";

	//Concat two strings here for no reason
	bar = bar + bookSummary;
}

void PassByPointersInventory(const int* bookNumber, const std::string* bookSummary)
{
	//Bogus stuff
	int foo = *bookNumber + 333;
	std::string bar = "Add text for no reason.";

	//Concat two strings here for no reason
	bar = bar + *bookSummary;
}
