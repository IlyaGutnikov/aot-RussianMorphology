// LemmataizerClient.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <comdef.h>
#include "windows.h"
#include <iostream>
#include <process.h>
#include <string>
#include <stdexcept>

using namespace std;

string exec(const char* cmd);

int main()
{
	cout << "Hello World" << endl;

	string str = "";
	str = "TestLemmatizerCSharp.exe GetAllForms зуд";
	//GetAllForms - получаем все формы
	//GetAllNorms - получаем все нормы
	//Stem - получаем первую норму из всех возможных
	
	string output = exec(str.c_str());
	cout << output << endl;
	
	string first = "";
	int pos = output.find(",");
	first = output.substr(0, pos);
	cout << first << endl;

	cout << "After execution" << endl;
	system("pause");

    return 0;

}

string exec(const char* cmd) {
	char buffer[128];
	std::string result = "";
	FILE* pipe = _popen(cmd, "r");
	if (!pipe) throw std::runtime_error("popen() failed!");
	try {
		while (!feof(pipe)) {
			if (fgets(buffer, 128, pipe) != NULL)
				result += buffer;
		}
	}
	catch (...) {
		_pclose(pipe);
		throw;
	}
	_pclose(pipe);
	return result;
}

