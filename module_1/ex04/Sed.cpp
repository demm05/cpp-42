#include <iostream>
#include <string>
#include "Sed.hpp"

Sed::Sed(void) {
}

Sed::~Sed(void) {
    this->_fin.close();
    this->_fout.close();
    this->_buffer.clear();
}

bool Sed::open(std::string const &filename) {
    std::string outfile;
    if (filename.empty())
        return (0);
    this->_fin.open(filename.c_str());
    if (!this->_fin.good())
        return (0);
    outfile = filename + ".replace";
    this->_fout.open(outfile.c_str(), std::ios::out | std::ios::trunc);
    if (!this->_fout.good())
        return (0);
    return (1);
}

void Sed::replace(char const *targetString, char const *newString) {
    if (!targetString || !newString) {
        std::cerr << "please provide valid pointer to a variable" << std::endl;
        return;
    }
    if (!*targetString) {
        std::cerr << "Error: target string can't be empty" << std::endl;
        return;
    }
    this->_targetString = std::string(targetString);
    this->_newString = std::string(newString);
    while (std::getline(this->_fin, this->_buffer)) {
        this->replaceBuffer();
        this->_fout << this->_buffer << std::endl;
        this->_buffer.clear();
    }
}

void Sed::replaceBuffer(void) {
    size_t index;

    index = this->_buffer.find(this->_targetString);
    while (index != std::string::npos) {
        this->_buffer.erase(index, this->_targetString.length());
        this->_buffer.insert(index, this->_newString);
        index = this->_buffer.find(this->_targetString);
    }
}
