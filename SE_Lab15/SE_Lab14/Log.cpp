#include "Log.h"
#include <stdarg.h>
namespace Log {
    LOG getlog(wchar_t logfile[]) {
        LOG log = INITLOG;
        wcsncpy_s(log.logfile, logfile, PARM_MAX_SIZE);

        log.stream = new std::ofstream(logfile);
        if (!log.stream) {
            throw ERROR_THROW(112);
        }

        return log;
    }
    void WriteLine(LOG log, char* first, ...) {
        va_list args;
        va_start(args, first);

        char* current = first;
        char buffer[1024];// Может быть в будущем нужно будет изменять размер буфера!!!!!!!!!!!!!!!!!!!!
        buffer[0] = '\0';

        while (current[0] != '\0') {
            strcat_s(buffer, current);
            current = va_arg(args, char*);
        }

        va_end(args);

            *(log.stream) << buffer;
    }
    void WriteLine(LOG log, wchar_t* first, ...) {
        va_list args;
        va_start(args, first);

        wchar_t* current = first;
        char buffer[1024];// Может быть в будущем нужно будет изменять размер буфера!!!!!!!!!!!!!!!!!!!!
        buffer[0] = '\0';

        while (current[0] != '\0') {
            char buffer2[1024]; // Может быть в будущем нужно будет изменять размер буфера!!!!!!!!!!!!!!!!!!!!
            size_t charsConverted = 0;
            wcstombs_s(&charsConverted, buffer2, current, _TRUNCATE); // Преобразуем wchar_t* в char*
            strcat_s(buffer, buffer2);
            current = va_arg(args, wchar_t*);
        }

        va_end(args);

        *(log.stream) << buffer;
    }
    void WriteLog(LOG log) {
        time_t rawtime;
        tm timeinfo;
        char timeBuffer[80];

        // Получаем текущее время
        time(&rawtime);
        localtime_s(&timeinfo, &rawtime);

        // Форматируем время в строку
        strftime(timeBuffer, sizeof(timeBuffer), "%Y.%m.%d %H:%M:%S", &timeinfo);

        // Выводим заголовок в протокол
        *(log.stream) << "---- Протокол ------ " << timeBuffer << " ------------------" << std::endl;
    }
    void WriteParm(LOG log, Parm::PARM parm) {
        size_t charsConverted = 0; // т.к parm.in = wchar_t, нужно его переводить в char чтобы записать в файл корректно
        char buffer[1024]; // Может быть в будущем нужно будет изменять размер буфера!!!!!!!!!!!!!!!!!!!!
        *(log.stream) << "---- Исходные данные ------" << std::endl;
        wcstombs_s(&charsConverted, buffer, parm.in, _TRUNCATE);
        *(log.stream) << "-in: " << buffer << std::endl;
        wcstombs_s(&charsConverted, buffer, parm.out, _TRUNCATE);
        *(log.stream) << "-out: " << buffer << std::endl;
        wcstombs_s(&charsConverted, buffer, parm.log, _TRUNCATE);
        *(log.stream) << "-log: " << buffer << std::endl;
    }
    void WriteIn(LOG log, In::IN in) {
        *(log.stream) << "---- Исходные данные ------" << std::endl;
        *(log.stream) << "Количество символов: " << in.size << std::endl;
        *(log.stream) << "Проигнорировано    : " << in.ignor << std::endl;
        *(log.stream) << "Количество строк   : " << in.lines << std::endl;
    }

    void Close(LOG log) {
        if(log.stream)log.stream->close(); // Если поток открыт, то закрываем его
    }
    void WriteError(LOG log, Error::ERROR error) {
        if (log.stream) {
            *(log.stream) << "Ошибка " << error.id << ": " << error.message
                          << ", строка " << error.inext.line
                          << ",позиция " << error.inext.col << std::endl;
        }
        else {
            std::cout << "Ошибка " << error.id << ": " << error.message
                << ", строка " << error.inext.line
                << ",позиция " << error.inext.col << std::endl;
        }
    }
}
