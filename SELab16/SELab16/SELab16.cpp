#include <iostream>
#include "tchar.h"
#include "FST.h"


int _tmain(int argc, _TCHAR* argv[]) {
	setlocale(LC_ALL, "ru");

	FST::FST fst1(
		(char*)"aaabbbaba",
		4,
		FST::NODE(3, FST::RELATION('a', 0), FST::RELATION('b', 0), FST::RELATION('a', 1)),
		FST::NODE(1, FST::RELATION('b', 2)),
		FST::NODE(1, FST::RELATION('a', 3)),
		FST::NODE()
	);
	if (FST::execute(fst1))
		std::cout << "Цепочка " << fst1.string << " распознана" << std::endl;
	else std::cout << "Цепочка " << fst1.string << " не распознана" << std::endl;

	FST::FST fst2(
		(char*)"aaabbbabba",
		4,
		FST::NODE(3, FST::RELATION('a', 0), FST::RELATION('b', 0), FST::RELATION('a', 1)),
		FST::NODE(1, FST::RELATION('b', 2)),
		FST::NODE(1, FST::RELATION('a', 3)),
		FST::NODE()
	);
	if (FST::execute(fst2))
		std::cout << "Цепочка " << fst2.string << " распознана" << std::endl;
	else
		std::cout << "Цепочка " << fst2.string << " не распознана" << std::endl;

	FST::FST fst3(
		(char*)"awwbfwwcfwdfwwwwwe", // ЭТО ПРАВИЛЬНО
		8,
		FST::NODE(1, FST::RELATION('a', 1)), //0
		FST::NODE(1, FST::RELATION('w', 2)), // 1
		FST::NODE(5, FST::RELATION('b', 3), FST::RELATION('c', 3), FST::RELATION('d', 3), FST::RELATION('w', 2), FST::RELATION('w', 6)), //2
		FST::NODE(1, FST::RELATION('f', 4)), //3
		FST::NODE(1, FST::RELATION('w', 5)), //4
		FST::NODE(5, FST::RELATION('w', 5), FST::RELATION('w', 6), FST::RELATION('b', 3), FST::RELATION('c', 3), FST::RELATION('d', 3)), //5
		FST::NODE(2, FST::RELATION('w', 6), FST::RELATION('e', 7)), //6
		FST::NODE() // 7
	);

	if (FST::execute(fst3))
		std::cout << "Цепочка " << fst3.string << " распознана" << std::endl;
	else
		std::cout << "Цепочка " << fst3.string << " не распознана" << std::endl;

	FST::FST fst4( 
		(char*)"awwe",
		8,
		FST::NODE(1, FST::RELATION('a', 1)), //0
		FST::NODE(1, FST::RELATION('w', 2)), // 1
		FST::NODE(5, FST::RELATION('b', 3), FST::RELATION('c', 3), FST::RELATION('d', 3), FST::RELATION('w', 2), FST::RELATION('w', 6)), //2
		FST::NODE(1, FST::RELATION('f', 4)), //3
		FST::NODE(1, FST::RELATION('w', 5)), //4
		FST::NODE(5, FST::RELATION('w', 5), FST::RELATION('w', 6), FST::RELATION('b', 3), FST::RELATION('c', 3), FST::RELATION('d', 3)), //5
		FST::NODE(2, FST::RELATION('w', 6), FST::RELATION('e', 7)), //6
		FST::NODE() // 7
	);


	if (FST::execute(fst4))
		std::cout << "Цепочка " << fst4.string << " распознана" << std::endl;
	else
		std::cout << "Цепочка " << fst4.string << " не распознана" << std::endl;

	FST::FST fst5( 
		(char*)"awcfwbfwdfwwe",
		8,
		FST::NODE(1, FST::RELATION('a', 1)), //0
		FST::NODE(1, FST::RELATION('w', 2)), // 1
		FST::NODE(5, FST::RELATION('b', 3), FST::RELATION('c', 3), FST::RELATION('d', 3), FST::RELATION('w', 2), FST::RELATION('w', 6)), //2
		FST::NODE(1, FST::RELATION('f', 4)), //3
		FST::NODE(1, FST::RELATION('w', 5)), //4
		FST::NODE(5, FST::RELATION('w', 5), FST::RELATION('w', 6), FST::RELATION('b', 3), FST::RELATION('c', 3), FST::RELATION('d', 3)), //5
		FST::NODE(2, FST::RELATION('w', 6), FST::RELATION('e', 7)), //6
		FST::NODE() // 7
	);


	if (FST::execute(fst5))
		std::cout << "Цепочка " << fst5.string << " распознана" << std::endl;
	else
		std::cout << "Цепочка " << fst5.string << " не распознана" << std::endl;

	FST::FST fst6( 
		(char*)"awcfwcfwcfwwe",
		8,
		FST::NODE(1, FST::RELATION('a', 1)), //0
		FST::NODE(1, FST::RELATION('w', 2)), // 1
		FST::NODE(5, FST::RELATION('b', 3), FST::RELATION('c', 3), FST::RELATION('d', 3), FST::RELATION('w', 2), FST::RELATION('w', 6)), //2
		FST::NODE(1, FST::RELATION('f', 4)), //3
		FST::NODE(1, FST::RELATION('w', 5)), //4
		FST::NODE(5, FST::RELATION('w', 5), FST::RELATION('w', 6), FST::RELATION('b', 3), FST::RELATION('c', 3), FST::RELATION('d', 3)), //5
		FST::NODE(2, FST::RELATION('w', 6), FST::RELATION('e', 7)), //6
		FST::NODE() // 7
	);


	if (FST::execute(fst6))
		std::cout << "Цепочка " << fst6.string << " распознана" << std::endl;
	else
		std::cout << "Цепочка " << fst6.string << " не распознана" << std::endl;

	FST::FST fst7( 
		(char*)"awcfwcfwcfwwwwe",
		8,
		FST::NODE(1, FST::RELATION('a', 1)), //0
		FST::NODE(1, FST::RELATION('w', 2)), // 1
		FST::NODE(5, FST::RELATION('b', 3), FST::RELATION('c', 3), FST::RELATION('d', 3), FST::RELATION('w', 2), FST::RELATION('w', 6)), //2
		FST::NODE(1, FST::RELATION('f', 4)), //3
		FST::NODE(1, FST::RELATION('w', 5)), //4
		FST::NODE(5, FST::RELATION('w', 5), FST::RELATION('w', 6), FST::RELATION('b', 3), FST::RELATION('c', 3), FST::RELATION('d', 3)), //5
		FST::NODE(2, FST::RELATION('w', 6), FST::RELATION('e', 7)), //6
		FST::NODE() // 7
	);


	if (FST::execute(fst7))
		std::cout << "Цепочка " << fst7.string << " распознана" << std::endl;
	else
		std::cout << "Цепочка " << fst7.string << " не распознана" << std::endl;

	FST::FST fst8( 
		(char*)"awbfwwe",
		8,
		FST::NODE(1, FST::RELATION('a', 1)), //0
		FST::NODE(1, FST::RELATION('w', 2)), // 1
		FST::NODE(5, FST::RELATION('b', 3), FST::RELATION('c', 3), FST::RELATION('d', 3), FST::RELATION('w', 2), FST::RELATION('w', 6)), //2
		FST::NODE(1, FST::RELATION('f', 4)), //3
		FST::NODE(1, FST::RELATION('w', 5)), //4
		FST::NODE(5, FST::RELATION('w', 5), FST::RELATION('w', 6), FST::RELATION('b', 3), FST::RELATION('c', 3), FST::RELATION('d', 3)), //5
		FST::NODE(2, FST::RELATION('w', 6), FST::RELATION('e', 7)), //6
		FST::NODE() // 7
	);


	if (FST::execute(fst8))
		std::cout << "Цепочка " << fst8.string << " распознана" << std::endl;
	else
		std::cout << "Цепочка " << fst8.string << " не распознана" << std::endl;

	FST::FST fst9( 
		(char*)"awcfwdfwdfwdfwwe",
		8,
		FST::NODE(1, FST::RELATION('a', 1)), //0
		FST::NODE(1, FST::RELATION('w', 2)), // 1
		FST::NODE(5, FST::RELATION('b', 3), FST::RELATION('c', 3), FST::RELATION('d', 3), FST::RELATION('w', 2), FST::RELATION('w', 6)), //2
		FST::NODE(1, FST::RELATION('f', 4)), //3
		FST::NODE(1, FST::RELATION('w', 5)), //4
		FST::NODE(5, FST::RELATION('w', 5), FST::RELATION('w', 6), FST::RELATION('b', 3), FST::RELATION('c', 3), FST::RELATION('d', 3)), //5
		FST::NODE(2, FST::RELATION('w', 6), FST::RELATION('e', 7)), //6
		FST::NODE() // 7
	);


	if (FST::execute(fst9))
		std::cout << "Цепочка " << fst9.string << " распознана" << std::endl;
	else
		std::cout << "Цепочка " << fst9.string << " не распознана" << std::endl;

	FST::FST fst10( 
		(char*)"awwwbfwwwwww",
		8,
		FST::NODE(1, FST::RELATION('a', 1)), //0
		FST::NODE(1, FST::RELATION('w', 2)), // 1
		FST::NODE(5, FST::RELATION('b', 3), FST::RELATION('c', 3), FST::RELATION('d', 3), FST::RELATION('w', 2), FST::RELATION('w', 6)), //2
		FST::NODE(1, FST::RELATION('f', 4)), //3
		FST::NODE(1, FST::RELATION('w', 5)), //4
		FST::NODE(5, FST::RELATION('w', 5), FST::RELATION('w', 6), FST::RELATION('b', 3), FST::RELATION('c', 3), FST::RELATION('d', 3)), //5
		FST::NODE(2, FST::RELATION('w', 6), FST::RELATION('e', 7)), //6
		FST::NODE() // 7
	);


	if (FST::execute(fst10))
		std::cout << "Цепочка " << fst10.string << " распознана" << std::endl;
	else
		std::cout << "Цепочка " << fst10.string << " не распознана" << std::endl;

	FST::FST fst11( 
		(char*)"aew",
		8,
		FST::NODE(1, FST::RELATION('a', 1)), //0
		FST::NODE(1, FST::RELATION('w', 2)), // 1
		FST::NODE(5, FST::RELATION('b', 3), FST::RELATION('c', 3), FST::RELATION('d', 3), FST::RELATION('w', 2), FST::RELATION('w', 6)), //2
		FST::NODE(1, FST::RELATION('f', 4)), //3
		FST::NODE(1, FST::RELATION('w', 5)), //4
		FST::NODE(5, FST::RELATION('w', 5), FST::RELATION('w', 6), FST::RELATION('b', 3), FST::RELATION('c', 3), FST::RELATION('d', 3)), //5
		FST::NODE(2, FST::RELATION('w', 6), FST::RELATION('e', 7)), //6
		FST::NODE() // 7
	);


	if (FST::execute(fst11))
		std::cout << "Цепочка " << fst11.string << " распознана" << std::endl;
	else
		std::cout << "Цепочка " << fst11.string << " не распознана" << std::endl;

	FST::FST fst12( 
		(char*)"afcdefg",
		9,
		FST::NODE(1, FST::RELATION('a', 1)), //0
		FST::NODE(2, FST::RELATION('f', 2), FST::RELATION('f', 7)), // 1
		FST::NODE(3, FST::RELATION('f', 2), FST::RELATION('c', 3), FST::RELATION('b', 5)), //2
		FST::NODE(1, FST::RELATION('d', 4)), //3
		FST::NODE(2, FST::RELATION('d', 4), FST::RELATION('e', 6)), //4
		FST::NODE(1, FST::RELATION('e', 6)), //5
		FST::NODE(3, FST::RELATION('b', 5), FST::RELATION('c', 3), FST::RELATION('f', 7)), //6
		FST::NODE(2, FST::RELATION('f', 7), FST::RELATION('g', 8)), //7
		FST::NODE() // 9
	);


	if (FST::execute(fst12))
		std::cout << "Цепочка " << fst12.string << " распознана" << std::endl;
	else
		std::cout << "Цепочка " << fst12.string << " не распознана" << std::endl;


		FST::FST fst13( 
		(char*)"abcbbdbebbbfg",
		10,
		FST::NODE(1, FST::RELATION('a', 1)), //0
		FST::NODE(1, FST::RELATION('b', 2)), // 1
		FST::NODE(6, FST::RELATION('b', 2), FST::RELATION('b', 7), FST::RELATION('f', 8), FST::RELATION('c', 3), FST::RELATION('d', 4), FST::RELATION('e',5)), //2
		FST::NODE(1, FST::RELATION('b', 6)), //3
		FST::NODE(1, FST::RELATION('b', 6)), //4
		FST::NODE(1, FST::RELATION('b', 6)), //5
		FST::NODE(6, FST::RELATION('b', 6), FST::RELATION('b', 7), FST::RELATION('c', 3), FST::RELATION('d', 4), FST::RELATION('e', 5), FST::RELATION('f', 8)), //6
		FST::NODE(2, FST::RELATION('b', 7), FST::RELATION('f', 8)), //7
		FST::NODE(1, FST::RELATION('g', 9)), //8
		FST::NODE() // 9
	);


	if (FST::execute(fst13))
		std::cout << "Цепочка " << fst13.string << " распознана" << std::endl;
	else
		std::cout << "Цепочка " << fst13.string << " не распознана" << std::endl;



	system("pause");
	return 0;
}