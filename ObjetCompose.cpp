#include "ObjetCompose.hpp"

ObjetCompose::ObjetCompose(string name) : ObjetAbst(name) {

}

void ObjetCompose::incrementFrequencies(string name) {
    for (long unsigned int i = 0; i < frequencies.size(); i++) {
        if (frequencies[i].first == name) {
            unsigned int *elementCount = &frequencies[i].second;
            *elementCount += 1;
            cout<<frequencies[i].second;
            return;
        }
    }
    pair<string,int> pair(name, 1);
    frequencies.push_back(pair);

}

void ObjetCompose::operator[](ObjetAtomique *&objetAtomique) {
    ObjetAtomique *copyPointer = objetAtomique;
    composants.push_back(copyPointer);
    incrementFrequencies(objetAtomique->getName());
    objetAtomique = nullptr;
}

ObjetCompose::~ObjetCompose() {
    for (long unsigned int i = 0; i < composants.size(); i++) {
        delete composants[i];
    }
}

void ObjetCompose::setComment(const string &com) {
    this->comment = com;
}

string ObjetCompose::getName() const {
    return name;
}

ostream &operator<<(ostream &out, const ObjetCompose &objetCompose) {
    out << "Les composants de " << objetCompose.name << ":" << endl;
    for (long unsigned int i = 0; i < objetCompose.frequencies.size(); i++) {
        if(objetCompose.frequencies[i].second > 0){
            out<< objetCompose.frequencies[i].first<< ": "<<objetCompose.frequencies[i].second<<endl;
        }
    }
    return out;
}