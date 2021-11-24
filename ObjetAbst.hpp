#ifndef OBJETABST_HPP
#define OBJETABST_HPP

#include <iostream>
#include <vector>
#include <utility>
using namespace std;

class ObjetAtomique;

class ObjetAbst {
private:

    static vector<pair<ObjetAtomique*,int>> objetsDisponible;
protected:
    const string name;
    string comment ="";
    explicit ObjetAbst(const string&);
    static void reestablishRessource(string);

public:
    virtual string getName() const = 0;
    virtual void setComment(const string&)=0;
    static vector<string> getAllNames();
    static void testObjetAbst();
    static ObjetAtomique *forge(const string &name) ;
    static ObjetAtomique *forge(const ObjetAtomique * objetAtomPoint) ;
    static ObjetAtomique *forge(const ObjetAtomique& objetAtom);

};

#endif /* OBJETABST_HPP */

