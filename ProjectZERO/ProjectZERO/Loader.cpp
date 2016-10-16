
#include "Loader.h"

Loader::Loader() {

}

Loader Loader::getInstance() {
	if (!instance) {
		instance = new Loader;
	}
	return *instance;
}