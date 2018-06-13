#ifndef _FUNCOES_H_
#define _FUNCOES_H_

#include <iostream>
using std::cout;
using std::cerr;
using std::endl;

#include <fstream>
using std::ifstream;

#include <string>
using std::string;
using std::stoi;
using std::getline;

#include "cache.h"
#include "mp.h"

void configuracao(int &tamanhob, int &linha, int &bloco, int &mapeamento, int &tamanho_bloco, int &substituicao);

void init(Mp *memoria_principal, Cache *cache, int &tamanhob, int &linha, int &bloco, int &mapeamento, int &tamanho_bloco, int &substituicao);

void initMpCache(Mp *memoria_principal, Cache *cache, int tamanho_bloco, int bloco, int linha);

void print(Mp *memoria_principal, Cache *cache, int tamanho_bloco, int bloco, int linha);

#endif//_FUNCOES_H_
