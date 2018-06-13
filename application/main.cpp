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

	int tamanho_bloco, linha, bloco, mapeamento, setSize, substituicao;

	Cache *cache; // Declaração de ponteiro de obj do tipo Cache
	Mp *memoriap;		// Declaração de ponteiro de obj do tipo Mp

	queue<int> fila;
	std::map<int, int> via;

	configuracao(tamanho_bloco, linha, bloco, mapeamento, setSize, substituicao);

	int vetor[][] = new int*[linha];
	for (int i = 0; i < linha; ++i)
		vetor[i] = new int[2];

	cache = new Cache[linha];
	memoriap = new Mp[bloco];

	//Inicializa a memória principal e a memória cache
	init(memoriap, cache, tamanho_bloco, linha, bloco, mapeamento, setSize, substituicao);

	// Declaração de strings para leitura dos comandos digitado pelo usuário
	string leitura, comando = "", num;

	do{
		cout << endl;
		cout << "comand > ";
		getline(cin, leitura);
		stringstream ss(leitura);
		ss >> comando >> num;

		if (comando == "Read" or comando == "read" or comando == "READ") {

			int end = stoi(num);
			int local_mem = end/tamanho_bloco;

			//Mapeamento direto (1 - Aleatório)
			if (mapeamento == 1) {
				mapeamentoDireto(memoriap, cache, local_mem, linha);
			}

			//Mapeamento Totalmente Associativo (2 - Totalmente associativo e 1 - Aleatório)
			if (mapeamento == 2 and substituicao == 1) {
				totalmenteAssociativoAleatorio(memoriap, cache, local_mem, linha, tamanho_bloco);
			}

			//Mapeamento Totalmente Associativo (2 - Totalmente associativo e 2 - FIFO)
			if (mapeamento == 2 and substituicao == 2) {
				totalmenteAssociativoFIFO(memoriap, cache, local_mem, linha, tamanho_bloco);
			}

			//Mapeamento Totalmente Associativo (2 - Totalmente associativo e 3 - LRU)
			if (mapeamento == 2 and substituicao == 3) {
				/* code */
			}

			//Mapeamento Totalmente Associativo (2 - Totalmente associativo e 4 - LFU)
			if (mapeamento == 2 and substituicao == 4) {
				/* code */
			}

			//Mapeamento Parcialmente Associativo (2 - Parcialmente associativo e 1 - Aleatório)
			if (mapeamento == 3 and substituicao == 1) {
				/* code */
			}

			//Mapeamento Parcialmente Associativo (2 - Parcialmente associativo e 2 - FIFO)
			if (mapeamento == 3 and substituicao == 2) {
				/* code */
			}

			//Mapeamento Parcialmente Associativo (2 - Parcialmente associativo e 3 - LFU)
			if (mapeamento == 3 and substituicao == 3) {
				/* code */
			}

			//Mapeamento Parcialmente Associativo (2 - Parcialmente associativo e 4 - LRU)
			if (mapeamento == 3 and substituicao == 4) {
				/* code */
			}
		}

		print(memoriap, cache, tamanho_bloco, bloco, linha);
	}while (comando != "exit");

	for (int i = 0; i < 2; ++i)
		delete[] vetor[i];

	delete[] vetor;
	delete[] cache;
	delete[] memoriap;

	return 0;
}
