#include "In.h"
#include "Error.h"

namespace In {
    IN In::getin(wchar_t infile[])
    {
        //const int arr[256] = IN_CODE_TABLE; ЕСЛИ НЕ ИНИЦИАЛИЗИРОВАТЬ ВНУТРИ СТРУКТУРЫ ТАБЛИЦУ, ТО ЭТО НУЖНО ДЕЛАТЬ ЗДЕСЬ
        unsigned char* str = new unsigned char[IN_MAX_LEN_TEXT];

        std::ifstream file(infile);
        if (!file.is_open()) {
            throw ERROR_THROW(110)
        }
        IN params;
        /*for (int i = 0; i < 256; i++) {
            params.code[i] = arr[i];
        }*/
        char chh;
        int line = 0, column = 0, i = 0, ignore = 0;
        while (file.get(chh)) {
            unsigned char ch = chh;
            if (ch == IN_CODE_ENDL) {
                line++;
                column = 0;
                str[i] = ch;
                i++;
                continue;
            }
            if (ch < 256 && params.code[ch] == IN::F) {
                throw ERROR_THROW_IN(111, line, column);
            }
            if (ch < 256 && params.code[ch] == IN::I) {
                ignore++;
                continue;
            }
            if (ch < 256 && (params.code[ch] == IN::T)){
                str[i] = ch;
                i++;
                column++;
            }
            if (params.code[ch] == '-') { // Поменять символ если задан по условию какой-то другой
                str[i] = '-';
                i++;
                column++;
            }
            if (params.code[ch] == '|') { // Поменять символ если задан по условию какой-то другой
                str[i] = '|';
                i++;
                column++;
            }
        }
        file.close();
        params.text = new unsigned char[i]; // Правильное выделение памяти
        for (int j = 0; j < i; j++) {
            params.text[j] = str[j];
        }
        params.text[i] = '\0'; // Чтобы не появлялись ненужные символы, нужн завершить строку нуль-терминалом
        params.ignor = ignore;
        params.lines = line;
        params.size = i;
        return params;

    }
}
