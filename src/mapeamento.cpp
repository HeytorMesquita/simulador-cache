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
    cout << "MISS! ";
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
      cache[local_cache].setConteudo(memoria_principal[local_memoria].getConteudo());
    } else {
      srand (time(NULL));
      local_cache = rand() % linha;
      for (int i = 0; i < tamanho_bloco; i++)
        cache[local_cache].setEndereco(memoria_principal[local_memoria].getEndereco());
      cache[local_cache].setBloco(local_memoria);
      cache[local_cache].setConteudo(memoria_principal[local_memoria].getConteudo());
    }
    cout << "Alocado na linha " << local_cache << endl;
  } else {
    cout << "HIT!" << endl;
  }
}

void totalmenteAssociativoFIFO(Mp *memoria_principal, Cache *cache, int local_memoria, int linha, int tamanho_bloco, queue<int> &fila){
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
        cache[local_cache].setConteudo(memoria_principal[local_memoria].getConteudo());
        cout << "bloco alocado na linha " << local_cache << endl;
      } else {
        local_cache = fifo.front();

        for(int i = 0; i < linha; i++) {
          if(c[i].getBloco() == local_cache) {
            c[i].setBloco(memoria_principal[local_memoria].getBloco());
            c[i].setEndereco(memoria_principal[local_memoria].getEndereco());
            c[i].setConteudo(memoria_principal[local_memoria].getConteudo());
            cout << "bloco alocado na linha " << i << endl;
            fila.pop();
            fila.push(local_memoria);
          }
        }
      }
    }
  } else {
    cout << "HIT!" << endl;
  }
}

void totalmenteAssociativoLRU(Mp *memoria_principal, Cache *cache, int local_mem, int linha, int tamanho_bloco, map<int, int>lru,int &ciclo){
  bool encontrado = false;
  int local_cache = -1;

  for(int i = 0; i < linha ; i++) {
    if(c[i].getBloco() == local_memoria) {
      encontrado = true;
      lru[local_memoria] = ciclo++;
    }
  }

  if(!encontrado){
    cout << "Miss "; 
    for(int i = 0; i < linha; i++) {
      if(c[i].getBloco() == -1) {
        local_cache = i;
        i = linha;
        break;
      }
    }

    if(local_cache != -1){
      for (int i = 0; i < tamanho_bloco; i++)
          cache[local_cache].setEndereco(memoria_principal[local_memoria].getEndereco());
        cache[local_cache].setBloco(local_memoria);
        cache[local_cache].setConteudo(memoria_principal[local_memoria].getConteudo());
      cout << "bloco alocado na linha " << prox << endl;
      lru.insert(pair<int, int>(local_memoria, ciclo++));

    } else {
      map<int, int>::iterator it = lru.begin();
      int prim = it->primeiro;
      int menor = it->segundo;
      cout << menor << endl;
      for(it = lru.begin(); it != lru.end(); ++it) {
        if(menor > it->segundo) {
          menor = it->segundo;
          prim = it->primeiro;
        }
      }

      int r = prim;
      for(int i = 0; i < line; i++) {
        if(c[i].getBloco() == r) {
          c[i].setBloco(m[local_memoria].getBloco());
          c[i].setEndereco(m[local_memoria].getEndereco());
          c[i].setConteudo(m[local_memoria].getConteudo());
          cout << "bloco alocado na linha " << i << endl;
          lru.erase(r);
          lru.insert(pair<int, int>(block_cache, ciclo));
          ciclo++;
        }
      }
    }
  } else {
    cout << "HIT" << endl;
  }



}

/*
void totalmenteAssociativoLFU(Mp *memoria_principal, Cache *cache, int local_mem, int linha, int tamanho_bloco, map<int, int> &via){

}

void parcialmenteAssociativoAleatorio(){
  bool hit = false, emp = false;
  int prox;

  int divisoes = line / setSize;

  int way = block_cache % setSize;

  cout << "\nVia: " << way << endl;

  for(int i = 0; i < setSize ; i++) {
    if(i == way) {
      for(int j = i; j < divisoes + i; j++) {
        if(c[j + i ].getBloco() == block_cache) {
          hit = true;
        }
      }
    }
  }

  if(!hit){
    for(int i = 0; i < setSize ; i++) {
      if(i == way) {
        for(int j = i; j < divisoes + i; j++) {
          if(c[ j + i ].getBloco() == -1) {
            emp = true;
            prox = i + j;
            break;
          }
        }
      }
    }

    if(emp){
      c[prox].setBloco(m[block_cache].getBloco());
      c[prox].setEndereco(m[block_cache].getEndereco());
      c[prox].setConteudo(m[block_cache].getConteudo());
      cout << "MISS => bloco alocado na linha " << prox << endl;

    } else {
      int r;
      
      srand(time(NULL));

      for(int i = 0; i < setSize; i++) {
        if(i == way) {
          r = rand() % setSize + ( i + way ) ;
        }
      }

      c[r].setBloco(m[block_cache].getBloco());
      c[r].setEndereco(m[block_cache].getEndereco());
      c[r].setConteudo(m[block_cache].getConteudo());
      cout << "MISS => bloco alocado na linha " << r << endl;
    }

  } else {
    cout << "HIT" << endl;
  }


}

void parcialmenteAssociativoFIFO(){

}

void parcialmenteAssociativoLRU(){

}

void parcialmenteAssociativoLFU(){

}
*/
