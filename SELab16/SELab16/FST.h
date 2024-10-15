#include "Windows.h"
#include <algorithm>
#include <iostream>

namespace FST {
	struct RELATION {
		char symbol;
		short node;
		RELATION(char c = 0x00, short ns = NULL);
	};

	struct NODE
	{
		short n_relation;
		RELATION* relations;
		NODE();
		NODE(short n, RELATION rel, ...);
	};
	struct FST {
		char* string;
		short position;
		short nstates;
		NODE* nodes;
		short* rstates;
		FST(char* s, short ns, NODE n, ...);
	};

	bool execute(FST& fst);
	bool step(FST& fst, short*& rstates);
};