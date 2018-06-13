#ifndef _MP_H_
#define _MP_H_

#include <iostream>
using std::ostream;
using std::istream;
using std::cout;
using std::endl;
#include <vector>
using std::vector;

class Mp {
	protected:
		int bloco;
		vector<int> endereco;
		vector<int> conteudo;

	public:
		Mp();
		~Mp();

		int getBloco();
		vector<int> getEndereco();
		vector<int> getConteudo();

		void setBloco(int bloco);
		void setEndereco(vector<int> endereco);
		void setConteudo(vector<int> conteudo);

		void inserirConteudo(int conteudo);
		void inserirEndereco(int endereco);

		friend ostream& operator<<(ostream &os, Mp &memoria_principal);

		friend istream& operator>>(istream &is, Mp &memoria_principal);
};

#endif//_MP_H_
