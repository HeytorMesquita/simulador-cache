#include "mapeamento.h"

void mapeamentoDireto(Mp *memoria_principal, Cache *cache, int local_memoria, int linha){
  int linha_cache = local_memoria % linha;

  if (cache[linha_cache].getBloco() == local_memoria)
    cout << "HIT!" << endl;
  else {
    cout << "MISS!";

    cache[linha_cache].setBloco(memoria_principal[local_memoria].getBloco());
    cache[linha_cache].setEndereco(memoria_principal[local_memoria].getEndereco());
    cache[linha_cache].setConteudo(memoria_principal[local_memoria].getConteudo());
    cout << "Alocado na linha " << linha_cache << endl;
  }
}

void totalmenteAssociativoAleatorio(Mp *memoria_principal, Cache *cache, int local_memoria ,int linha, int tamanho_bloco){
  int local_cache = -1;
  bool encontrado = false;

  for (int i = 0; i < linha; i++)
    if (cache[i].getBloco() == local_memoria) encontrado = true;

  if (!encontrado) {
    cout << "MISS!" << endl;
    for (int i = 0; i < linha; i++) {
      if (cache[i].getBloco() == -1) {
        local_cache = i;
        i = linha;
      }
    }

    if (local_cache != -1) {
      for (int i = 0; i < tamanho_bloco; i++)
        cache[local_cache].setEndereco(memoria_principal[local_memoria].getEndereco());
      cache[local_cache].setBloco(local_memoria);
    } else {
      srand (time(NULL));
      local_cache = rand() % linha;
      for (int i = 0; i < tamanho_bloco; i++)
        cache[local_cache].setEndereco(memoria_principal[local_memoria].getEndereco());
      cache[local_cache].setBloco(local_memoria);
    }
  } else {
    cout << "HIT!" << endl;
  }
}

void totalmenteAssociativoFIFO(Mp *memoria_principal, Cache *cache, int local_memoria, int linha, int tamanho_bloco){
  int local_cache = -1;
  bool encontrado = false;

  for (int i = 0; i < linha; i++)
    if (cache[i].getBloco() == local_memoria) encontrado = true;

  if (!encontrado) {
    cout << "MISS!" << endl;

    for (int i = 0; i < linha; i++) {
      if (cache[i].getBloco() == -1) {
        local_cache = i;
        i = linha;
      }
    }

    if (local_cache != -1) {
      for (int i = 0; i < tamanho_bloco; i++)
        cache[local_cache].setEndereco(memoria_principal[local_memoria].getEndereco());
      cache[local_cache].setBloco(local_memoria);
    } else {
      // ....
    }


  } else {
    cout << "HIT!" << endl;
  }

}
/*
void totalmenteAssociativoLRU(){

}

void totalmenteAssociativoLFU(){

}

void parcialmenteAssociativoAleatorio(){

}

void parcialmenteAssociativoFIFO(){

}

void parcialmenteAssociativoLRU(){

}

void parcialmenteAssociativoLFU(){

}
*/
