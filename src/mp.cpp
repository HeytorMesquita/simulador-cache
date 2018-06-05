#include "mp.h"

Mp::Mp() {
}

Mp::~Mp() {
}

int Mp::getBloco(){
	return bloco;
}

void Mp::setBloco(int b){
	bloco = b;
}

vector<int> Mp::getEndereco() {
	return endereco;
}

void Mp::setEndereco(vector<int> e) {
	endereco = e;
}

vector<int> Mp::getConteudo() {
	return conteudo;
}

void Mp::setConteudo(vector<int> c) {
	conteudo = c;
}

void Mp::inserirConteudo(int co){
	conteudo.push_back(co);
}

void Mp::inserirEndereco(int en){
	endereco.push_back(en);
}

ostream& operator<<(ostream &os, Mp &m) {
	return os;
}

istream& operator>>(istream &is, Mp &m) {
	return is;
}
