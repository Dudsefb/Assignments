#include <string>
#include <list>
#include <map>
#include <memory>
#include <ctime>
#include "Mapeavel.hpp"
#include "Banda.hpp"
#include "Show.hpp"

using namespace std;

Show::Show(){
	this->nomeEvento = "NEW SHOW";
	this->dataRealizacao.tm_mday = 0;
	this->dataRealizacao.tm_mon = 0;
	this->dataRealizacao.tm_year = 0;
	this->bandas = {};
}

Show::~Show(){
	bandas.clear();
}

string Show::getNome(){
	return this->nomeEvento;
}

void Show::setNome(const string& nome){
	this->nomeEvento = nome;
}

struct tm Show::getData(){
	return this->dataRealizacao;
}

void Show::setData(const struct tm& data){
	this->dataRealizacao = data;
}

void Show::addBanda(shared_ptr<Banda> banda){
	this->bandas.push_back(banda);
}

map<string,string> Show::exportar() const{
	map<string,string> myMap;
	myMap["nome"] = this->nomeEvento;
	myMap["dia"] = to_string(this->dataRealizacao.tm_mday);
	switch(this->dataRealizacao.tm_mon){
		case 0:
			myMap["mes"] = "Janeiro";
			break;
		case 1:
			myMap["mes"] = "Fevereiro";
			break;
		case 2:
			myMap["mes"] = "Março";
			break;
		case 3:
			myMap["mes"] = "Abril";
			break;
		case 4:
			myMap["mes"] = "Maio";
			break;
		case 5:
			myMap["mes"] = "Junho";
			break;
		case 6:
			myMap["mes"] = "Julho";
			break;
		case 7:
			myMap["mes"] = "Agosto";
			break;
		case 8:
			myMap["mes"] = "Setembro";
			break;
		case 9:
			myMap["mes"] = "Outubro";
			break;
		case 10:
			myMap["mes"] = "Novembro";
			break;
		case 11:
			myMap["mes"] = "Dezembro";
			break;
		default:
			myMap["mes"] = "ERRO";
	}
	myMap["ano"] = to_string(this->dataRealizacao.tm_year+1900);
	string buffer = "";
	if(this->bandas.size()>0){
		for(list<shared_ptr<Banda>>::const_iterator it=this->bandas.begin(); it!=this->bandas.end();++it){
			buffer+=(*it)->getNome();
			buffer+=',';
		}
		buffer.pop_back();
	}else{
		buffer = "Nenhuma banda cadastrada!";
	}
	myMap["bandas"] = buffer;
	return myMap;
}

void Show::importar(const map<string,string>& m){
	throw("Show.importar: Função não implementada!\n");
}
