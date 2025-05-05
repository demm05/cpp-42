#include <fstream>

class Sed {
public:
    Sed(void);
    ~Sed(void);

private:
    std::fstream _fin;
    std::fstream _fout;
    std::string  _name;

    bool static checkFileRight(std::string filename);
};
