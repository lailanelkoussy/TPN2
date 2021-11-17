#ifndef OBJETABST_HPP
#define OBJETABST_HPP

#include <iostream>
#include "ObjetAtomique.hpp"
#include <vector>
#include <utility>
using namespace std;

class ObjetAbst{
private:
    static vector<pair<ObjetAtomique*,int>> objetsDisponible; // TODO: need to make sure this thing isn't editable
    string const name; // inchangeable dès l'intialization
    string comment; //TODO: peut changer, donc implementer fonction pour changer le commentaire


public:
    string getName();
    void setComment(const string&);
    static vector<string> getAllNames();
    static void testObjetAbst();
    static ObjetAtomique *forge(string name);
    static ObjetAtomique *forge(ObjetAtomique * objetAtomPoint);
    static ObjetAtomique *forge(ObjetAtomique objetAtom);

};

#endif /* OBJETABST_HPP */

