

#include "ObjetAbst.hpp"
#include "ObjetAtomique.hpp"

using namespace std;

// Construisez ici l'inventaire global des pièces disponibles,
// avec un vecteur contenant les 4 objets Atomiques, A,B,C,D ayant respectivement des frequences 2,25,50,100
vector<pair<ObjetAtomique *, int>> initializeVector() {
    int frequencies[4] = {2, 25, 50, 100};
    string names[4] = {"A", "B", "C", "D"};
    vector<pair<ObjetAtomique *, int>> myVector;

    for (int i = 0; i < 4; i++) {
        ObjetAtomique *atom = new ObjetAtomique(names[i]);
        pair<ObjetAtomique *, int> pair(atom, frequencies[i]);
        myVector.push_back(pair);
    }
    return myVector;
}

vector<pair<ObjetAtomique *, int>> ObjetAbst::objetsDisponible{initializeVector()};


void ObjetAbst::testObjetAbst() {
    // ------------ Test 2 ---------
    // montrez ici qu'on ne peut plus ajouter d'objetAtomique à l'inventaire initial 
    // c.a d. essayez d'en ajoutez dans une ligne que vous laisserez en commentaire
    //

//    pair<ObjetAtomique*, int> p(new ObjetAtomique("E"), 200);
//    objetsDisponible.push_back(p);

    // Expliquez en qqs phrases, et mettez en évidence en MAJUSCULE ce qui dans le type a empéché l'action de se faire
    //
    ////  REPONSE CI DESSOUS
//// Nous ne pouvons pas rajouter d'objetAtomique à l'inventaire initial parce que le CONSTRUCTEUR d'ObjetAtomique est
//// en PRIVÉ, et est donc uniquement accessible par des fonctions ou des classes marqués 'friend' d'ObjetAtomique
//// donc dans ce cas, la class ObjetAbst n'est pas friend d'ObjetAtomique, la fonction testObjetAbst ne l'est pas également


    // ------------ Test 3 ---------
    // montrez ici comment réduire le stock d'une unité pour toutes les pièces disponibles
    vector<string> names = getAllNames();
    vector<ObjetAtomique *> objetsAtom;
    for (string element: names) {
        ////ici nous créeons un élement de chaque pièce disponible, si jamais une des classes d'elements atomiques n'a plus
        ////d'unité disponible, forge renvoie un nullptr
        ObjetAtomique *nouvelObjet = forge(element);
        if (nouvelObjet != nullptr)
            objetsAtom.push_back(nouvelObjet);
    }

    // récupérez ensuite séparément le vecteur des fréquences 
    vector<int> v_freq;
    // a completer
    ////completion ci-dessous
    for (auto pair: objetsDisponible) {
        v_freq.push_back(pair.second);
    }

    if (v_freq == vector<int>{1, 24, 49, 99}) cout << "- ok decroissance frequence" << endl;
    else cout << "PB DECROISSANCE FREQUENCE" << endl;
    // puis remettez ici les fréquences en l'état
    ////Pour remettre les fréquences en l'état, nous nous contentons de supprimer les elements de notre vecteur
    for (long unsigned int i = 0; i < objetsAtom.size(); i++) {
        delete objetsAtom[i];
    }

    ////le code ci-dessous permet de bien montrer que les fréquences sont rétablie
////    for(auto element: objetsDisponible){
////        cout<<element.first->getName()<<" "<<element.second<<endl;
////    }

    // ------------ Test 4 -----------
    // vous allez tenter ici de modifier tous les noms et commentaires en leur ajoutant "_mod"
    // ca doit être impossible pour les noms, mais possible pour les commentaires
    // n'affichez rien, et laissez en commentaire la ligne qui échoue
    // nous la testerons en la décommantant
    // code :
    //
    for (long unsigned int i = 0; i < objetsDisponible.size(); i++) {
////        objetsDisponible[i].first->name = objetsDisponible[i].first->name + "_mod";
        objetsDisponible[i].first->comment =  objetsDisponible[i].first->comment + "_mod";
    }

    // Expliquez ici en formant une phrase compréhensible, ce qui dans les types 
    // permet de répondre précisément à la spécification précédente
    // (utilisez des majuscules pour faire ressortir les mots clés significatifs)
    ////REPONSE: les noms sont inchangeable à cause du mot clé CONST ajouté à la définition de leur variable NAME,
    //// alors que la variable comment n'est pas marquée comme étant constante.
    ////De plus, ces variables sont accessibles par notre fonction qui est définie dans ObjetAbst, car les variables sont
    //// déclarés dans ObjetAbst, et que ObjetAtomique hérite de ObjetAbst
}

ObjetAbst::ObjetAbst(const string &nom) : name(nom) {}

vector<string> ObjetAbst::getAllNames() {
    vector<string> names;
    for (auto element: objetsDisponible) {
        names.push_back(element.first->name);
    }
    return names;
}

ObjetAtomique *ObjetAbst::forge(const string &name) {
    for (long unsigned int i = 0; i < objetsDisponible.size(); i++) {
        string currentName = objetsDisponible[i].first->getName();
        if (currentName == name) {
            if (objetsDisponible[i].second > 0) {
                int *elementCount = &objetsDisponible[i].second;
                (*elementCount) -= 1;
                return new ObjetAtomique{currentName};;
            } else
                return nullptr;
        }
    }
    return nullptr;
}

ObjetAtomique *ObjetAbst::forge(const ObjetAtomique &objetAtom) {
    //Test 6
    //objetAtom.setComment("bonjour");
    ObjetAtomique * newObjPoint = forge(objetAtom.getName());
    if(newObjPoint!= nullptr)
        newObjPoint->setComment(objetAtom.getComment());
    return newObjPoint;
}

ObjetAtomique *ObjetAbst::forge(const ObjetAtomique *objetAtomPoint) {
    //Test 6
    //objetAtomPoint->setComment("bonjour");
    return forge(*objetAtomPoint);
}

void ObjetAbst::reestablishRessource(string nom) {

    for (long unsigned int i = 0; i < objetsDisponible.size(); i++) {
        string elementName = objetsDisponible[i].first->getName();
        if (elementName == nom) {
            int *elementCount = &objetsDisponible[i].second;
            *elementCount += 1;
            return;
        }
    }
}

