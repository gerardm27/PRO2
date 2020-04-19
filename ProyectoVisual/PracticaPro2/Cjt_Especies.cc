#include "Cjt_Especies.hh"

Cjt_Especies::Cjt_Especies() {
}

Cjt_Especies::~Cjt_Especies() {

}

void Cjt_Especies::Esta_al_conjunt(bool& found, const string& id) {
	//Si l'element que troba no esta a la ultima+1 posicio, vol dir que existeix.
	if (map_especies.find(id) != map_especies.end()) found = true;
	//Si esta a la ultima+1 (end), no existeix.
	else found = false;
}
void Cjt_Especies::Crea_especie(const string& id, const string& gen) {
	bool found = false;
	Esta_al_conjunt(found, id);
	//Si ja existeix, salta exception
	if (found) {
		throw "what(): Ja existeix?";
	}
	//Sino l'afegeix
	else {
		map_especies.insert(make_pair(id, Especie(gen)));
		cout << "S'ha afegit l'especie amb identificador " << id << " i gen " << gen << " al conjunt" << endl;
		//Actualitza_taula_distancies();
	}
}

void Cjt_Especies::Obtenir_gen(const string& id) {
	bool found = false;
	Esta_al_conjunt(found, id);

	//Si ha acabat i no l'ha trobat, no existeix
	if (not found) {
		throw "what(): No existeix?";
	}
	else {
		cout << "El gen associat a l'identificador " << id << " es: " << map_especies[id].Obtenir_gen() << endl;
	}
}

double Cjt_Especies::Calcula_distancia(const string& id1, const string& id2) {
	bool found = false;
	Esta_al_conjunt(found, id1);
	//Si no existeix un dels dos, salta exception
	if (not found) {
		throw "what(): No existeix?";
	}
	else {
		found = false;
		Esta_al_conjunt(found, id2);
		if (not found) {
			throw "what(): No existeix?";
		}
		//Calcular la distancia entre id1, id2
		else {
			return map_especies[id1].Calcula_distancia(map_especies[id2]);
		}
	}
}

void Cjt_Especies::Elimina_especie(const string& id) {
	bool found = false;
	Esta_al_conjunt(found, id);

	//Si no existeix, salta exception
	if (not found) {
		throw "what(): No existeix?";
	}
	else {
		map_especies.erase(id);
		cout << "S'ha eliminat l'especie amb identificador " << id << " del conjunt." << endl;
	}
}

void Cjt_Especies::Existeix_especie(const string& id) {
	bool found = false;
	Esta_al_conjunt(found, id);
	if (found) cout << "L'especie amb identificador " << id << " existeix al conjunt." << endl;
	else cout << "L'especie amb identificador " << id << " no existeix al conjunt." << endl;
}

void Cjt_Especies::Buida_cjt_especies() {
	map_especies.clear();
}

void Cjt_Especies::Llegeix_cjt_especies(const int& n) {
	Buida_cjt_especies();
	string id, gen;
	for (int i = 0; i < n; ++i) {
		cin >> id >> gen;
		map_especies.insert(make_pair(id, Especie(gen)));
	}
}

void Cjt_Especies::Imprimeix_cjt_especies() {
	for (map<string, Especie>::iterator it = map_especies.begin(); it != map_especies.end(); ++it) {
		cout << it->first << " " << it->second.Obtenir_gen() << endl;
	}
}

void Cjt_Especies::Afegir_element_taula_distancies(const string& id) {

}

void Cjt_Especies::Imprimeix_taula_distancies() {
	
}

