#include "Analysis.h"
#include "LT.h"
#include <vector>

// ÄÎÏÈÑÀÒÜ ÀÍÀËÈÇ ÄËß ÈÄÅÍÒÈÔÈÊÀÒÎÐÎÂ È ÎÑÒÀËÜÍÛÕ ËÅÊÑÅÌ
// ÅÙÅ ÈÑÏÐÀÂÈÒÜ IN.CPP, ×ÒÎÁÛ ÊÀÆÄÀß ËÅÊÑÀÌ ÎÒÄÅËßËÀÑÜ ÏÐÎÁÅËÎÌ

#define MAX_LEX_SIZE 4096

#define FST_INT FST::FST _int\
	(str,\
	8,\
	FST::NODE(1, FST::RELATION('i', 1)),\
	FST::NODE(1, FST::RELATION('n', 2)),\
	FST::NODE(1, FST::RELATION('t', 3)),\
	FST::NODE(1, FST::RELATION('e', 4)),\
	FST::NODE(1, FST::RELATION('g', 5)),\
	FST::NODE(1, FST::RELATION('e', 6)),\
	FST::NODE(1, FST::RELATION('r', 7)),\
	FST::NODE());

#define FST_STRING FST::FST _string\
	(str,\
	7,\
	FST::NODE(1, FST::RELATION('s', 1)),\
	FST::NODE(1, FST::RELATION('t', 2)),\
	FST::NODE(1, FST::RELATION('r', 3)),\
	FST::NODE(1, FST::RELATION('i', 4)),\
	FST::NODE(1, FST::RELATION('n', 5)),\
	FST::NODE(1, FST::RELATION('g', 6)),\
	FST::NODE());


#define FST_FUNC FST::FST _function\
	(str,\
	9,\
	FST::NODE(1, FST::RELATION('f', 1)),\
	FST::NODE(1, FST::RELATION('u', 2)),\
	FST::NODE(1, FST::RELATION('n', 3)),\
	FST::NODE(1, FST::RELATION('c', 4)),\
	FST::NODE(1, FST::RELATION('t', 5)),\
	FST::NODE(1, FST::RELATION('i', 6)),\
	FST::NODE(1, FST::RELATION('o', 7)),\
	FST::NODE(1, FST::RELATION('n', 8)),\
	FST::NODE());

#define FST_DECLARE FST::FST _declare\
	(str,\
	8,\
	FST::NODE(1, FST::RELATION('d', 1)),\
	FST::NODE(1, FST::RELATION('e', 2)),\
	FST::NODE(1, FST::RELATION('c', 3)),\
	FST::NODE(1, FST::RELATION('l', 4)),\
	FST::NODE(1, FST::RELATION('a', 5)),\
	FST::NODE(1, FST::RELATION('r', 6)),\
	FST::NODE(1, FST::RELATION('e', 7)),\
	FST::NODE());

#define FST_RETURN FST::FST _return\
	(str,\
	7,\
	FST::NODE(1, FST::RELATION('r', 1)),\
	FST::NODE(1, FST::RELATION('e', 2)),\
	FST::NODE(1, FST::RELATION('t', 3)),\
	FST::NODE(1, FST::RELATION('u', 4)),\
	FST::NODE(1, FST::RELATION('r', 5)),\
	FST::NODE(1, FST::RELATION('n', 6)),\
	FST::NODE());

#define FST_MAIN FST::FST _main\
	(str,\
	5,\
	FST::NODE(1, FST::RELATION('m', 1)),\
	FST::NODE(1, FST::RELATION('a', 2)),\
	FST::NODE(1, FST::RELATION('i', 3)),\
	FST::NODE(1, FST::RELATION('n', 4)),\
	FST::NODE());

#define FST_PRINT FST::FST _print\
	(str,\
	6,\
	FST::NODE(1, FST::RELATION('p', 1)),\
	FST::NODE(1, FST::RELATION('r', 2)),\
	FST::NODE(1, FST::RELATION('i', 3)),\
	FST::NODE(1, FST::RELATION('n', 4)),\
	FST::NODE(1, FST::RELATION('t', 5)),\
	FST::NODE());

#define FST_INT_LITERAL FST::FST _intLit\
	(str, \
	2,\
	FST::NODE(20, FST::RELATION('0', 0), FST::RELATION('1', 0), FST::RELATION('2', 0),\
				  FST::RELATION('3', 0), FST::RELATION('4', 0), FST::RELATION('5', 0),\
				  FST::RELATION('6', 0), FST::RELATION('7', 0), FST::RELATION('8', 0),\
				  FST::RELATION('9', 0),\
				  FST::RELATION('0', 1), FST::RELATION('1', 1), FST::RELATION('2', 1),\
				  FST::RELATION('3', 1), FST::RELATION('4', 1), FST::RELATION('5', 1),\
				  FST::RELATION('6', 1), FST::RELATION('7', 1), FST::RELATION('8', 1),\
				  FST::RELATION('9', 1)),\
	FST::NODE());

#define FST_STRING_LITERAL FST::FST _stringLit\
	(str, \
	3,\
	FST::NODE(2, FST::RELATION('\"', 1), FST::RELATION('\'', 1)),\
	FST::NODE(136, FST::RELATION('a', 1), FST::RELATION('b', 1), FST::RELATION('c', 1), FST::RELATION('d', 1), FST::RELATION('e', 1),\
				  FST::RELATION('f', 1), FST::RELATION('g', 1), FST::RELATION('h', 1), FST::RELATION('i', 1), FST::RELATION('j', 1),\
				  FST::RELATION('k', 1), FST::RELATION('l', 1), FST::RELATION('m', 1), FST::RELATION('n', 1), FST::RELATION('o', 1),\
				  FST::RELATION('p', 1), FST::RELATION('q', 1), FST::RELATION('r', 1), FST::RELATION('s', 1), FST::RELATION('t', 1),\
				  FST::RELATION('u', 1), FST::RELATION('v', 1), FST::RELATION('w', 1), FST::RELATION('x', 1), FST::RELATION('y', 1),\
				  FST::RELATION('z', 1),\
				  FST::RELATION('A', 1), FST::RELATION('B', 1), FST::RELATION('C', 1), FST::RELATION('D', 1), FST::RELATION('E', 1),\
				  FST::RELATION('F', 1), FST::RELATION('G', 1), FST::RELATION('H', 1), FST::RELATION('I', 1), FST::RELATION('J', 1),\
				  FST::RELATION('K', 1), FST::RELATION('L', 1), FST::RELATION('M', 1), FST::RELATION('N', 1), FST::RELATION('O', 1),\
				  FST::RELATION('P', 1), FST::RELATION('Q', 1), FST::RELATION('R', 1), FST::RELATION('S', 1), FST::RELATION('T', 1),\
				  FST::RELATION('U', 1), FST::RELATION('V', 1), FST::RELATION('W', 1), FST::RELATION('X', 1), FST::RELATION('Y', 1),\
				  FST::RELATION('Z', 1),\
				  FST::RELATION('à', 1), FST::RELATION('á', 1), FST::RELATION('â', 1), FST::RELATION('ã', 1), FST::RELATION('ä', 1),\
				  FST::RELATION('å', 1), FST::RELATION('¸', 1), FST::RELATION('æ', 1), FST::RELATION('ç', 1), FST::RELATION('è', 1),\
				  FST::RELATION('é', 1), FST::RELATION('ê', 1), FST::RELATION('ë', 1), FST::RELATION('ì', 1), FST::RELATION('í', 1),\
				  FST::RELATION('î', 1), FST::RELATION('ï', 1), FST::RELATION('ð', 1), FST::RELATION('ñ', 1), FST::RELATION('ò', 1),\
				  FST::RELATION('ó', 1), FST::RELATION('ô', 1), FST::RELATION('õ', 1), FST::RELATION('ö', 1), FST::RELATION('÷', 1),\
				  FST::RELATION('ø', 1), FST::RELATION('ù', 1), FST::RELATION('ú', 1), FST::RELATION('û', 1), FST::RELATION('ü', 1),\
				  FST::RELATION('ý', 1), FST::RELATION('þ', 1), FST::RELATION('ÿ', 1),\
				  FST::RELATION('À', 1), FST::RELATION('Á', 1), FST::RELATION('Â', 1), FST::RELATION('Ã', 1), FST::RELATION('Ä', 1),\
				  FST::RELATION('Å', 1), FST::RELATION('¨', 1), FST::RELATION('Æ', 1), FST::RELATION('Ç', 1), FST::RELATION('È', 1),\
				  FST::RELATION('É', 1), FST::RELATION('Ê', 1), FST::RELATION('Ë', 1), FST::RELATION('Ì', 1), FST::RELATION('Í', 1),\
				  FST::RELATION('Î', 1), FST::RELATION('Ï', 1), FST::RELATION('Ð', 1), FST::RELATION('Ñ', 1), FST::RELATION('Ò', 1),\
				  FST::RELATION('Ó', 1), FST::RELATION('Ô', 1), FST::RELATION('Õ', 1), FST::RELATION('Ö', 1), FST::RELATION('×', 1),\
				  FST::RELATION('Ø', 1), FST::RELATION('Ù', 1), FST::RELATION('Ú', 1), FST::RELATION('Û', 1), FST::RELATION('Ü', 1),\
				  FST::RELATION('Ý', 1), FST::RELATION('Þ', 1), FST::RELATION('ß', 1),\
				  FST::RELATION('0', 1), FST::RELATION('1', 1), FST::RELATION('2', 1), FST::RELATION('3', 1), FST::RELATION('4', 1),\
				  FST::RELATION('5', 1), FST::RELATION('6', 1), FST::RELATION('7', 1), FST::RELATION('8', 1), FST::RELATION('9', 1),\
				  FST::RELATION(' ', 1), FST::RELATION('_', 1), FST::RELATION('-', 1), FST::RELATION('.', 1), FST::RELATION(',', 1),\
				  FST::RELATION('\'', 1), FST::RELATION('\"', 2), FST::RELATION('\'', 2)),\
	FST::NODE()\
);

#define FST_INDEF FST::FST _idenf\
	(str, \
	2, \
	FST::NODE(108, FST::RELATION('a', 0), FST::RELATION('b', 0), FST::RELATION('c', 0), FST::RELATION('d', 0), FST::RELATION('e', 0),\
				  FST::RELATION('f', 0), FST::RELATION('g', 0), FST::RELATION('h', 0), FST::RELATION('i', 0), FST::RELATION('j', 0),\
				  FST::RELATION('k', 0), FST::RELATION('l', 0), FST::RELATION('m', 0), FST::RELATION('n', 0), FST::RELATION('o', 0),\
				  FST::RELATION('p', 0), FST::RELATION('q', 0), FST::RELATION('r', 0), FST::RELATION('s', 0), FST::RELATION('t', 0),\
				  FST::RELATION('u', 0), FST::RELATION('v', 0), FST::RELATION('w', 0), FST::RELATION('x', 0), FST::RELATION('y', 0),\
				  FST::RELATION('z', 0),\
				  FST::RELATION('A', 0), FST::RELATION('B', 0), FST::RELATION('C', 0), FST::RELATION('D', 0), FST::RELATION('E', 0),\
				  FST::RELATION('F', 0), FST::RELATION('G', 0), FST::RELATION('H', 0), FST::RELATION('I', 0), FST::RELATION('J', 0),\
				  FST::RELATION('K', 0), FST::RELATION('L', 0), FST::RELATION('M', 0), FST::RELATION('N', 0), FST::RELATION('O', 0),\
				  FST::RELATION('P', 0), FST::RELATION('Q', 0), FST::RELATION('R', 0), FST::RELATION('S', 0), FST::RELATION('T', 0),\
				  FST::RELATION('U', 0), FST::RELATION('V', 0), FST::RELATION('W', 0), FST::RELATION('X', 0), FST::RELATION('Y', 0),\
				  FST::RELATION('Z', 0), FST::RELATION('_', 1), FST::RELATION('-', 0),\
				  FST::RELATION('a', 1), FST::RELATION('b', 1), FST::RELATION('c', 1), FST::RELATION('d', 1), FST::RELATION('e', 1),\
				  FST::RELATION('f', 1), FST::RELATION('g', 1), FST::RELATION('h', 1), FST::RELATION('i', 1), FST::RELATION('j', 1),\
				  FST::RELATION('k', 1), FST::RELATION('l', 1), FST::RELATION('m', 1), FST::RELATION('n', 1), FST::RELATION('o', 1),\
				  FST::RELATION('p', 1), FST::RELATION('q', 1), FST::RELATION('r', 1), FST::RELATION('s', 1), FST::RELATION('t', 1),\
				  FST::RELATION('u', 1), FST::RELATION('v', 1), FST::RELATION('w', 1), FST::RELATION('x', 1), FST::RELATION('y', 1),\
				  FST::RELATION('z', 1),\
				  FST::RELATION('A', 1), FST::RELATION('B', 1), FST::RELATION('C', 1), FST::RELATION('D', 1), FST::RELATION('E', 1),\
				  FST::RELATION('F', 1), FST::RELATION('G', 1), FST::RELATION('H', 1), FST::RELATION('I', 1), FST::RELATION('J', 1),\
				  FST::RELATION('K', 1), FST::RELATION('L', 1), FST::RELATION('M', 1), FST::RELATION('N', 1), FST::RELATION('O', 1),\
				  FST::RELATION('P', 1), FST::RELATION('Q', 1), FST::RELATION('R', 1), FST::RELATION('S', 1), FST::RELATION('T', 1),\
				  FST::RELATION('U', 1), FST::RELATION('V', 1), FST::RELATION('W', 1), FST::RELATION('X', 1), FST::RELATION('Y', 1),\
				  FST::RELATION('Z', 1), FST::RELATION('Z', 0), FST::RELATION('_', 1), FST::RELATION('-', 0)),\
	FST::NODE());



namespace LA {
	bool stringFlag = false;
	char* str = new char[MAX_LEX_SIZE];
	bool intFlag = false;
	bool param = false;

	bool funcParam = false;
	char FST()
	{
		FST_INT
			if (FST::execute(_int))
			{
				intFlag = true;
				return LEX_INTEGER;
			}
		FST_STRING
			if (FST::execute(_string))
			{
				stringFlag = true;
				return LEX_STRING;
			}
		FST_FUNC
			if (FST::execute(_function))
			{
				if (!funcParam) {
					funcParam = true;
				}
				return LEX_FUNCTION;
			}
		FST_DECLARE
			if (FST::execute(_declare))
				return LEX_DECLARE;
		FST_RETURN
			if (FST::execute(_return))
				return LEX_RETURN;
		FST_MAIN
			if (FST::execute(_main))
			{
				return LEX_MAIN;
			}
		FST_PRINT
			if (FST::execute(_print))
				return LEX_PRINT;
		FST_STRING_LITERAL
			if (FST::execute(_stringLit))
				return LEX_LITERAL;
		FST_INT_LITERAL
			if (FST::execute(_intLit))
				return LEX_LITERAL;
		FST_INDEF
			if (FST::execute(_idenf)) {
				return LEX_ID;
			}
		if (str[0] == ';')
			return LEX_SEMICOLON;
		if (str[0] == ',')
			return LEX_COMMA;
		if (str[0] == '{')
			return LEX_LEFTBRACE;
		if (str[0] == '}')
			return LEX_BRACELET;
		if (str[0] == '(') {
			if (funcParam) {
				param = true;
			}
			return LEX_LEFTHESIS;
		}
		if (str[0] == '=') {
			return LEX_EQUAL;
		}

		if (str[0] == ')')
		{
			if (param && funcParam) {
				param = false;
				funcParam = false;
			}
			return LEX_RIGHTHESIS;
		}
		if (str[0] == '+' || str[0] == '-' || str[0] == '*' || str[0] == '/')
			return LEX_PLUS;

		return NULL;
	}

	void add_LT(LT::Entry& Entry_LT, int size, int idxF)
	{
		Entry_LT.idxTI = size;
		Entry_LT.sn = idxF;
	}

	void add_IT(IT::Entry& Entry_TI, int line, char* str, IT::IDDATATYPE data, IT::IDTYPE type, int value)
	{
		Entry_TI.idxfirstLE = line;
		memcpy(Entry_TI.id, str, 5); // ÓÑÅ×ÅÍÈÅ ÄÎ 5 ÑÈÌÂÎËÎÂ
		Entry_TI.id[5] = '\0';
		Entry_TI.iddatatype = data;
		Entry_TI.idtype = type;
		Entry_TI.value.vint = value;
	}

	LT::LexTable _LTable = LT::Create(LT_MAXSIZE - 1);
	IT::IdTable _ITable = IT::Create(TI_MAXSIZE - 1);

	int count = 0;

	void LA(In::IN& in) {
		int numberStrings = 0;
		LT::Entry Entry_LT;
		IT::Entry Entry_TI;
		int line = 1;
		int indexIT = -1;
		bool TypeFlag = false;
		bool addedTI = false;
		bool chert = false;
		int bufferIndex = 0;
		bool declareFunctionFlag = false;
		int idLex = 0;
		int numberLiteral = 0;
		unsigned char* entry_token = new unsigned char[10000];
		bool AddedToTI = false;
		entry_token[count++] = '0' + line / 10;
		entry_token[count++] = '0' + line % 10;
		entry_token[count++] = ':';
		entry_token[count++] = ' ';
		str[0] = '\0';


		for (int i = 0; in.text[i] != '\0'; i++) {
			if (in.text[i] != ' ' && in.text[i] != '|') {
				str[bufferIndex] = in.text[i];
				bufferIndex++;
				if (bufferIndex >= MAX_LEX_SIZE) {
					throw ERROR_THROW(119);
				}
				continue;
			}
			if (str[0] == '|') {
				line++;
				entry_token[count++] = '\n';
				entry_token[count++] = '0' + line / 10;
				entry_token[count++] = '0' + line % 10;
				entry_token[count++] = ':';
				entry_token[count++] = ' ';
				continue;
			}
			else {
				if (str[0] == '\0') {
					continue; }
				str[bufferIndex] = '\0';
				Entry_LT.lexema[0] = FST();

				if (Entry_LT.lexema[0] == NULL) {
					
					return; }
				if (Entry_LT.lexema[0] == LEX_MAIN) {
					add_LT(Entry_LT, _ITable.size, line);
					add_IT(Entry_TI, line, str, IT::INT, IT::F, NULL);
					indexIT = IT::search(_ITable, Entry_TI);
					i--;
					if (indexIT >= 0) { std::cout << "SEARCH ERROR!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << std::endl; exit(1); }
					if (indexIT == -1) {
						IT::Add(_ITable, Entry_TI);
						LT::Add(_LTable, Entry_LT);
						entry_token[count++] = Entry_LT.lexema[0];
						Entry_LT.lexema[0] = NULL;
						bufferIndex = 0;
						std::memset(str, NULL, bufferIndex + 1);
						str[0] = '|';
						continue;
					}
				}
				if (Entry_LT.lexema[0] == LEX_ID) {
					add_LT(Entry_LT, _ITable.size, line);
					add_IT(Entry_TI, line, str, IT::INT, IT::L, NULL);
					if (_LTable.table[_LTable.size - 2].lexema[0] == LEX_DECLARE) {
						if (_LTable.table[_LTable.size - 1].lexema[0] == LEX_STRING && stringFlag) {
							Entry_TI.iddatatype = IT::STR;
							strcpy_s(Entry_TI.value.vstr->str, "");
							stringFlag = false;
						}

					}
					if (_LTable.table[_LTable.size - 1].lexema[0] == LEX_FUNCTION) {
						Entry_TI.idtype = IT::F;

						if (_LTable.table[_LTable.size - 2].lexema[0] == LEX_STRING && stringFlag) {
							Entry_TI.iddatatype = IT::STR;
							strcpy_s(Entry_TI.value.vstr->str, "");
							stringFlag = false;
						}
					}
					if (funcParam && param) {
						Entry_TI.idtype = IT::P;
						if (_LTable.table[_LTable.size - 1].lexema[0] == LEX_STRING && stringFlag) {
							Entry_TI.iddatatype = IT::STR;
							strcpy_s(Entry_TI.value.vstr->str, "");
							stringFlag = false;
							Entry_LT.idxTI = _ITable.size;
							IT::Add(_ITable, Entry_TI);
							LT::Add(_LTable, Entry_LT);
							entry_token[count++] = Entry_LT.lexema[0];
							Entry_LT.lexema[0] = NULL;
							bufferIndex = 0;
							std::memset(str, NULL, bufferIndex + 1);
							continue;
						}


					}
					/*if (_LTable.table[_LTable.size - 2].lexema[0] == LEX_COMMA && _ITable.table[_LTable.table[_LTable.size - 2].idxTI].idtype == IT::P) {
						Entry_TI.idtype = IT::P;
						if (_LTable.table[_LTable.size - 1].lexema[0] == LEX_STRING && stringFlag) {
							Entry_TI.iddatatype = IT::STR;
							strcpy_s(Entry_TI.value.vstr->str, "");
							stringFlag = false;
						}
						indexIT = IT::search(_ITable, Entry_TI);
						if (indexIT >= 0) {
							std::cout << "FST_LIT ERROR!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << std::endl;
						}
						else {
							Entry_LT.idxTI = _LTable.size;
							IT::Add(_ITable, Entry_TI);
							LT::Add(_LTable, Entry_LT);
							entry_token[count++] = Entry_LT.lexema[0];
							Entry_LT.lexema[0] = NULL;
							AddedToTI = true;

						}
					}*/
					if (!AddedToTI) {
						int intdexTI = IT::search(_ITable, Entry_TI);

						if (indexIT >= 0) {
							add_LT(Entry_LT, _ITable.size, line);
							if (_ITable.table[intdexTI].iddatatype == IT::INT) {
								Entry_TI.iddatatype = IT::INT;
							}
							if (_ITable.table[intdexTI].iddatatype == IT::STR) {
								Entry_TI.iddatatype = IT::STR;
							}
							IT::Add(_ITable, Entry_TI);
							LT::Add(_LTable, Entry_LT);
							entry_token[count++] = Entry_LT.lexema[0];
							Entry_LT.lexema[0] = NULL;
							AddedToTI = false;
							bufferIndex = 0;
							std::memset(str, NULL, bufferIndex + 1);
							continue;
						}
						else {
							add_LT(Entry_LT, _ITable.size, line);
							IT::Add(_ITable, Entry_TI);
							LT::Add(_LTable, Entry_LT);
							entry_token[count++] = Entry_LT.lexema[0];
							Entry_LT.lexema[0] = NULL;
							AddedToTI = false;
							bufferIndex = 0;
							std::memset(str, NULL, bufferIndex + 1);
							continue;
						}


					}


					std::memset(Entry_TI.id, NULL, 5);
					Entry_TI.value.vint = NULL;
					AddedToTI = false;
					bufferIndex = 0;
					std::memset(str, NULL, bufferIndex + 1);
					continue;
				}
				if (Entry_LT.lexema[0] == LEX_LITERAL) {
					add_LT(Entry_LT, _ITable.size, line);
					numberLiteral++;
					i--;
					if (_LTable.table[_LTable.size - 1].lexema[0] == LEX_RETURN) {
						add_IT(Entry_TI, line, str, IT::INT, IT::L, atoi(str));
						sprintf_s(Entry_TI.id, "L%d", numberLiteral);
						entry_token[count++] = Entry_LT.lexema[0];
						LT::Add(_LTable, Entry_LT);
						IT::Add(_ITable, Entry_TI);
						Entry_LT.lexema[0] = NULL;
						intFlag = false;
						bufferIndex = 0;
						std::memset(str, NULL, bufferIndex + 1);
						continue;
					}
					if (_ITable.table[_LTable.table[_LTable.size - 2].idxTI].iddatatype == IT::INT) {
						add_IT(Entry_TI, line, str, IT::INT, IT::L, atoi(str));
						sprintf_s(Entry_TI.id, "L%d", numberLiteral);

						entry_token[count++] = Entry_LT.lexema[0];
						LT::Add(_LTable, Entry_LT);
						IT::Add(_ITable, Entry_TI);
						Entry_LT.lexema[0] = NULL;
						intFlag = false;
						bufferIndex = 0;
						std::memset(str, NULL, bufferIndex + 1);

						continue;
					}
					if (_ITable.table[_LTable.table[_LTable.size - 2].idxTI].iddatatype == IT::STR) {
						Entry_TI.iddatatype = IT::STR;
						Entry_TI.idtype = IT::L;
						for (int j = 0; j < strlen(str); j++) {
							Entry_TI.value.vstr->str[j] = str[j];
						}
						Entry_TI.value.vstr[numberStrings].str[strlen(str)] = '\0';
						Entry_TI.value.vstr[numberStrings++].len = strlen(str);
						entry_token[count++] = Entry_LT.lexema[0];
						LT::Add(_LTable, Entry_LT);
						IT::Add(_ITable, Entry_TI);
						Entry_LT.lexema[0] = NULL;
						stringFlag = false;
						bufferIndex = 0;
						std::memset(str, NULL, bufferIndex + 1);
						i--;
						continue;
					}
					if (intFlag) {
						Entry_TI.iddatatype = IT::INT;
						Entry_TI.idtype = IT::L;
						Entry_TI.value.vint = atoi(str);
						entry_token[count++] = Entry_LT.lexema[0];
						LT::Add(_LTable, Entry_LT);
						IT::Add(_ITable, Entry_TI);
						Entry_LT.lexema[0] = NULL;
						intFlag = false;
						bufferIndex = 0;
						std::memset(str, NULL, bufferIndex + 1);

						continue;
					}
					if (stringFlag) {
						Entry_TI.iddatatype = IT::STR;
						Entry_TI.idtype = IT::L;
						for (int j = 0; j < strlen(str); j++) {
							Entry_TI.value.vstr->str[j] = str[j];
						}
						Entry_TI.value.vstr[numberStrings].str[strlen(str)] = '\0';
						Entry_TI.value.vstr[numberStrings++].len = strlen(str);
						entry_token[count++] = Entry_LT.lexema[0];
						LT::Add(_LTable, Entry_LT);
						IT::Add(_ITable, Entry_TI);
						Entry_LT.lexema[0] = NULL;
						stringFlag = false;
						bufferIndex = 0;
						std::memset(str, NULL, bufferIndex + 1);
						i--;
						continue;
					}
					bufferIndex = 0;
					std::memset(str, NULL, bufferIndex + 1);
				}

				if (Entry_LT.lexema[0] != LEX_ID && Entry_LT.lexema[0] != LEX_LITERAL && Entry_LT.lexema[0] != LEX_MAIN) {
					add_LT(Entry_LT, -1, line);
					LT::Add(_LTable, Entry_LT);
					entry_token[count++] = Entry_LT.lexema[0];
					Entry_LT.lexema[0] = NULL;
					bufferIndex = 0;
					std::memset(str, NULL, bufferIndex + 1);
				}
			}
			if (in.text[i] == '|') {
				line++;
				entry_token[count++] = '\n';
				entry_token[count++] = '0' + line / 10;
				entry_token[count++] = '0' + line % 10;
				entry_token[count++] = ':';
				entry_token[count++] = ' ';
				str[0] = '|';
			}
		}

		entry_token[count] = '\0';
		for (int i = 0; entry_token[i] != '\0'; i++) {
			std::cout << entry_token[i];
		}
	}
}