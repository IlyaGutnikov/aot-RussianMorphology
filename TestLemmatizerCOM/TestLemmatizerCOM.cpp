#include <stdio.h>
#include <comdef.h>
#include "windows.h"
#include <iostream>
#include <process.h>
#include <string>
#import "C:\Rml\Bin\Lemmatizer.tlb"
using namespace std;
using namespace LEMMATIZERLib;
int main(int argc, char *argv[])
{
	_bstr_t main_form;

	CoInitialize(NULL);
	//  creating and loading Russian dictionary
	ILemmatizerPtr	piLemmatizer;
	HRESULT hr = piLemmatizer.CreateInstance(__uuidof(LemmatizerRussian));
	if (FAILED(hr))
	{
		cout << "Fatal Error: Lemmatizer creation failed";
		return 1;
	}
	// loading dictionary into the memory
	hr = piLemmatizer->LoadDictionariesRegistry();
	if (FAILED(hr))
	{
		cout << "Fatal Error: Lemmatizer loading failed";
		return 1;
	}

	else {

		piLemmatizer->LoadDictionariesRegistry();
	
	}
	// lemmatizing a word
	{
		IParadigmCollectionPtr piParadigmCollection = piLemmatizer->CreateParadigmCollectionFromForm("девочкой", 0, 0);
		//  print possible lemmas
		cout << piParadigmCollection->Count << endl;
		for (int j = 0; j < piParadigmCollection->Count; j++)
		{
			main_form = _bstr_t(piParadigmCollection->Item[j]->SrcNorm);
			CharToOem(main_form, main_form);
			cout << main_form << endl;
		};

	}

	{
		IParadigmCollectionPtr piParadigmCollection2 = piLemmatizer->CreateParadigmCollectionFromNorm(main_form, 0, 0);
		 
		cout << piParadigmCollection2->Count << endl;

		for (int i = 0; i < piParadigmCollection2->Count; ++i)
		{
			for (int j = 0; j < piParadigmCollection2[i].Count; j++)
			{
				_bstr_t form = _bstr_t(piParadigmCollection2->Item[i]->Form[j]);

				CharToOem(form, form);
				cout << form << endl;
			}
		}
	}
	// destroy the dictionary
	piLemmatizer = 0;
	CoUninitialize();
	string str = "";
	str = system("TestLemmatizerCSharp.exe");
	cout << str << endl;

	cout << "Это после выполнения";

	system("pause");
	return 0;
}