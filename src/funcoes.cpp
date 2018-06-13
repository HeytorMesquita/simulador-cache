#include "funcoes.h"

void configuracao(int &tamanhob, int &linha, int &bloco, int &mapeamento, int &conjunto, int &substituicao) {
	string leitura_linha;
	int cont = 0;

	// Caminho do arquivo
	ifstream entrada("data/config1.txt");

	// Verificando consistencia do arquivo
	if(!entrada) {
		cerr << "Erro na leitura do arquivo de configuracao." << endl;
		return ;
	}

	// contador
	while(getline(entrada, leitura_linha))
		cont++;

	// Verificando quantidade de linhas do arquivo de configuracao
	if(cont != 6) {
		cout << "Arquivo de configuracao incompleto!" << endl;
		exit(1) ;
	}

	// Voltando a leitura para o inicio do arquivo
	entrada.clear();
	entrada.seekg(entrada.beg);

	entrada >> tamanhob;
	entrada >> linha;
	entrada >> bloco;
	entrada >> mapeamento;
	entrada >> conjunto;
	entrada >> substituicao;
}

void init(Mp *memoriap, Cache *cache, int &tamanho_bloco, int &linha, int &bloco, int &mapeamento, int &conjunto, int &substituicao) {
	initMpCache(memoriap, cache, tamanho_bloco, bloco, linha);
}

void initMpCache(Mp *memoriap, Cache *cache, int tamanho_bloco, int bloco, int linha){
	// Inicializa a memoria principal
	int aux = 0;
	for(int i = 0; i < bloco; i++){
		memoriap[i].setBloco(i);
		for (int j = 0; j < tamanho_bloco; j++){
			memoriap[i].inserirEndereco(aux++);
			memoriap[i].inserirConteudo(aux*2);
		}
	}

	// Inicializa a memoria cache
	for (int k = 0; k < linha; k++){
		cache[k].setLinha(k);
		cache[k].setBloco(-1);
		for (int z = 0; z < tamanho_bloco; z++) {
			cache[k].inserirEndereco(-1);
			cache[k].inserirConteudo(-1);
		}
	}
}

void print(Mp *memoriap, Cache *cache, int tamanho_bloco, int bloco, int linha){
	cout << endl;
	cout << endl;	
	cout << "CACHE L1" << endl;
	cout << "Linha - Bloco - Endereco - Conteudo " << endl;
	for(int i = 0; i < linha; i++) {
		for(int j = 0; j < tamanho_bloco; j++) {
			vector<int> endereco = cache[i].getEndereco();
			vector<int> conteudo = cache[i].getConteudo();
			cout << cache[i].getLinha() << " - " << cache[i].getBloco() << " - "<< endereco[j] << " - " << conteudo[j];
			cout << endl;
		}
	}
	cout << endl;

	cout << "Memória Principal" << endl;
	cout << "Bloco - Endereco - Conteudo" << endl;
	for(int i = 0; i < bloco; i++) {
		for(int j = 0; j < tamanho_bloco; j++) {
			vector<int> v_endereco = memoriap[i].getEndereco();
			vector<int> v_conteudo = memoriap[i].getConteudo();
			cout << memoriap[i].getBloco() << " - " << v_endereco[j] << " - " << v_conteudo[j];
			cout << endl;
		}
	}

	cout << endl;
	cout << endl;
}
