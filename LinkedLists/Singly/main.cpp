#include <iostream>
#include"linklists.h"

using namespace std;

int main(int argc, char **argv)
{
	List a;
	a.Print();
	a.Append(1);
	a.Append(2);
	a.Append(3);
	a.Append(4);
	a.Delete(3);
	a.Delete(56);
	a.Print();
}
