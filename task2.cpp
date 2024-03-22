#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <dirent.h> 
using namespace std;
class CLI{
	public:
   void contentDirectory(const string& path) {
    DIR* dir;
    struct dirent* ent;
    if ((dir = opendir(path.c_str())) != NULL) {
        while ((ent = readdir(dir)) != NULL) {
            cout << ent->d_name << endl;
        }
             closedir(dir);
    } else {
        perror("opendir");
    }
}
void creatingDir(const string& path) {
     if (system(("mkdir " + path).c_str()) == 0) {
        cout << "Directory created ." << endl;
    } else {
        cout << "directory creation failed." << endl;
    }
}
void copyingFile(const string& source, const string& destination) {
    if (system(("copy " + source + " " + destination).c_str()) == 0) {
        cout << "File copied." << endl;
    } else {
        cout << "Failed to copy file." << endl;
    }
}
void movingFile(const string& source, const string& destination) {
 if (system(("move " + source + " " + destination).c_str()) == 0) {
        cout << "File moved ." << endl;
    } else {
        cout << "Failed to move file." << endl;
    }
}
void openingFile(const string& filename) {
    ifstream file(filename.c_str());
    if (file.is_open()) {
        cout << "File opened." << endl;
        file.close();     } else {
        cout << "Failed to open file." << endl;
    }
}
bool movingBackDir() {
    if (chdir("..") == 0) {
        return true; 
    } else {
        return false;
    }
}};
int main() {
	system("color 2f");
	CLI c1;
    string currentDirectory = ".";
    int ch;
    do{
    cout<<"1.Display current directory contents"<<endl;
    cout<<"2.Create a directory"<<endl;
    cout<<"3.Copy a file"<<endl;
    cout<<"4.Move a file"<<endl;
    cout<<"5.Open a file"<<endl;
    cout<<"6.Move back directory"<<endl;
    cout<<"7.Exit"<<endl;
    cout<<"Enter your choice: ";
    cin >> ch;
  if(ch==1){
    c1.contentDirectory(currentDirectory);
    }
    else if(ch==2) {
    string newDirName;
    cout << "Enter name for new directory: ";
    cin >> newDirName;
    c1.creatingDir(currentDirectory + "/" + newDirName);
    }
   else if(ch==3){
    string source, destination;
    cout << "Enter source file name: ";
    cin >> source;
    cout << "Enter destination directory: ";
    cin >> destination;
    c1.copyingFile(source, destination);
            }
    else if(ch==4){
    string source, destination;
    cout << "Enter source file name: ";
    cin >> source;
    cout << "Enter destination directory: ";
    cin >> destination;
    c1.movingFile(source, destination);
            }
    else if(ch==5){
    string filename;
    cout << "Enter file name: ";
    cin >> filename;
    c1.openingFile(filename);
            }
   else if(ch==6){
    if (c1.movingBackDir()) {
        cout << "Moved back one directory." << endl;
    } else {
        cout << "Failed to move back one directory." << endl;
    }}
    else if(ch==7){
	cout << "Exiting program." << endl;
}
    else{
    cout << "Invalid choice. Please try again." << endl;
        }
    } while (ch != 8);

    return 0;
}

