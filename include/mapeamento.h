#ifndef _MAPEAMENTO_H_
#define _MAPEAMENTO_H_

#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include <string>
using std::string;

#include "funcoes.h"
#include "cache.h"
#include "mp.h"

void mapeamentoDireto(Mp *m, Cache *c, int local_mem, int line);

void totalmenteAssociativoAleatorio(Mp *m, Cache *c, int local_mem ,int line, int sizeBlock);

void totalmenteAssociativoFIFO(Mp *m, Cache *c, int local_mem, int line, int sizeBlock);

#endif//_MAPEAMENTO_H_
