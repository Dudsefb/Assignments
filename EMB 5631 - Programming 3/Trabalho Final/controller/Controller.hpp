#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "../model/Show.hpp"
#include "../view/View.hpp"

class Controller{
	public:
		Controller();
		~Controller();
		void executar();
	private:
		Show show;
		View view;
		unsigned short op;
};
#endif
