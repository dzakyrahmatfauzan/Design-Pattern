#ifndef GHOSTFACTORY_H
#define GHOSTFACTORY_H

#include "Ghost.h"
#include <string>

class GhostFactory {
public:
    static Ghost* createGhost(const std::string& type);
};

#endif // GHOSTFACTORY_H
