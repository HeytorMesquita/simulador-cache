#ifndef _CACHE_H_
#define _CACHE_H_

#include "mp.h"

class Cache : public Mp {
	private:
		int linha;		/**< Linha da cache */

	public:
		Cache();
		~Cache();
		int getLinha();
		void setLinha(int linha);

		friend ostream& operator<<(ostream &os, Cache &c);
		friend istream& operator>>(istream &is, Cache &c);
};

#endif//_CACHE_H_
