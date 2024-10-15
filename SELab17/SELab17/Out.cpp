#include "Out.h"
#include "Error.h"

Out::OUT Out::getout(wchar_t outfile[])
{
    Out::OUT out = Out::INITOUT;
    wcsncpy_s(out.outfile, outfile, PARM_MAX_SIZE);

    out.stream = new std::ofstream(outfile);
    if (!out.stream) {
        throw ERROR_THROW(112);
    }

    return out;
}

void Out::w_out(OUT file, In::IN in)
{
    *(file.stream) << in.text;
}

void Out::w_error(OUT out, Error::ERROR error)
{
    *(out.stream) << "Строка: ";
    *(out.stream) << error.inext.line;
    *(out.stream) << " Позиция: ";
    *(out.stream) << error.inext.col;
}

void Out::close(OUT out)
{
    if (out.stream)out.stream->close(); // Если поток открыт, то закрываем его
}
