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

void configuracao(int &s, int &l, int &b, int &map, int &setSize, int &sub, int &write);

void init(Mp *m, Cache *c, int &s, int &l, int &b, int &map, int &setSize, int &sub, int &write);

void initMpCache(Mp *m, Cache *c, int sizeBlock, int block, int line);

void print(Mp *m, Cache *c, int sizeBlock, int block, int line);

#endif//_FUNCOES_H_
