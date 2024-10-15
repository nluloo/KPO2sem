#include <iostream>

#include <locale>
#include <TCHAR.H>
#include <cwchar>
#include "Parm.h"
#include "Error.h"
#include "Log.h"
#include "Out.h"
#include "Analysis.h"

using namespace std;

int wmain(int argc, _TCHAR* argv[]) {
	Log::LOG log = Log::INITLOG;
	Out::OUT out = Out::INITOUT;
	setlocale(LC_ALL, "ru");
	try {
		Parm::PARM parm = Parm::getparm(argc, argv);
		log = Log::getlog(parm.log);
		In::IN in = In::getin(parm.in);

		Log::WriteLog(log);
		out = Out::getout(parm.out);

		Log::WriteParm(log, parm);
		Log::WriteIn(log, in);
		Log::Close(log);
		Out::w_out(out, in);
		LA::LA(in);
		cout << '\n' << in.text << endl;
		std::cout << "Всего символов: " << in.size << std::endl;
		std::cout << "Всего строк: " << in.lines << std::endl;
		std::cout << "Пропущено: " << in.ignor << std::endl;
		std::cout << "Пробелы: " << in.space << std::endl;
	}
	catch (Error::ERROR e) {

		std::cout << "Ошибка " << e.id << ": " << e.message << std::endl << std::endl;
		Log::WriteError(log, e);
		Log::Close(log);
	}

	return 0;
}