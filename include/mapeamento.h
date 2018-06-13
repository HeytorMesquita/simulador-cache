#ifndef _MAPEAMENTO_H_
#define _MAPEAMENTO_H_

#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <queue>
using std::queue;

#include <map>
using std::map;

#include "funcoes.h"
#include "cache.h"
#include "mp.h"

void mapeamentoDireto(Mp *memoria_principal, Cache *cache, int local_mem, int linha);

void totalmenteAssociativoAleatorio(Mp *memoria_principal, Cache *cache, int local_mem ,int linha, int tamanho_bloco);

void totalmenteAssociativoFIFO(Mp *memoria_principal, Cache *cache, int local_mem, int linha, int tamanho_bloco, queue<int> &fila);

void totalmenteAssociativoLFU(Mp *memoria_principal, Cache *cache, int local_mem, int linha, int tamanho_bloco, map<int, int> &via);

void totalmenteAssociativoLRU(Mp *memoria_principal, Cache *cache, int local_mem, int linha, int tamanho_bloco, map<int, int> &ciclo);

// void parcialmenteAssociativoAleatorio(Mp *memoria_principal, Cache *cache, int local_mem ,int linha, int tamanho_bloco);

// void parcialmenteAssociativoFIFO(Mp *memoria_principal, Cache *cache, int local_mem, int linha, int tamanho_bloco, queue<int> &fila);

// void parcialmenteAssociativoLFU(Mp *memoria_principal, Cache *cache, int local_mem, int linha, int tamanho_bloco, map<int, int> &via);

// void parcialmenteAssociativoLRU(Mp *memoria_principal, Cache *cache, int local_mem, int linha, int tamanho_bloco, map<int, int> &ciclo);

#endif//_MAPEAMENTO_H_
