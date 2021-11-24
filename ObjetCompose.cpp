#include "ObjetCompose.hpp"

ObjetCompose::ObjetCompose(string name): ObjetAbst(name) {

}

void ObjetCompose::operator[](ObjetAtomique*& objetAtomique) {
    ObjetAtomique* copyPointer = objetAtomique;
    composants.push_back(copyPointer);
    objetAtomique = nullptr;
}

ObjetCompose::~ObjetCompose() {
    for(long unsigned int i = 0; i<composants.size(); i++){
        delete composants[i];
    }
}

void ObjetCompose::setComment(const string &com){
    this->comment = com;
}
string ObjetCompose::getName() const{
    return name;
}
