#include "cache.h"

Cache::Cache() {
}

Cache::~Cache() {
}

int Cache::getLinha() {
	return linha;
}

void Cache::setLinha(int l) {
	linha = l;
}

ostream& operator<<(ostream &os, Cache &c) {
	// os << "Linha-Bloco-Endereco-Conteudo" << endl;
	// os << c.linha << " - " << c.bloco;

	return os;
}

istream& operator>>(istream &is, Cache &c) {

	return is;
}
