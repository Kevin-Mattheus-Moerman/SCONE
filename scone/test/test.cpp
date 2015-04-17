// test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "XmlParseTest.h"
#include "OptimizationTest.h"
#include <conio.h>
#include "SimulationTest.h"
#include "../core/Log.h"
#include "SerializationTest.h"

using std::cout;
using std::endl;

int _tmain(int argc, _TCHAR* argv[])
{
	try
	{
		//XmlParseTest();
		//SerializationTest();
		//OptimizationTest();
		//SimulationTest();
		PropNode p = ReadPropNode( "include_test.xml" );
		cout << p;
	}
	catch (std::exception& e)
	{
		log::Critical( e.what() );
	}

	_getch();

	return 0;
}
