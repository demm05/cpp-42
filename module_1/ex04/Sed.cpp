#include "Sed.hpp"

Sed::Sed(void) {
}

Sed::~Sed(void) {
    this->_fin.close();
    this->_fout.close();
}
