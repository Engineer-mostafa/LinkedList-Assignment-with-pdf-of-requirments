#include "LinkedList.h"
#include <iostream>
using namespace std;


int main()
{
	////10 9 5 8 6 4 9 3
	LinkedList<int> L;	
	int Choice,x;
	cin >> Choice >> x;
	while (x != -1)
	{
		L.Insertend(x);
		cin >> x;
	}
	switch (Choice)
	{
	case 1:
		L.RemoveEvensAfterOdds();
		break;
	case 2:
		L.CompletesTen();
		break;
	case 3:
		L.RemoveEquals();
		break;
	case 4:
		L.CompressEquals();
		break;
	default:
		break;
	}
	
	L.PrintList();
	return 0;
}

