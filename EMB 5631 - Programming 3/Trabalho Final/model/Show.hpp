#ifndef SHOW_H
#define SHOW_H

#include <string>
#include <list>
#include <map>
#include <memory>
#include <ctime>
#include "Mapeavel.hpp"
#include "Banda.hpp"

using namespace std;

class Show : public Mapeavel{
	public:
		Show();
		~Show();
		string getNome();
		void setNome(const string& nome);
		struct tm getData();
		void setData(const struct tm& data);
		void addBanda(shared_ptr<Banda> banda);
		map<string,string> exportar() const override;
		void importar(const map<string,string>&) override;
	private:
		string nomeEvento;
		struct tm dataRealizacao;
		list<shared_ptr<Banda>> bandas;
};
#endif
