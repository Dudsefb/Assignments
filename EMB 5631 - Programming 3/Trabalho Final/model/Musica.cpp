#include <string>
#include <map>
#include "Mapeavel.hpp"
#include "Musica.hpp"

using namespace std;

Musica::Musica() : nome(""), duracao(0), compositor("") {};

Musica::~Musica(){};

string Musica::getNome(){
	return this->nome;
}

void Musica::setNome(const string& nome){
	this->nome = nome;
}

unsigned short Musica::getDuracao(){
	return this->duracao;
}

void Musica::setDuracao(const unsigned short& duracao){
	this->duracao = duracao;
}

string Musica::getCompositor(){
	return this->compositor;
}

void Musica::setCompositor(const string& compositor){
	this->compositor = compositor;
}

map<string,string> Musica::exportar() const{
	map<string,string> myMap;
	myMap["nome"] = this->nome;
	unsigned short fBuffer = this->duracao;
	string sBuffer = "";
	sBuffer+=to_string((int)(fBuffer/3600));
	fBuffer %= 3600;
	sBuffer+="h";
	sBuffer+=to_string((int)(fBuffer/60));
	fBuffer %= 60;
	sBuffer+="m";
	sBuffer+=to_string((int)fBuffer);
	sBuffer+="s";
	myMap["duracao"] = sBuffer;
	myMap["compositor"] = this->compositor;
	return myMap;
}

void Musica::importar(const map<string,string>& m){
	throw("Musica.importar: Função não implementada!\n");
}
