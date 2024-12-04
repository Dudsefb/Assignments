#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <vector>
#include <memory>
#include "../model/Show.hpp"
#include "../model/Banda.hpp"
#include "../model/Integrante.hpp"
#include "../model/Musica.hpp"
#include "../view/View.hpp"

using namespace std;

class Controller{
	public:
		Controller();
		~Controller();
		void executar();
	private:
		Show show;
		View view;
		vector<shared_ptr<Banda>> bandas;
		vector<shared_ptr<Integrante>> integrantes;
		vector<shared_ptr<Musica>> musicas;
		void editarShow();
		void criarIntegrante();
		void criarMusica();
		void criarBanda();
		void editarIntegrante(shared_ptr<Integrante> integrante);
		void editarMusica(shared_ptr<Musica> musica);
		void editarBanda(shared_ptr<Banda> banda);
		map<string,string> exportarIntegrantes();
		map<string,string> exportarMusicas();
		map<string,string> exportarBandas();
};
#endif
