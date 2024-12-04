#ifndef MUSICA_H
#define MUSICA_H

#include <string>
#include <map>
#include "Mapeavel.hpp"

using namespace std;

class Musica : public Mapeavel{
	public:
		Musica();
		~Musica();
		string getNome();
		void setNome(const string& nome);
		unsigned short getDuracao();
		void setDuracao(const unsigned short& duracao);
		string getCompositor();
		void setCompositor(const string& compositor);
		map<string,string> exportar() const override;
		void importar(const map<string,string>&) override;
	private:
		string nome;
		unsigned short duracao;
		string compositor;
};
#endif
