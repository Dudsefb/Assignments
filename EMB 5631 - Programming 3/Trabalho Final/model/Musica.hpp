#ifndef MUSICA_H
#define MUSICA_H

#include <string>
#include <map>
#include "Mapeavel.hpp"

class Musica : public Mapeavel{
	public:
		Musica();
		~Musica();
		std::string getNome();
		void setNome(const std::string& nome);
		unsigned short getDuracao();
		void setDuracao(const unsigned short& duracao);
		std::string getCompositor();
		void setCompositor(const std::string& compositor);
		std::map<std::string,std::string> exportar() const override;
		void importar(const std::map<std::string,std::string>&) override;
	private:
		std::string nome;
		unsigned short duracao;
		std::string compositor;
};
#endif
