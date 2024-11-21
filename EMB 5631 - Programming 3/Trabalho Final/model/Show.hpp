#ifndef SHOW_H
#define SHOW_H

#include <string>
#include <list>
#include <map>
#include <memory>
#include <ctime>
#include "Mapeavel.hpp"
#include "Banda.hpp"

class Show : public Mapeavel{
	public:
		Show();
		~Show();
		std::string getNome();
		void setNome(const std::string& nome);
		struct tm getData();
		void setData(const struct tm& data);
		void addBanda(const Banda& banda);
		std::map<std::string,std::string> exportar() const override;
		void importar(const std::map<std::string,std::string>&) override;
	private:
		std::string nomeEvento;
		struct tm dataRealizacao;
		std::list<std::shared_ptr<Banda>> bandas;
};
#endif
