#include "In.h"
#include "Error.h"

namespace In {
    IN In::getin(wchar_t infile[])
    {
        unsigned char* str = new unsigned char[IN_MAX_LEN_TEXT];

        std::ifstream file(infile);
        if (!file.is_open()) {
            throw ERROR_THROW(110);
        }
        IN params;
        char chh;
        int line = 1, column = 0, i = 0, ignore = 0, space = 0;

        bool lastWasNewLine = false;
        bool lastWasSpace = false;  // Флаг для проверки повторных пробелов
        bool lastWasPipe = false;   // Флаг для проверки, что предыдущий символ был '|'

        while (file.get(chh)) {
            unsigned char ch = chh;

            // Обработка символа конца строки
            if (ch == IN_CODE_ENDL) {
                line++;
                column = 0;
                lastWasNewLine = true;
                lastWasSpace = false;

                // Убираем пробелы перед символом '|', если они есть
                if (i > 0 && str[i - 1] == ' ') {
                    i--;  // Убираем пробел перед '|'
                    space--;  // Уменьшаем количество пробелов
                }

                str[i++] = '|';  // Добавляем символ '|'

                // Пропускаем все пробелы сразу после символа '|'
                while (file.peek() == ' ') {
                    file.get();  // Пропускаем пробелы после '|'
                }

                lastWasPipe = true;  // Устанавливаем флаг после символа '|'
                continue;
            }

            if (ch < 256 && params.code[ch] == IN::F) {
                throw ERROR_THROW_IN(111, line, column);
            }
            if (ch < 256 && params.code[ch] == IN::I) {
                if (ch == ' ') {
                    if (!lastWasSpace) {  // Если предыдущий символ не был пробелом
                        str[i++] = ' ';  // Оставляем один пробел
                        space++;
                        lastWasSpace = true;  // Устанавливаем флаг
                    }
                    continue;
                }
                ignore++;
                continue;
            }

            // Сбрасываем флаг при встрече других символов
            lastWasSpace = false;

            // Проверка для символов, требующих пробелы вокруг них
            if (ch == '(' || ch == ')' || ch == '{' || ch == '}' ||
                ch == '=' || ch == '+' || ch == '*' || ch == ';' || ch == ',')
            {
                // Если предыдущий символ был '|', пропускаем пробел перед этим символом
                if (!lastWasPipe && i > 0 && str[i - 1] != ' ') {
                    str[i++] = ' ';  // Пробел перед символом
                    space++;
                }

                str[i++] = ch;

                // Если следующий символ не пробел и не перевод строки, добавляем пробел
                if (file.peek() != ' ' && file.peek() != '\n' && file.peek() != '\t') {
                    str[i++] = ' ';  // Пробел после символа
                    space++;
                }

                column++;
                lastWasNewLine = false;
                lastWasPipe = false;  // Сбрасываем флаг для символа '|'
                continue;
            }

            // Если предыдущий символ был '|', пропускаем пробел перед символом
            if (lastWasPipe && ch == ' ') {
                continue;  // Пропускаем пробел после '|'
            }

            // Стандартная обработка символов
            str[i++] = ch;
            column++;
            lastWasNewLine = false;
            lastWasPipe = false;  // Сбрасываем флаг после вставки другого символа
        }

        file.close();

        params.text = new unsigned char[i];
        for (int j = 0; j < i; j++) {
            params.text[j] = str[j];
        }
        params.text[i] = '\0';
        params.ignor = ignore;
        params.lines = line;
        params.size = i - line;
        params.space = space;

        delete[] str;
        return params;
    }
}

