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
        bool lastWasSpace = false;  // ���� ��� �������� ��������� ��������
        bool lastWasPipe = false;   // ���� ��� ��������, ��� ���������� ������ ��� '|'

        while (file.get(chh)) {
            unsigned char ch = chh;

            // ��������� ������� ����� ������
            if (ch == IN_CODE_ENDL) {
                line++;
                column = 0;
                lastWasNewLine = true;
                lastWasSpace = false;

                // ������� ������� ����� �������� '|', ���� ��� ����
                if (i > 0 && str[i - 1] == ' ') {
                    i--;  // ������� ������ ����� '|'
                    space--;  // ��������� ���������� ��������
                }

                str[i++] = '|';  // ��������� ������ '|'

                // ���������� ��� ������� ����� ����� ������� '|'
                while (file.peek() == ' ') {
                    file.get();  // ���������� ������� ����� '|'
                }

                lastWasPipe = true;  // ������������� ���� ����� ������� '|'
                continue;
            }

            if (ch < 256 && params.code[ch] == IN::F) {
                throw ERROR_THROW_IN(111, line, column);
            }
            if (ch < 256 && params.code[ch] == IN::I) {
                if (ch == ' ') {
                    if (!lastWasSpace) {  // ���� ���������� ������ �� ��� ��������
                        str[i++] = ' ';  // ��������� ���� ������
                        space++;
                        lastWasSpace = true;  // ������������� ����
                    }
                    continue;
                }
                ignore++;
                continue;
            }

            // ���������� ���� ��� ������� ������ ��������
            lastWasSpace = false;

            // �������� ��� ��������, ��������� ������� ������ ���
            if (ch == '(' || ch == ')' || ch == '{' || ch == '}' ||
                ch == '=' || ch == '+' || ch == '*' || ch == ';' || ch == ',')
            {
                // ���� ���������� ������ ��� '|', ���������� ������ ����� ���� ��������
                if (!lastWasPipe && i > 0 && str[i - 1] != ' ') {
                    str[i++] = ' ';  // ������ ����� ��������
                    space++;
                }

                str[i++] = ch;

                // ���� ��������� ������ �� ������ � �� ������� ������, ��������� ������
                if (file.peek() != ' ' && file.peek() != '\n' && file.peek() != '\t') {
                    str[i++] = ' ';  // ������ ����� �������
                    space++;
                }

                column++;
                lastWasNewLine = false;
                lastWasPipe = false;  // ���������� ���� ��� ������� '|'
                continue;
            }

            // ���� ���������� ������ ��� '|', ���������� ������ ����� ��������
            if (lastWasPipe && ch == ' ') {
                continue;  // ���������� ������ ����� '|'
            }

            // ����������� ��������� ��������
            str[i++] = ch;
            column++;
            lastWasNewLine = false;
            lastWasPipe = false;  // ���������� ���� ����� ������� ������� �������
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

