#include <iostream>
#include <iomanip>
#include <map>
#include <string>
#include <list>
#include <vector>
#include <stdlib.h>
#include <ctime>
#include <limits>
#include "View.hpp"

using namespace std;

list<string> split(const string& s, const string& delimiter){
	size_t pos;
	string buffer = s;
	list<string> myList;
	while((pos = buffer.find(delimiter))!=string::npos){
		myList.push_back(buffer.substr(0,pos));
		buffer.erase(0,pos+delimiter.length());
	}
	if(buffer!="") myList.push_back(buffer);
	return myList;
}

void cleanBuffer(){
	cin.ignore(numeric_limits<streamsize>::max(),'\n');
	//cin.clear();
	cout << "~ ";
}

View::View() : header("") {};

View::~View(){};

void View::printHeader(){
	string buffer = "----------------------------------------";
	cout << buffer << '\n';
	int l = (40-this->header.length())/2;
	for(int i=0;i<l;i++){
		cout << ' ';
	}
	cout << this->header << '\n';
	cout << buffer << '\n';
}

void View::clear(){
	system("clear");
}

void View::setHeader(const string& header){
	this->header = header;
}

unsigned short View::readOperation(){
	cout << "~ ";
	unsigned short buffer;
	cin>>buffer;
	return buffer;
}

string View::readString(const string& reason){
	cout << "Insira " << reason << ": ";
	cleanBuffer();
	string buffer;
	getline(cin,buffer);
	return buffer;
}

unsigned short View::readUShort(const string& reason){
	cout << "Insira " << reason <<": ";
	cout << "~ ";
	unsigned short buffer;
	cin>>buffer;
	return buffer;
}

struct tm View::readData(){
	cout << "Insira uma data no formato dd/mm/aaaa: ";
	cleanBuffer();
	string buffer;
	getline(cin,buffer);
	vector<int> numbers;
	struct tm ans;
	for(string s:split(buffer,"/")){
		numbers.push_back(stoi(s));
	}
	ans.tm_mday = numbers[0];
	ans.tm_mon = numbers[1]-1;
	ans.tm_year = numbers[2]-1900;
	return ans;
}

void View::printBanda(const map<string,string>& mBanda){
	this->clear();
	vector<list<string>> buffer;
	this->setHeader(mBanda.at("nome"));
	this->printHeader();
	cout << "Gênero: " << mBanda.at("genero") << '\n';
	if(mBanda.at("integrantes")==""){
		cout << "***Nenhum integrante cadastrado***\n";
	}else{
		cout << setw(20) << left << "Nome";
		cout << setw(20) << left << "Instrumento";
		cout << setw(20) << left << "Idade";
		cout << '\n';
		buffer = {split(mBanda.at("integrantes"),","),split(mBanda.at("instrumentos"),","),split(mBanda.at("idades"),",")};
		while(!buffer[0].empty()){	
			for(int i=0;i<3;i++){
				cout << setw(20) << left << buffer[i].front();
				buffer[i].pop_front();
			}
			cout << '\n';
		}
		cout << setw(20) << left << "Nome";
		cout << setw(20) << left << "Duração";
		cout << setw(20) << left << "Compositor";
		cout << '\n';
		buffer = {split(mBanda.at("musicas"),","),split(mBanda.at("duracoes"),","),split(mBanda.at("compositores"),",")};
		while(!buffer[0].empty()){
			for(int i=0;i<3;i++){
				cout << setw(20) << left << buffer[i].front();
				buffer[i].pop_front();
			}
			cout << '\n';
		}
	}
}

void View::printListaIntegrantes(const map<string,string>& mIntegrantes){
	int c = 0;
	this->clear();
	cout << "=== Lista de Integrantes ===\n";
	vector<list<string>> buffer = {split(mIntegrantes.at("nome"),","),split(mIntegrantes.at("instrumento"),","),split(mIntegrantes.at("idade"),",")};
	cout << "    ";
	cout << setw(20) << left << "Nome";
	cout << setw(20) << left << "Instrumento";
	cout << setw(20) << left << "Idade";
	cout << '\n';
	while(!buffer[0].empty()){
		cout << "[" << to_string(++c) << "] ";
		for(int i=0;i<3;i++){
			cout << setw(20) << left << buffer[i].front();
			buffer[i].pop_front();
		}
		cout << '\n';
	}
}

void View::printListaMusicas(const map<string,string>& mMusicas){
	int c = 0;
	this->clear();
	cout << "=== Lista de Musicas ===\n";
	vector<list<string>> buffer = {split(mMusicas.at("nome"),","),split(mMusicas.at("duracao"),","),split(mMusicas.at("compositor"),",")};
	cout << "    ";
	cout << setw(20) << left << "Nome";
	cout << setw(20) << left << "Duracao";
	cout << setw(20) << left << "Compositor";
	cout << '\n';
	while(!buffer[0].empty()){
		cout << "[" << to_string(++c) << "] ";
		for(int i=0;i<3;i++){
			cout << setw(20) << left << buffer[i].front();
			buffer[i].pop_front();
		}
		cout << '\n';
	}
}

void View::printListaBandas(const map<string,string>& mBandas){
	int c = 0;
	this->clear();
	cout << "=== Lista de Bandas ===\n";
	vector<list<string>> buffer = {split(mBandas.at("nome"),","),split(mBandas.at("genero"),",")};
	cout << "    ";
	cout << setw(20) << left << "Nome";
	cout << setw(20) << left << "Gênero";
	cout << '\n';
	while(!buffer[0].empty()){
		cout << "[" << to_string(++c) << "] ";
		for(int i=0;i<2;i++){
			cout << setw(20) << left << buffer[i].front();
			buffer[i].pop_front();
		}
		cout << '\n';
	}
}

void View::printShow(const map<string,string>& mShow){
	this->clear();
	this->setHeader(mShow.at("nome"));
	this->printHeader();
	cout << setw(20) << left << "Data: ";
	cout << setw(20) << left << mShow.at("dia")+"/"+mShow.at("mes")+"/"+mShow.at("ano");
	cout << '\n';
	cout << "=== Bandas Cadastradas ===\n";
	list<string> buffer = split(mShow.at("bandas"),",");
	while(!buffer.empty()){
		cout << setw(20) << left << buffer.front();
		buffer.pop_front();
		cout << "\n";
	}
}

void View::printMenuGeral(){
	this->clear();
	this->printHeader();
	cout << "[1] Editar show\n";
	cout << "[2] Imprimir show\n";
	cout << "[3] Cadastrar integrante\n";
	cout << "[4] Cadastrar musica\n";
	cout << "[5] Cadastrar banda\n";
	cout << "[6] Listar integrantes\n";
	cout << "[7] Listar musicas\n";
	cout << "[8] Listar bandas\n";
	cout << "[9] Sair\n";
}

void View::printMenuShow(){
	this->clear();
	this->printHeader();
	cout << "[1] Adicionar banda existente\n";
	cout << "[2] Adicionar nova banda\n";
	cout << "[3] Alterar nome\n";
	cout << "[4] Alterar data de realização\n";
	cout << "[5] Voltar\n";
}

void View::printMenuSelecao(){
	cout << "Insira 0 para cancelar\n";
}

void View::printMenuBanda(){
	this->clear();
	this->printHeader();
	cout << "[1] Adicionar integrante existente\n";
	cout << "[2] Adicionar novo integrante\n";
	cout << "[3] Adicionar música existente\n";
	cout << "[4] Adicionar nova música\n";
	cout << "[5] Alterar nome\n";
	cout << "[6] Alternar gênero musical\n";
	cout << "[7] Voltar\n";
}

void View::printMenuIntegrante(){
	this->clear();
	this->printHeader();
	cout << "[1] Editar nome\n";
	cout << "[2] Editar instrumento\n";
	cout << "[3] Editar idade\n";
	cout << "[4] Voltar\n";
}

void View::printMenuMusica(){
	this->clear();
	this->printHeader();
	cout << "[1] Editar nome\n";
	cout << "[2] Editar duração\n";
	cout << "[3] Editar compositor\n";
	cout << "[4] Voltar\n";
}
