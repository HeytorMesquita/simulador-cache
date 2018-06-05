#include "funcoes.h"

void configuracao(int &s, int &l, int &b, int &m, int &set_size, int &sub, int &write) {
	string linha;
	int cont = 0;

	// Caminho do arquivo
	ifstream entrada("data/config.txt");

	// Verificando consistencia do arquivo
	if(!entrada) {
		cerr << "Erro na leitura do arquivo de configuracao." << endl;
		return ;
	}

	// contador
	while(getline(entrada, linha))
		cont++;

	// Verificando quantidade de linhas do arquivo de configuracao
	if(cont != 7) {
		cout << "Arquivo de configuracao incompleto!" << endl;
		exit(1) ;
	}

	// Voltando a leitura para o inicio do arquivo
	entrada.clear();
	entrada.seekg(entrada.beg);

	entrada >> s;
	entrada >> l;
	entrada >> b;
	entrada >> m;
	entrada >> set_size;
	entrada >> sub;
	entrada >> write;
}

void init(Mp *m, Cache *c, int &sizeBlock, int &line, int &block, int &map, int &setSize, int &sub, int &write)  {
	initMpCache(m, c, sizeBlock, block, line);
}

void initMpCache(Mp *m, Cache *c, int sizeBlock, int block, int line){
	// Inicializa a memoria principal
	int aux = 0;
	for(int i = 0; i < block; i++){
		m[i].setBloco(i);
		for (int j = 0; j < sizeBlock; j++){
			m[i].inserirEndereco(aux++);
			m[i].inserirConteudo(aux*2);
		}
	}

	// Inicializa a memoria cache
	for (int k = 0; k < line; k++){
		c[k].setLinha(k);
		c[k].setBloco(-1);
		for (int z = 0; z < sizeBlock; z++) {
			c[k].inserirEndereco(-1);
			c[k].inserirConteudo(-1);
		}
	}
}

void print(Mp *m, Cache *c, int sizeBlock, int block, int line){
	cout << "CACHE L1" << endl;
	cout << "Linha - Bloco - Endereco - Conteudo " << endl;
	for(int i = 0; i < line; i++) {
		for(int j = 0; j < sizeBlock; j++) {
			vector<int> v_1 = c[i].getEndereco();
			vector<int> v_2 = c[i].getConteudo();
			cout << c[i].getLinha() << " - " << c[i].getBloco() << " - "<< v_1[j] << " - " << v_2[j];
			cout << endl;
		}
	}
	cout << endl;
	cout << endl;

	cout << "Memória Principal" << endl;
	cout << "Bloco - Endereco - Conteudo" << endl;
	for(int i = 0; i < block; i++) {
		for(int j = 0; j < sizeBlock; j++) {
			vector<int> v1 = m[i].getEndereco();
			vector<int> v2 = m[i].getConteudo();
			cout << m[i].getBloco() << " - " << v1[j] << " - " << v2[j];
			cout << endl;
		}
	}
}
