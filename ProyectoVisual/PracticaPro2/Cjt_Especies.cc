#include "Cjt_Especies.hh"

Cjt_Especies::Cjt_Especies() {
	cin >> kmer_value;
}

Cjt_Especies::~Cjt_Especies()
{

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
		map_especies.insert(make_pair(id, gen));
		cout << "S'ha afegit l'especie amb identificador " << id << " i gen " << gen << " al conjunt" << endl;
		Actualitza_taula_distancies();
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
		cout << "El gen associat a l'identificador " << id << " es: " << map_especies[id] << endl;
	}
}

void Cjt_Especies::Distancia(const string& id1, const string& id2) {
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
	map<string, string>::iterator it = map_especies.begin();
	while (not map_especies.empty()) {
		map_especies.erase(it);
		it = map_especies.begin();
	}
}

void Cjt_Especies::Llegeix_cjt_especies(int& n) {
	Buida_cjt_especies();
	string id, gen;
	for (int i = 0; i < n; ++i) {
		cin >> id >> gen;
		map_especies.insert(make_pair(id, gen));
	}
}

void Cjt_Especies::Imprimeix_cjt_especies() {
	for (map<string, string>::iterator it = map_especies.begin(); it != map_especies.end(); ++it) {
		cout << it->first << " " << it->second << endl;
	}

void Cjt_Especies::Afegir_element_taula_distancies(const string& id)
{

}

void Cjt_Especies::Imprimeix_taula_distancies() {
	
}
 //Corregir i entendre per a mi
set<string> Cjt_Especies::Calcular_kmer(string gen) {
	int size = gen.size();
	set<string> kmer;
	for (int i = 0; i < (size - kmer_value); ++i) {
		string kmerAux;
		for (int j = i; j < i + kmer_value; ++j) {
			kmerAux += gen[j];
		}
		set<string>::const_iterator it = kmer.end();
		kmer.insert(it, kmerAux);
	}
	return kmer;
}

//Corregir i entendre per a mi
double Cjt_Especies::CalcularDistancia(string genA, string genB) {
	double unio = 0;
	double interseccio = 0;
	set <string> kmer1 = Calcular_kmer(genA);
	set <string> kmer2 = Calcular_kmer(genB);
	for (set<string>::iterator it = kmer1.begin(); it != kmer1.end(); ++it) {
		set<string>::iterator it2 = kmer2.find(*it);
		if (it2 != kmer2.end()) {
			++interseccio;
			++unio;
			kmer2.erase(it2);
		}
		else {
			++unio;
		}
	}
	unio += kmer2.size();
	return (1.00 - (interseccio / unio)) * 100;
}

