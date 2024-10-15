#pragma once
#include <fstream>
#include <iostream>
#include "Parm.h"
#include "Error.h"
#include "In.h"

namespace Out {
	struct OUT
	{
		wchar_t outfile[PARM_MAX_SIZE];
		std::ofstream* stream;

	};
	static const OUT INITOUT{ L"", NULL };
	OUT getout(wchar_t outfile[]);
	void w_out(OUT, In::IN);
	void w_error(OUT out, Error::ERROR error);
	void close(OUT out);
}
