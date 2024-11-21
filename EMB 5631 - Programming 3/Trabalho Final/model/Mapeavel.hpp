#ifndef MAPEAVEL_H
#define MAPEAVEL_H

#include <map>

class Mapeavel{
	public:
		~Mapeavel() = default;
		virtual std::map<std::string,std::string> exportar() const = 0;
		virtual void importar(const std::map<std::string,std::string>& m) = 0;
};

#endif
