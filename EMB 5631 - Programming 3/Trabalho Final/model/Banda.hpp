#ifndef BANDA_H
#define BANDA_H

#include <string>
#include <list>
#include <map>
#include <memory>
#include "Mapeavel.hpp"
#include "Integrante.hpp"
#include "Musica.hpp"

using namespace std;

class Banda : public Mapeavel{
	public:
		Banda();
		~Banda();
		string getNome();
		void setNome(const string& nome);
		string getGeneroMusical();
		void setGeneroMusical(const string& generoMusical);
		void addIntegrante(shared_ptr<Integrante> integrante);
		void addMusica(shared_ptr<Musica> musica);
		map<string,string> exportar() const override;
		void importar(const map<string,string>&) override;
	private:
		string nome;
		string generoMusical;
		list<shared_ptr<Integrante>> integrantes;
		list<shared_ptr<Musica>> musicas;
};
;
#endif
