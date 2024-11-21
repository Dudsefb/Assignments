#ifndef INTEGRANTE_H
#define INTEGRANTE_H

#include <string>
#include <map>
#include "Mapeavel.hpp"

class Integrante : public Mapeavel{
	public:
		Integrante();
		~Integrante();
		std::string getNome();
		void setNome(const std::string& nome);
		std::string getInstrumento();
		void setInstrumento(const std::string& instrumento);
		unsigned short getIdade();
		void setIdade(const unsigned short& idade);
		std::map<std::string,std::string> exportar() const override;
		void importar(const std::map<std::string,std::string>&) override;
	private:
		std::string nome;
		std::string instrumento;
		unsigned short idade;
};
#endif
