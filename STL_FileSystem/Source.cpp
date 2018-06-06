#include <iostream>
#include <string>
#include <vector>
#include <filesystem>
#include <fstream>

using namespace std;
using namespace std::experimental::filesystem;

void printDirectoryContent(path dir)
{
	cout << "Content of '" << dir.string() << "': " << endl;
	
	for (auto& element : directory_iterator(dir))
	{
		cout << "\t - " << element << endl;
	}

	cout << endl << endl;
}

string createFolder(path dir, string dirName)
{
	auto newPath = dir.string() + dirName;

	if(!exists(newPath))
	{
		create_directory(newPath);
	}

	return newPath;
}

void deleteeFolder(path pethTofolder)
{
	if (exists(pethTofolder))
	{
		remove_all(pethTofolder);
	}
}

void recursive_file_list(const char* path)
{
	for (recursive_directory_iterator i(path), end; i != end; ++i)
		if (!is_directory(i->path()))
			cout << i->path().filename() << "\n";
}


void main()
{
	path rootPath("D:/");
	auto currentPath = current_path();
	
	if (exists(rootPath))
	{
		auto tempDir = path(createFolder(rootPath, "temp"));

		cout << "Root: " << rootPath.string() << endl;
		cout << "Current: " << currentPath.string() << endl << endl;
		cout << "Temp dir: " << tempDir.string() << endl << endl;

		const auto spaceInfo = space(rootPath);
		cout << "space_Info of '" + rootPath.string() + "':" << endl;
		cout << "available:\t" << spaceInfo.available << endl;
		cout << "free: \t\t" << spaceInfo.free << endl;
		cout << "capacity: \t" << spaceInfo.capacity << endl << endl;
		
		printDirectoryContent(tempDir);

		cout << "Create folder and files! " << endl << endl;
		
		auto filePath1 = tempDir.string() + "/file1.txt";
		auto filePath2 = tempDir.string() + "/file2.txt";

		auto newDir = createFolder(tempDir, "/testDir");
		ofstream(filePath1.c_str());
		ofstream(filePath2.c_str());

		printDirectoryContent(tempDir);
		cout << "Delete all! " << endl << endl;

		deleteeFolder(tempDir);

		recursive_file_list(currentPath.string().c_str());
	}
}
