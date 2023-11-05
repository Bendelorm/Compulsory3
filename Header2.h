#include <iostream>
#include <string>
#include <ctime>
#include <time.h>
using namespace std;
class FileClass {
private:
	string fileName;
	int fileSize;
	char* fileDate;

public:
	FileClass(string newName)//constructor for files
	{
		srand((unsigned)time(NULL)); //random seed for random
		fileSize = rand() % 100;
		time_t timeNow = time(0);
		fileDate = ctime(&timeNow);
		fileName = newName;
	}
	string getName()
	{
		return fileName;
	}
	int getSize()
	{
		return fileSize;
	}
	char* getDate()
	{
		return fileDate;
	}
	void setName(string newName)
	{
		fileName = newName;
	}
};

