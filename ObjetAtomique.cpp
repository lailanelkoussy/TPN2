#include "ObjetAtomique.hpp"


ObjetAtomique::ObjetAtomique(const string &nom): ObjetAbst(nom){
}

void ObjetAtomique::setComment(const string &com){
    this->comment = com;
}
string ObjetAtomique::getName()const {
    return name;
}

ObjetAtomique::~ObjetAtomique() {
    reestablishRessource(name);
}

string ObjetAtomique::getComment() const {
    return comment;
}

ostream& operator<<(ostream& out, const ObjetAtomique& objetAtomique){
    out<<"name: "<<objetAtomique.name <<" comment: "<<objetAtomique.comment<<endl;
    return out;
}