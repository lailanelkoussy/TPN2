#include "ObjetAtomique.hpp"


ObjetAtomique::ObjetAtomique(const string &nom): ObjetAbst(nom){
}

void ObjetAtomique::setComment(const string &com){
    this->comment = com;
}
string ObjetAtomique::getName() {
    return name;
}

ObjetAtomique::~ObjetAtomique() {
    reestablishRessource(name);
}
