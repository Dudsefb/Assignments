#ifndef VIEW_H
#define VIEW_H

#include <iostream>
#include <map>

class View{
	public:
		View();
		~View();
		unsigned short readOperation();
		std::string readString(const std::string& reason);
		unsigned short readUShort(const std::string& reason);
		void printIntegrantes(const std::map<std::string,std::string>& mBanda);
		void printMusicas(const std::map<std::string,std::string>& mBanda);
		void printListaBandas(const std::map<std::string,std::string>& mShow);
		void printShow(const std::map<std::string,std::string>& mShow);
};
#endif
