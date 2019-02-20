// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FormMain.h"
#include <iterator>
#include <vector>
#include <map>
#include <algorithm>
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

// ---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner) : TForm(Owner) {
}

void VectorMapFunctor(std::pair<int, String> pair)
// could be a class static method as well
{
	String pairStr = L"{"+(String)num+L", "+pair.second+L"}";
	Form1->Caption = pairStr;
}
// ---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender) {
	std::vector<int>items;
	items.push_back(1);
	items.push_back(2);
	items.push_back(5);

	std::map<int, String>map;
	map[1] = L"One";
	map[2] = L"Two";
	map[3] = L"Three";

	std::pair<int, String> elem = *map.begin();
	VectorMapFunctor (elem);
	for_each(map.begin(), map.end(), VectorMapFunctor);

	String s;
	for (std::vector<int>::const_iterator it = items.begin();
	it != items.end(); it++) {
		if (s == "") {
			s = *it;
		} else {
			s = s+L", "+*it;
		}
		// std::wcout <<  << std::endl;
	}
	Button1->Caption = s;

	/*
	Foo* foo = new Foo();
	Test(foo);
	delete foo;
	*/
}
// ---------------------------------------------------------------------------
