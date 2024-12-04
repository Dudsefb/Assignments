#ifndef MAPEAVEL_H
#define MAPEAVEL_H

#include <map>

using namespace std;

class Mapeavel{
	public:
		~Mapeavel() = default;
		virtual map<string,string> exportar() const = 0;
		virtual void importar(const map<string,string>& m) = 0;
};

#endif
