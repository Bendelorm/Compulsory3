#include <iostream>
#include <string>
#include "Header2.h"
using namespace std;

class Folder {
private:
	string folderName;
	int folderSize;
	char* folderDate;
	Folder* folders[5] = {nullptr, nullptr, nullptr, nullptr, nullptr};
	FileClass* files[10] = {nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr};
public:
	Folder(string newName) //constructor for folders
	{
		srand((unsigned)time(NULL)); //random seed for random
		folderSize = rand() % 100;
		time_t timeNow = time(0);
		folderDate = ctime(&timeNow);
		folderName = newName;
	}
	string getName()
	{
		return folderName;
	}
	int getSize()
	{
		return folderSize;
	}
	char* getDate()
	{
		return folderDate;
	}
	Folder** getFolders()
	{
		return folders;
	}
	FileClass** getFiles()
	{
		return files;
	}
	void putFolder(Folder* folderObj)
	{
		for (int i = 0; i < 5; i++)
		{
			if (folders[i] == nullptr)
			{
				folders[i] = folderObj;
				break;
			}
		}
	}
	void putFile(FileClass* fileObj)
	{
		for (int i = 0; i < 10; i++)
		{
			if (files[i] == nullptr)
			{
				files[i] = fileObj;
				break;
			}
		}
	}
	void setName(string newName)
	{
		folderName = newName;
	}
	int getFolderNum()
	{
		int size = 0;
		for (int i = 0; i < 10; ++i) {
			if (files[i] != nullptr) {
				++size;
			}
		}
		return size;
	}
};