/**
	*\file Cjt_Especies.cc
	*\brief Representa un conjunt d'Especies.
*/


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
		cout << "ERROR: La especie " << id << " ya existe." << endl;
	}
	//Sino l'afegeix
	else {
		Especie e(gen);
		map_especies.insert(make_pair(id, e));
		Afegir_element_taula_distancies(id);
	}
}

void Cjt_Especies::Obtenir_gen(const string& id) {
	bool found = false;
	Esta_al_conjunt(found, id);

	//Si ha acabat i no l'ha trobat, no existeix
	if (not found) {
		cout << "ERROR: La especie " << id << " no existe." << endl;
	}
	else {
		cout << map_especies[id].Obtenir_gen() << endl;
	}
}

double Cjt_Especies::Calcula_distancia(const string& id, const string& id2) {
	bool found1 = false;
	bool found2 = false;
	Esta_al_conjunt(found1, id);
	Esta_al_conjunt(found2, id2);
	if (not found1 and found2) {
		cout << "ERROR: La especie " << id << " no existe." << endl;
		return -1;
	}
	else if (found1 and not found2) {
		cout << "ERROR: La especie " << id2 << " no existe." << endl;
		return -1;
	}
	if (not found1 and not found2) {
		cout << "ERROR: La especie " << id << " y la especie " << id2 << " no existen." << endl;
		return -1;
	}
	else {
			return map_especies[id].Calcula_distancia(map_especies[id2]);
	}
}


void Cjt_Especies::Elimina_especie(const string& id) {
	bool found = false;
	Esta_al_conjunt(found, id);

	//Si no existeix, salta exception
	if (not found) {
		cout << "ERROR: La especie " << id << " no existe." << endl;
	}
	else {
		Eliminar_element_taula_distancies(id);
		map_especies.erase(id);
	}
}

void Cjt_Especies::Existeix_especie(const string& id) {
	bool found = false;
	Esta_al_conjunt(found, id);
	if (found) cout << "SI" << endl;
	else cout << "NO" << endl;
}

void Cjt_Especies::Llegeix_cjt_especies(const int& n) {
	taula_distancies.clear();
	map_especies.clear();
	string id, gen;
	for (int i = 0; i < n; ++i) {
		cin >> id >> gen;
		Crea_especie(id, gen);
	}
}

void Cjt_Especies::Imprimeix_cjt_especies() {
	for (map<string, Especie>::iterator it = map_especies.begin(); it != map_especies.end(); ++it) {
		cout << it->first << " " << it->second.Obtenir_gen() << endl;
	}
}


void Cjt_Especies::Afegir_element_taula_distancies(const string& id) {
	for (map<string, Especie>::iterator it = map_especies.begin(); it != map_especies.end(); ++it) {
		if (it->first < id) {
			taula_distancies.insert(make_pair(make_pair(it->first, id), map_especies.find(id)->second.Calcula_distancia(it->second)));
		}
		else if (it->first == id) {
			taula_distancies.insert(make_pair(make_pair(id, it->first), double(0)));
		}
		else {
			taula_distancies.insert(make_pair(make_pair(id, it->first), map_especies.find(id)->second.Calcula_distancia(it->second)));
		}
	}
}

void Cjt_Especies::Eliminar_element_taula_distancies(const string& id) {
	map<pair<string,string>, double>::iterator it = taula_distancies.begin();

	while (it != taula_distancies.end() and it->first.first <= id) {
		if (it->first.first == id or it->first.second == id) {
			taula_distancies.erase(it++);
		}
		else {
			++it;
		}
	}
}

void Cjt_Especies::Imprimeix_taula_distancies() {
	if (not taula_distancies.empty()) {
		string ultim_tractat;
		for (map<pair<string, string>, double>::iterator it = taula_distancies.begin(); it != taula_distancies.end(); ++it) {
			if (ultim_tractat == it->first.first) {
				cout << ' ' << it->first.second << " (" << it->second << ')';
			}
			else if (it == taula_distancies.begin()) {
				cout << it->first.first << ':';
				if (it->first.first != it->first.second) {
					cout << ' ' << it->first.second << " (" << it->second << ')';
				}
				ultim_tractat = it->first.first;
			}
			else {
				cout << endl << it->first.first << ':';
				if (it->first.first != it->first.second) {
					cout << ' ' << it->first.second << " (" << it->second << ')';
				}
				ultim_tractat = it->first.first;
			}
		}
		cout << endl;
	}
}

