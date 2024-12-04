#ifndef VIEW_H
#define VIEW_H

#include <iostream>
#include <iomanip>
#include <map>
#include <string>
#include <list>
#include <vector>
#include <stdlib.h>
#include <ctime>

using namespace std;

list<string> split(const string& s, const string& delimiter);
void cleanBuffer();

class View{
	public:
		View();
		~View();
		void clear();
		void setHeader(const string& header);
		unsigned short readOperation();
		string readString(const string& reason);
		unsigned short readUShort(const string& reason);
		struct tm readData();
		void printBanda(const map<string,string>& mBanda);
		void printListaIntegrantes(const map<string,string>& mIntegrantes);
		void printListaMusicas(const map<string,string>& mMusicas);
		void printListaBandas(const map<string,string>& mBandas);
		void printShow(const map<string,string>& mShow);
		void printMenuGeral();
		void printMenuShow();
		void printMenuSelecao();
		void printMenuBanda();
		void printMenuIntegrante();
		void printMenuMusica();
	private:
		string header;
		void printHeader();
};
#endif
