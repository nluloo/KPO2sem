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
        char buffer[1024];// ����� ���� � ������� ����� ����� �������� ������ ������!!!!!!!!!!!!!!!!!!!!
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
        char buffer[1024];// ����� ���� � ������� ����� ����� �������� ������ ������!!!!!!!!!!!!!!!!!!!!
        buffer[0] = '\0';

        while (current[0] != '\0') {
            char buffer2[1024]; // ����� ���� � ������� ����� ����� �������� ������ ������!!!!!!!!!!!!!!!!!!!!
            size_t charsConverted = 0;
            wcstombs_s(&charsConverted, buffer2, current, _TRUNCATE); // ����������� wchar_t* � char*
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

        // �������� ������� �����
        time(&rawtime);
        localtime_s(&timeinfo, &rawtime);

        // ����������� ����� � ������
        strftime(timeBuffer, sizeof(timeBuffer), "%Y.%m.%d %H:%M:%S", &timeinfo);

        // ������� ��������� � ��������
        *(log.stream) << "---- �������� ------ " << timeBuffer << " ------------------" << std::endl;
    }
    void WriteParm(LOG log, Parm::PARM parm) {
        size_t charsConverted = 0; // �.� parm.in = wchar_t, ����� ��� ���������� � char ����� �������� � ���� ���������
        char buffer[1024]; // ����� ���� � ������� ����� ����� �������� ������ ������!!!!!!!!!!!!!!!!!!!!
        *(log.stream) << "---- �������� ������ ------" << std::endl;
        wcstombs_s(&charsConverted, buffer, parm.in, _TRUNCATE);
        *(log.stream) << "-in: " << buffer << std::endl;
        wcstombs_s(&charsConverted, buffer, parm.out, _TRUNCATE);
        *(log.stream) << "-out: " << buffer << std::endl;
        wcstombs_s(&charsConverted, buffer, parm.log, _TRUNCATE);
        *(log.stream) << "-log: " << buffer << std::endl;
    }
    void WriteIn(LOG log, In::IN in) {
        *(log.stream) << "---- �������� ������ ------" << std::endl;
        *(log.stream) << "���������� ��������: " << in.size << std::endl;
        *(log.stream) << "���������������    : " << in.ignor << std::endl;
        *(log.stream) << "���������� �����   : " << in.lines << std::endl;
    }

    void Close(LOG log) {
        if(log.stream)log.stream->close(); // ���� ����� ������, �� ��������� ���
    }
    void WriteError(LOG log, Error::ERROR error) {
        if (log.stream) {
            *(log.stream) << "������ " << error.id << ": " << error.message
                          << ", ������ " << error.inext.line
                          << ",������� " << error.inext.col << std::endl;
        }
        else {
            std::cout << "������ " << error.id << ": " << error.message
                << ", ������ " << error.inext.line
                << ",������� " << error.inext.col << std::endl;
        }
    }
}
