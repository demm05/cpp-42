#include <fstream>

class Sed {
public:
    Sed(void);
    ~Sed(void);
    bool open(std::string const &filename);
    void replace(char const *targetString, char const *newString);

private:
    std::ifstream _fin;
    std::ofstream _fout;
    std::string   _targetString;
    std::string   _newString;
    std::string   _buffer;

    void replaceWithNewLine(void);
    void replaceBasic(void);
    void replaceBuffer(void);
};
