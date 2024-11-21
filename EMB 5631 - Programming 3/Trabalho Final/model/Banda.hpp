#ifndef BANDA_H
#define BANDA_H

#include <string>
#include <list>
#include <map>
#include <memory>
#include "Mapeavel.hpp"
#include "Integrante.hpp"
#include "Musica.hpp"

class Banda : public Mapeavel{
	public:
		Banda();
		~Banda();
		std::string getNome();
		void setNome(const std::string& nome);
		std::string getGeneroMusical();
		void setGeneroMusical(const std::string& generoMusical);
		void addIntegrante(const Integrante& integrante);
		void addMusica(const Musica& musica);
		std::map<std::string,std::string> exportar() const override;
		void importar(const std::map<std::string,std::string>&) override;
	private:
		std::string nome;
		std::string generoMusical;
		std::list<std::shared_ptr<Integrante>> integrantes;
		std::list<std::shared_ptr<Musica>> musicas;
};
;
#endif
