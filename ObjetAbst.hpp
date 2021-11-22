#ifndef OBJETABST_HPP
#define OBJETABST_HPP

#include <iostream>
#include <vector>
#include <utility>
using namespace std;

class ObjetAtomique;

class ObjetAbst {
private:
    //TODO: need to make objet atomique unchangeable, but int okay
    static vector<pair<ObjetAtomique*,int>> objetsDisponible; // TODO: need to make sure this thing isn't editable
    static const vector<pair<ObjetAtomique*,int>> inventaire;
protected:
    const string name;
    string comment ="";
    explicit ObjetAbst(const string&);
    static void reestablishRessource(string);

public:
    virtual string getName()= 0;
    virtual void setComment(const string&)=0;
    static vector<string> getAllNames();
    static void testObjetAbst();
    static ObjetAtomique *forge(const string &name) ;
    static ObjetAtomique *forge(ObjetAtomique * objetAtomPoint) ;
    static ObjetAtomique *forge(ObjetAtomique& objetAtom);

};

#endif /* OBJETABST_HPP */

