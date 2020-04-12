#include "Cjt_Especies.hh"


Cjt_Especies::Cjt_Especies() {
	cin >> kmer_value;
}

void Cjt_Especies::esta_al_conjunt(bool& found, const string& id) {
	//Si l'element que troba no esta a la ultima+1 posicio, vol dir que existeix.
	if (map_especies.find(id) != map_especies.end()) found = true;
	//Si esta a la ultima+1 (end), no existeix.
	else found = false;
}

void Cjt_Especies::crea_especie(const string& id, string gen) {
	bool found = false;
	esta_al_conjunt(found, id);
	//Si ja existeix, salta exception
	if (found) {
		throw "what(): Ja existeix?";
	}
	//Sino l'afegeix
	else {
		map_especies.insert(make_pair(id, gen));
		cout << "S'ha afegit l'especie amb identificador " << id << " i gen " << gen << " al conjunt" << endl;
	}
}

void Cjt_Especies::obtenir_gen(const string& id) {
	bool found = false;
	esta_al_conjunt(found, id);

	//Si ha acabat i no l'ha trobat, no existeix
	if (not found) {
		throw "what(): No existeix?";
	}
	else {
		cout << "El gen associat a l'identificador " << id << " es: " << map_especies[id] << endl;
	}
}

void Cjt_Especies::distancia(const string& id1, const string& id2) {
	bool found = false;
	esta_al_conjunt(found, id1);
	//Si no existeix un dels dos, salta exception
	if (not found) {
		throw "what(): No existeix?"
	}
	else {
		found = false;
		esta_al_conjunt(found, id2);
		if (not found) {
			throw "what(): No existeix?"
		}
		//Calcular la distancia entre id1, id2
		else {
			
		}
	}
}

void Cjt_Especies::elimina_especie(const string& id) {
	bool found = false;
	esta_al_conjunt(found, id);

	//Si no existeix, salta exception
	if (not found) {
		throw "what(): No existeix?"
	}
	else {
		map_especies.erase(id);
		cout << "S'ha eliminat l'especie amb identificador " << id << " del conjunt." << endl;
	}
}

void Cjt_Especies::existeix_especie(string id) {
	bool found = false;
	esta_al_conjunt(found, id);
	if(found) cout << "L'especie amb identificador " << id << " existeix al conjunt."
	else cout <<"L'especie amb identificador " << id << " no existeix al conjunt."
}

void Cjt_Especies::buida_cjt_especies() {
	map<string, string>::iterator it = map_especies.begin();
	while (not map_especies.empty()) {
		map_especies.erase(it->first);
		++it;
	}
}

void Cjt_Especies::lee_cjt_especies(n) {
	string id, gen;
	for(int i = 0; i < n; ++i){
		cin >> id >> gen;
		map_especies.insert(make_pair(id, gen));
	}
}

