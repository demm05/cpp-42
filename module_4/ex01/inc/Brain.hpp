#pragma once

#include <string>

#define IDEAS_COUNT 100

class Brain {
protected:
    std::string _ideas[IDEAS_COUNT];

public:
    Brain(void);
    Brain(Brain const &rhs);
    ~Brain(void);

    Brain const &operator=(Brain const &rhs);

    std::string const &getIdea(size_t index) const;
    void setIdea(size_t index, std::string idea);
};
