#include <stdio.h>
#include <comdef.h>
#include "windows.h"
#include <iostream>
#import "C:\Rml\Bin\Lemmatizer.tlb"
using namespace std;
using namespace LEMMATIZERLib;
int main(int argc, char *argv[])
{
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
		return false;
	}
	// lemmatizing a word
	{
		IParadigmCollectionPtr piParadigmCollection = piLemmatizer->CreateParadigmCollectionFromForm("поющая", FALSE, FALSE);
		//  print possible lemmas
		for (int j = 0; j < piParadigmCollection->Count; j++)
		{
			_bstr_t Lemma = _bstr_t(piParadigmCollection->Item[j]->Norm);
			CharToOem(Lemma, Lemma);
			cout << Lemma << endl;
		};
	}
	// destroy the dictionary
	piLemmatizer = 0;
	CoUninitialize();

	cout << "Hello, world!" << endl;
	system("pause"); // Только для тех, у кого MS Visual Studio
	return 0;
}