#include <iostream>
#include <locale>
#include <TCHAR.H>
#include <cwchar>
#include "Parm.h"
#include "Error.h"
#include "Log.h"

// Выбрать любой из тестов
//#define TEST1
//#define TEST2
#define TEST3
//#define TEST4

#if defined(TEST1) + \
    defined(TEST2) + \
    defined(TEST3) + \
    defined(TEST4) > 1
#error Ошибка: Нельзя установить более одного макроса из списка
#endif

// ЧТОБЫ КОД ПРАВИЛЬНО РБОТАЛ ФАЙЛ .TXT НУЖНО СОХРАНЯТЬ В КОДИРОВКЕ ANSI. ТОГДА БУДУТ КОРРЕКТНО СЧИТЫВАТЬСЯ РУССКИЕ СИМВОЛЫ

int wmain(int argc, _TCHAR* argv[]) {
	setlocale(LC_ALL, "ru");
#ifdef TEST1
	std::cout << "---- тест Error:geterror ----" << std::endl << std::endl;
	try {
		throw ERROR_THROW(100);
	}
	catch (Error::ERROR e) {
		std::cout << "Ошибка " << e.id << ": " << e.message << std::endl << std::endl;
	};

	std::cout << "---- тест Error:geterrorin ----" << std::endl << std::endl;
	try {
		throw ERROR_THROW_IN(111, 7, 7);
	}
	catch (Error::ERROR e) {
		std::cout << "Ошибка " << e.id << ": " << e.message
			<< ", строка " << e.inext.line
			<< ", позиция " << e.inext.col << std::endl << std::endl;
	};
#endif

#ifdef TEST2
	std::cout << "---- тест Parm:getparm ----" << std::endl << std::endl;
	try {
		Parm::PARM parm = Parm::getparm(argc, argv);
		std::wcout << "-in:" << parm.in << ", -out:" << parm.out << ", -log:" << parm.log << std::endl << std::endl;
	}
	catch (Error::ERROR e) {
		std::cout << "Ошибка " << e.id << ": " << e.message << std::endl << std::endl;
	}
#endif

#ifdef TEST3
	std::cout << "---- тест In:getin ----" << std::endl << std::endl;
	try {
		Parm::PARM parm = Parm::getparm(argc, argv);
		In::IN in = In::getin(parm.in);
		std::cout << in.text << std::endl;
		std::cout << "Всего символов: " << in.size << std::endl;
		std::cout << "Всего строк: " << in.lines << std::endl;
		std::cout << "Пропущено: " << in.ignor << std::endl;
	}
	catch (Error::ERROR e) {
		std::cout << "Ошибка " << e.id << ": " << e.message << std::endl << std::endl;
	}
#endif

#ifdef TEST4
	Log::LOG log = Log::INITLOG;
	try
	{
	Parm::PARM parm = Parm::getparm(argc, argv);
	
	log = Log::getlog(parm.log);
	Log::WriteLine(log, (char*)"Теcт:", (char*)" без ошибок \n", "");
	Log::WriteLine(log, (wchar_t*)L"Тест:", (wchar_t*)L" без ошибок \n", L"");
	Log::WriteLog(log);
	Log::WriteParm(log, parm);
	In::IN in = In::getin(parm.in);
	Log::WriteIn(log, in);
	Log::Close(log);
	}
	catch (Error::ERROR e)
	{
		Log::WriteError(log, e);
	}
#endif

	system("pause");
	return 0;
}