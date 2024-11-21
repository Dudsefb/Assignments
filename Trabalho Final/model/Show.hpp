#ifndef SHOW_H
#define SHOW_H

#include <iostream>
#include <list>
#include "Banda.hpp"

class Show{
	public:
		Show();
		~Show();
		std::string getNome();
		void setNome(const std::string& nome);
		void addBanda(const Banda& banda);
		void exibirDetalhes();
	private:
		std::string nomeEvento;
		unsigned short dataRealizacao[3];
		std::list<std::shared_ptr<Banda>> bandas;	
};
#endif
