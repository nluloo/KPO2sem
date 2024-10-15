#pragma once
#include "FST.h"
#include "IT.h"
#include "In.h"
#include "Out.h"
#include "Error.h"
#include "Parm.h"
#include "Log.h"
#include "LT.h"


namespace LA {
	char FST();
	void add_LT(LT::Entry& Entry_LT, int size, int idxF);
	void add_IT(IT::Entry& Entry_TI, int line, char* str, IT::IDDATATYPE data, IT::IDTYPE type, int value);
	void LA(In::IN& in);
}