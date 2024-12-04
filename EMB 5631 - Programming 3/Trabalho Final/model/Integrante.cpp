#include <string>
#include <map>
#include "Mapeavel.hpp"
#include "Integrante.hpp"

using namespace std;

Integrante::Integrante() : nome(""), instrumento(""), idade(0) {};

Integrante::~Integrante(){};

string Integrante::getNome(){
	return this->nome;
}

void Integrante::setNome(const string& nome){
	this->nome = nome;
}

string Integrante::getInstrumento(){
	return this->instrumento;
}

void Integrante::setInstrumento(const string& instrumento){
	this->instrumento = instrumento;
}

unsigned short Integrante::getIdade(){
	return this->idade;
}

void Integrante::setIdade(const unsigned short& idade){
	this->idade = idade;
}

map<string,string> Integrante::exportar() const{
	map<string,string> myMap;
	myMap["nome"] = this->nome;
	myMap["instrumento"] = this->instrumento;
	myMap["idade"] = to_string(this->idade);
	return myMap;
}

void Integrante::importar(const map<string,string>& m){
	throw("Integrante.importar: Função não implementada!\n");
}
