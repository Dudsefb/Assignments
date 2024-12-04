#include <string>
#include <list>
#include <map>
#include <memory>
#include "Mapeavel.hpp"
#include "Integrante.hpp"
#include "Musica.hpp"
#include "Banda.hpp"

using namespace std;

Banda::Banda() : nome(""), generoMusical(""), integrantes({}), musicas({}) {};

Banda::~Banda(){
	integrantes.clear();
	musicas.clear();
}

string Banda::getNome(){
	return this->nome;
}

void Banda::setNome(const string& nome){
	this->nome = nome;
}

string Banda::getGeneroMusical(){
	return this->generoMusical;
}

void Banda::setGeneroMusical(const string& generoMusical){
	this->generoMusical = generoMusical;
}

void Banda::addIntegrante(shared_ptr<Integrante> integrante){
	this->integrantes.push_back(integrante);
}

void Banda::addMusica(shared_ptr<Musica> musica){
	this->musicas.push_back(musica);
}

map<string,string> Banda::exportar() const{
	map<string,string> myMap;
	myMap["nome"] = this->nome;
	myMap["genero"] = this->generoMusical;
	string bufferA = "",bufferB = "", bufferC = "";
	for(list<shared_ptr<Integrante>>::const_iterator it=this->integrantes.begin();it!=this->integrantes.end();++it){
		bufferA+=(*it)->getNome();
		bufferA+=',';
		bufferB+=(*it)->getInstrumento();
		bufferB+=',';
		bufferC+=to_string((*it)->getIdade());
		bufferC+=',';
	}
	bufferA.pop_back();
	bufferB.pop_back();
	bufferC.pop_back();
	myMap["integrantes"] = bufferA;
	myMap["instrumentos"] = bufferB;
	myMap["idades"] = bufferC;
	bufferA = "";
	bufferB = "";
	bufferC = "";
	for(list<shared_ptr<Musica>>::const_iterator it=this->musicas.begin();it!=this->musicas.end();++it){
		bufferA+=(*it)->getNome();
		bufferA+=',';
		bufferB+=to_string((*it)->getDuracao());
		bufferB+=',';
		bufferC+=(*it)->getCompositor();
		bufferC+=',';
	}
	bufferA.pop_back();
	bufferB.pop_back();
	bufferC.pop_back();
	myMap["musicas"] = bufferA;
	myMap["duracoes"] = bufferB;
	myMap["compositores"] = bufferC;
	return myMap;
}

void Banda::importar(const map<string,string>& m){
	throw("Banda.importar: Função importar não implementada!\n");
}
