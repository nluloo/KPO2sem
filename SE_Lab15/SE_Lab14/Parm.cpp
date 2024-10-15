#include "Parm.h"
#include "Error.h"
#include <wchar.h>
namespace Parm {
    PARM Parm::getparm(int argc, wchar_t* argv[])
    {
        PARM params;
        bool Inbool = false;
        bool Logbool = false;
        bool Outbool = false;
        for (int i = 1; i < argc; i++)
        {
            if (wcslen(argv[i]) > PARM_MAX_SIZE) { // Проверка на длину каждого входного параметра
                throw ERROR_THROW(104);
            }
            if (wcsncmp(argv[i], PARM_IN, 4) == 0) { // Если находим подстроку -in: то копируем ее в 
                wcscpy_s(params.in, PARM_MAX_SIZE, argv[i] + 4);
                Inbool = true;
            }
            else if (wcsncmp(argv[i], PARM_OUT, 5) == 0) {
                wcscpy_s(params.out, PARM_MAX_SIZE, argv[i] + 5);
                Outbool = true;
            }
            else if (wcsncmp(argv[i], PARM_LOG, 5) == 0) {
                wcscpy_s(params.log, PARM_MAX_SIZE, argv[i] + 5);
                Logbool = true;
            }
        }
        if (!Inbool) {
            throw ERROR_THROW(100);
        }
        if (!Outbool) {
            wchar_t str[PARM_MAX_SIZE];
            wcscpy_s(str, PARM_MAX_SIZE, params.in);
            wcscat_s(str, PARM_OUT_DEFAULT_EXT);
            wcscpy_s(params.out, PARM_MAX_SIZE, str);
        }
        if (!Logbool) {
            wchar_t str[PARM_MAX_SIZE];
            wcscpy_s(str, PARM_MAX_SIZE, params.in);
            wcscat_s(str, PARM_LOG_DEFAULT_EXT);
            wcscpy_s(params.log, PARM_MAX_SIZE, str);
        }
        return params;
    }
}
