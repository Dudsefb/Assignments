#ifndef INTEGRANTE_H
#define INTEGRANTE_H

#include <string>
#include <map>
#include "Mapeavel.hpp"

using namespace std;

class Integrante : public Mapeavel{
	public:
		Integrante();
		~Integrante();
		string getNome();
		void setNome(const string& nome);
		string getInstrumento();
		void setInstrumento(const string& instrumento);
		unsigned short getIdade();
		void setIdade(const unsigned short& idade);
		map<string,string> exportar() const override;
		void importar(const map<string,string>&) override;
	private:
		string nome;
		string instrumento;
		unsigned short idade;
};
#endif
