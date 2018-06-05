#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <string>
using std::string;
using std::getline;
#include <sstream>
using std::stringstream;
#include "funcoes.h"
#include "mapeamento.h"

int main() {

	int sizeBlock, line, block, map, setSize, sub, write;

	Cache *c; // Declaração de ponteiro de obj do tipo Cache
	Mp *m;		// Declaração de ponteiro de obj do tipo Mp

	configuracao(sizeBlock, line, block, map, setSize, sub, write);

	c = new Cache[line];
	m = new Mp[block];

	//Inicializa a memória principal e a memória cache
	init(m, c, sizeBlock, line, block, map, setSize, sub, write);

	// Declaração de strings para leitura dos comandos digitado pelo usuário
	string linha, comando = "", num;

	do{
		cout << "comand > ";
		getline(cin, linha);
		stringstream ss(linha);
		ss >> comando >> num;

		if (comando == "Read" or comando == "read" or comando == "READ") {

			int end = stoi(num);
			int local_mem = end/sizeBlock;

			//Mapeamento direto (1 - Aleatório)
			if (map == 1) {
				mapeamentoDireto(m, c, local_mem, line);
			}

			//Mapeamento Totalmente Associativo (2 - Totalmente associativo e 1 - Aleatório)
			if (map == 2 and sub == 1) {
				totalmenteAssociativoAleatorio(m, c, local_mem, line, sizeBlock);
			}

			//Mapeamento Totalmente Associativo (2 - Totalmente associativo e 2 - FIFO)
			if (map == 2 and sub == 2) {
				totalmenteAssociativoFIFO(m, c, local_mem, line, sizeBlock);
			}

			//Mapeamento Totalmente Associativo (2 - Totalmente associativo e 3 - LRU)
			if (map == 2 and sub == 3) {
				/* code */
			}

			//Mapeamento Totalmente Associativo (2 - Totalmente associativo e 4 - LFU)
			if (map == 2 and sub == 4) {
				/* code */
			}

			//Mapeamento Parcialmente Associativo (2 - Parcialmente associativo e 1 - Aleatório)
			if (map == 3 and sub == 1) {
				/* code */
			}

			//Mapeamento Parcialmente Associativo (2 - Parcialmente associativo e 2 - FIFO)
			if (map == 3 and sub == 2) {
				/* code */
			}

			//Mapeamento Parcialmente Associativo (2 - Parcialmente associativo e 3 - LFU)
			if (map == 3 and sub == 3) {
				/* code */
			}

			//Mapeamento Parcialmente Associativo (2 - Parcialmente associativo e 4 - LRU)
			if (map == 3 and sub == 4) {
				/* code */
			}
		}

		print(m, c, sizeBlock, block, line);
	}while (comando != "exit");


	return 0;
}
