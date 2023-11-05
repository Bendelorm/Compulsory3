#pragma warning(disable : 4996)
#include <iostream>
#include <ctime>
#include <chrono>
#include <string>
#include <cstdlib>
#include "Header.h"
#include "stdlib.h"
using namespace std;
/// <summary>
/// function for creating a folder
/// </summary>
/// <returns></returns>
void createFolder(Folder* rootFolder)
{
	string folderName;
	cout << "Enter folder name\n";
	cin >> folderName;
	Folder* folderObj = new Folder(folderName);
	rootFolder->putFolder(folderObj);
}
/// <summary>
/// function for creating a file
/// </summary>
/// <returns></returns>
void createFile(Folder* rootFolder)
{
	string fileName;
	cout << "Enter file name\n";
	cin >> fileName;
	FileClass* fileObj = new FileClass(fileName);
	rootFolder->putFile(fileObj);
}
/// <summary>
/// Function for checking the contents of a folder
/// </summary>
/// <param name="folderObj"></param>
void checkFolder(Folder folderObj)
{
	cout << "Current folder:\t";
	cout << folderObj.getName() << "\t" << folderObj.getSize() << "MB\t" << folderObj.getDate() << "\n";
	Folder** folders = folderObj.getFolders();
	FileClass** files = folderObj.getFiles();
	cout << "Folders:\n";
	for (int i = 0; i < 5; i++)
	{
		if (folders[i] != nullptr)
		{
			cout << (*folders[i]).getName() << "\t" << (*folders[i]).getSize() << "MB" << "\t" << (*folders[i]).getDate() << "\n";
		}
	}
	cout << "Files:\n";
	for (int k = 0; k < 10; k++)
	{
		if (files[k] != nullptr)
		{
			cout << (*files[k]).getName() << "\t" << (*files[k]).getSize() << "MB" << "\t" << (*files[k]).getDate() << "\n";
		}
	}
}
void renameFolder(Folder folderObj)
{
	int rename;
	Folder** folders = folderObj.getFolders();
	cout << "Which folder do you want to rename?\n";
	for (int i = 0; i < 5; i++)
	{
		if (folders[i] != nullptr)
		{
			cout << "[" << i + 1 << "]";
			cout << (*folders[i]).getName() << "\n";
		}
	}
	cin >> rename;
	cout << "What would you like to name the folder?\n";
	string folderNewName;
	cin >> folderNewName;
	folders[rename - 1]->setName(folderNewName);
}
void renameFile(Folder folderObj)
{
	int rename;
	FileClass** files = folderObj.getFiles();
	cout << "Which folder do you want to rename?\n";
	for (int i = 0; i < 5; i++)
	{
		if (files[i] != nullptr)
		{
			cout << "[" << i + 1 << "]";
			cout << (*files[i]).getName() << "\n";
		}
	}
	cin >> rename;
	cout << "What would you like to name the folder?\n";
	string folderNewName;
	cin >> folderNewName;
	files[rename - 1]->setName(folderNewName);
}
void biggestFile(Folder folderObj)
{
	FileClass** files = folderObj.getFiles();
	cout << "The biggest file is:\n";
	int size = folderObj.getFolderNum();
	if (size <= 0)
	{
		cout << "Array is empty\n";
	}
	int max = files[0]->getSize();
	int maxIndex = 0;
	for (int i = 1; i < size; i++)
	{
		if (files[i]->getSize() > max)
		{
			max = files[i]->getSize();
			maxIndex = i;
		}
	}
	cout << files[maxIndex]->getName() << " " << files[maxIndex]->getSize() << "MB " << files[maxIndex]->getDate() << "\n";
}
int main()
{
	Folder rootFolder("Root");
	while (true)
	{
		int meny;
		cout << "What do you want to do?\n";
		cout << "[1] Check content of folder\n";
		cout << "[2] Create a folder\n";
		cout << "[3] Create a file\n";
		cout << "[4] Change the name of a folder\n";
		cout << "[5] Change the name of a file\n";
		cout << "[6] Find biggest file\n";
		cout << "[7] Exit program\n";
		cin >> meny;
		switch (meny)
		{
		case 1:
			checkFolder(rootFolder);
			break;
		case 2:
		{
			createFolder(&rootFolder);
			break;
		}
		case 3:
		{
			createFile(&rootFolder);
			break;
		}
		case 4:
			renameFolder(rootFolder);
			break;
		case 5:
			renameFile(rootFolder);
			break;
		case 6:
			biggestFile(rootFolder);
			break;
		case 7:
			exit(0);
			break;
		default:
			cout << "That was the wrong input, lets try again.\n\n\n";
			continue;
			break;
		}
	}
}