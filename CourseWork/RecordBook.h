#include <iostream>
#include <string>
#include "OneLinkedList.h"
#include "Session.h"
//#include "ListOfSessions.h"
#pragma once

using namespace std;

class RecordBook
{
private:
	OneLinkedList<Session> listOfSessions;
};

