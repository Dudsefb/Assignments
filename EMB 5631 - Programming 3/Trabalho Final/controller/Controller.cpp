#include <vector>
#include <memory>
#include "../model/Show.hpp"
#include "../model/Banda.hpp"
#include "../model/Integrante.hpp"
#include "../model/Musica.hpp"
#include "../view/View.hpp"
#include "Controller.hpp"

using namespace std;

Controller::Controller(){
	this->integrantes = {};
	this->musicas = {};
	this->bandas = {};
}

Controller::~Controller(){
	bandas.clear();
	integrantes.clear();
	musicas.clear();
}

void Controller::executar(){
	unsigned short op = 0;
	bool end = false;
	while(!end){
		this->view.setHeader(this->show.getNome());
		this->view.printMenuGeral();
		op = this->view.readOperation();
		switch(op){
			case 1:
				this->editarShow();
				break;
			case 2:
				this->view.printShow(this->show.exportar());
				this->view.printMenuSelecao();
				this->view.readOperation();
				break;
			case 3:
				this->criarIntegrante();
				break;
			case 4: 
				this->criarMusica();
				break;
			case 5:
				this->criarBanda();
				break;
			case 6:
				this->view.printListaIntegrantes(this->exportarIntegrantes());
				this->view.printMenuSelecao();
				this->view.readOperation();
				break;
			case 7:
				this->view.printListaMusicas(this->exportarMusicas());
				this->view.printMenuSelecao();
				this->view.readOperation();
				break;
			case 8:
				this->view.printListaBandas(this->exportarBandas());
				this->view.printMenuSelecao();
				this->view.readOperation();
				break;
			case 9:
				end = true;
				break;
			default:
				break;
		}
	}
}

void Controller::editarShow(){
	unsigned short op = 0;
	bool end = false;
	while(!end){
		this->view.setHeader(this->show.getNome());
		this->view.printMenuShow();
		op = this->view.readOperation();
		switch(op){
			case 1:
				this->view.printListaBandas(this->exportarBandas());
				this->view.printMenuSelecao();
				op = this->view.readUShort("o número da banda desejada");
				if(op!=0&&op<=this->bandas.size()) this->show.addBanda(this->bandas[op-1]);
				break;
			case 2:
				this->criarBanda();
				this->show.addBanda(this->bandas.back());
				break;
			case 3:
				this->show.setNome(this->view.readString("o nome do show"));
				break;
			case 4:
				this->show.setData(this->view.readData());
				break;
			case 5:
				end = true;
				break;
			default:
				break;
		}
	}
}

void Controller::criarIntegrante(){
	Integrante i = Integrante();
	this->view.clear();
	i.setNome(this->view.readString("o nome do integrante"));
	i.setInstrumento(this->view.readString("o instrumento do integrante"));
	i.setIdade(this->view.readUShort("a idade do integrante"));
	this->integrantes.push_back(make_shared<Integrante>(i));
}

void Controller::criarMusica(){
	Musica m = Musica();
	this->view.clear();
	m.setNome(this->view.readString("o nome da música"));
	m.setDuracao(this->view.readUShort("a duração da música, em segundos"));
	m.setCompositor(this->view.readString("o nome do compositor"));
	this->musicas.push_back(make_shared<Musica>(m));
}

void Controller::criarBanda(){
	Banda b = Banda();
	this->view.clear();
	b.setNome(this->view.readString("o nome da banda"));
	b.setGeneroMusical(this->view.readString("o gênero da banda"));
	this->bandas.push_back(make_shared<Banda>(b));
	this->editarBanda(bandas.back());
}

void Controller::editarIntegrante(shared_ptr<Integrante> integrante){
	unsigned short op = 0;
	bool end = false;
	this->view.clear();
	this->view.setHeader(integrante->getNome());
	while(!end){
		this->view.printMenuIntegrante();
		op = this->view.readOperation();
		switch(op){
			case 1:
				integrante->setNome(this->view.readString("o novo nome do integrante"));
				break;
			case 2:
				integrante->setInstrumento(this->view.readString("o novo instrumento do integrante"));
				break;
			case 3:
				integrante->setIdade(this->view.readUShort("a nova idade do integrante"));
				break;
			case 4:
				end = true;
				break;
			default:
				break;
		}
	}
}

void Controller::editarMusica(shared_ptr<Musica> musica){
	unsigned short op = 0;
	bool end = false;
	while(!end){
		this->view.setHeader(musica->getNome());
		this->view.printMenuMusica();
		op = this->view.readOperation();
		switch(op){
			case 1:
				musica->setNome(this->view.readString("o novo nome da música"));
				break;
			case 2:
				musica->setDuracao(this->view.readUShort("a nova duração da música, em segundos"));
				break;
			case 3:
				musica->setCompositor(this->view.readString("o novo compositor da música"));
				break;
			case 4:
				end = true;
				break;
			default:
				break;
		}
	}
}

void Controller::editarBanda(shared_ptr<Banda> banda){
	unsigned short op = 0;
	bool end = false;
	while(!end){
		this->view.setHeader(banda->getNome());
		this->view.printMenuBanda();
		op = this->view.readOperation();
		switch(op){
			case 1:
				do{
					this->view.printListaIntegrantes(this->exportarIntegrantes());
					this->view.printMenuSelecao();
					op = this->view.readOperation();
				}while(op>this->integrantes.size());
				if(op!=0) banda->addIntegrante(this->integrantes[op-1]);
				break;
			case 2:
				this->criarIntegrante();
				banda->addIntegrante(this->integrantes.back());
				break;
			case 3:
				do{
					this->view.printListaMusicas(this->exportarMusicas());
					this->view.printMenuSelecao();
					op = this->view.readOperation();
				}while(op>this->musicas.size());
				if(op!=0) banda->addMusica(this->musicas[op-1]);
				break;
			case 4:
				this->criarMusica();
				banda->addMusica(this->musicas.back());
				break;
			case 5:
				banda->setNome(this->view.readString("o nome da banda"));
				break;
			case 6: 
				banda->setGeneroMusical(this->view.readString("o novo gênero musical da banda"));
				break;
			case 7:
				end = true;
				break;
			default:
				break;
		}
	}
}

map<string,string> Controller::exportarIntegrantes(){
	map<string,string> myMap;
	string bufferA = "", bufferB = "", bufferC = "";
	for(shared_ptr<Integrante> i:this->integrantes){
		bufferA += i->getNome();
		bufferA += ',';
		bufferB += i->getInstrumento();
		bufferB += ',';
		bufferC += to_string(i->getIdade());
		bufferC += ',';
	}
	myMap["nome"] = bufferA;
	myMap["instrumento"] = bufferB;
	myMap["idade"] = bufferC;
	return myMap;
}

map<string,string> Controller::exportarMusicas(){
	map<string,string> myMap;
	string bufferA = "", bufferB = "", bufferC = "";
	unsigned short bufferD;
	for(shared_ptr<Musica> m:this->musicas){
		bufferA += m->getNome();
		bufferA += ',';
		bufferD = m->getDuracao();
		bufferB += to_string(bufferD/3600);
		bufferB += "h";
		bufferD %= 3600;
		bufferB += to_string(bufferD/60);
		bufferB += "m";
		bufferD %= 60;
		bufferB += to_string(bufferD);
		bufferB += "s,";
		bufferC += m->getCompositor();
		bufferC += ',';
	}
	myMap["nome"] = bufferA;
	myMap["duracao"] = bufferB;
	myMap["compositor"] = bufferC;
	return myMap;
}

map<string,string> Controller::exportarBandas(){
	map<string,string> myMap;
	string bufferA = "", bufferB = "";
	for(shared_ptr<Banda> b:this->bandas){
		bufferA += b->getNome();
		bufferA += ',';
		bufferB += b->getGeneroMusical();
		bufferB += ',';
	}
	myMap["nome"] = bufferA;
	myMap["genero"] = bufferB;
	return myMap;
}
