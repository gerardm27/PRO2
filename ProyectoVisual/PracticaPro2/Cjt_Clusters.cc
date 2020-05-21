/**
	*\file Cjt_Clusters.cc
	*\brief Representa un conjunt de clusters.
*/

#include "Cjt_Clusters.hh"
using namespace std;

Cjt_Clusters::Cjt_Clusters()
{
}

Cjt_Clusters::~Cjt_Clusters()
{
}

void Cjt_Clusters::Inicialitza_clusters(const Cjt_Especies& cjt_esp, bool print)
{
	taula_clusters = cjt_esp.taula_distancies;
	set_clusters.clear();
	mapa_clusters.clear();

	if (taula_clusters.size() != 0) {
		map<pair<string, string>, double>::iterator it = taula_clusters.begin();
		
		string primer = it->first.first;
		set_clusters.insert(it->first.first);
		BinTree<pair<string, double> > primer_cluster(make_pair(it->first.first, 0.0));
		mapa_clusters.insert(make_pair(it->first.first, primer_cluster));

		while (it != taula_clusters.end() and it->first.first == primer) {
			set_clusters.insert(it->first.second);
			BinTree<pair<string, double> > a(make_pair(it->first.second, 0.0));
			mapa_clusters.insert(make_pair(it->first.second, a));
			++it;
		}
		if (print) {
			Imprimeix_taula_clusters();
		}
	}
}

void Cjt_Clusters::Executa_pas_wpgma(bool print)
{
	if (set_clusters.size() > 1) {
		distancia_min = HIGH_VALUE;
		map<pair<string, string>, double>::iterator it = taula_clusters.begin();
		string id1, id2;
		while (it != taula_clusters.end()) {
			if (it->second < distancia_min and it->first.first != it->first.second) {
				distancia_min = it->second;
				id1 = it->first.first;
				id2 = it->first.second;
			}
			++it;
		}
		Afegir_element_taula_clusters(id1, id2);
		set_clusters.erase(id1);
		set_clusters.erase(id2);
		Eliminar_element_taula_clusters(id1);
		Eliminar_element_taula_clusters(id2);
		set_clusters.insert(id1 + id2);

		
		BinTree<pair<string, double> > a(make_pair(id1 + id2, distancia_min / 2), mapa_clusters.find(id1)->second, mapa_clusters.find(id2)->second);
		mapa_clusters.insert(make_pair(id1 + id2, a));
		mapa_clusters.erase(id1);
		mapa_clusters.erase(id2);

		if (print) {
			Imprimeix_taula_clusters();
		}

	}
	else {
		cout << "ERROR: num_clusters <= 1" << endl;
	}
}

void Cjt_Clusters::Eliminar_element_taula_clusters(const string& id) {
	map<pair<string, string>, double>::iterator it = taula_clusters.begin();
	if(taula_clusters.size() > 1){
		while (it != taula_clusters.end() and it->first.first <= id) {
			if (it->first.first == id or it->first.second == id) {
				taula_clusters.erase(it++);
			}
			else {
				++it;
			}
		}
	}
}

void Cjt_Clusters::Afegir_element_taula_clusters(const string& id1, const string& id2) {
	set<string>::iterator it = set_clusters.begin();
	
	while (it != set_clusters.end()) {
		if (*it != id1 and *it != id2) {
			double dist_aux = 0;
			if (*it < id1) {
				dist_aux += taula_clusters.find(make_pair(*it, id1))->second;
				dist_aux += taula_clusters.find(make_pair(*it, id2))->second;
				taula_clusters.insert(make_pair(make_pair(*it, id1 + id2), dist_aux / 2));
			}
			else if (*it < id2) {
				dist_aux += taula_clusters.find(make_pair(id1, *it))->second;
				dist_aux += taula_clusters.find(make_pair(*it, id2))->second;
				taula_clusters.insert(make_pair(make_pair(id1 + id2, *it), dist_aux / 2));
			}
			else {
				dist_aux += taula_clusters.find(make_pair(id1, *it))->second;
				dist_aux += taula_clusters.find(make_pair(id2, *it))->second;
				taula_clusters.insert(make_pair(make_pair(id1 + id2, *it), dist_aux / 2));
			}
		}
		++it;
	}
	taula_clusters.insert(make_pair(make_pair(id1 + id2, id1 + id2), 0));
}

void Cjt_Clusters::Imprimeix_taula_clusters() {
	if (not taula_clusters.empty()) {
		string ultim_tractat;
		for (map<pair<string, string>, double>::iterator it = taula_clusters.begin(); it != taula_clusters.end(); ++it) {
			
			if (ultim_tractat == it->first.first) {
				cout << ' ' << it->first.second << " (" << it->second << ')';
			}
			else if (it == taula_clusters.begin()) {
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

void Cjt_Clusters::Imprimeix_arbre(BinTree<pair<string, double> > a) {
	if (!a.empty()) {
		cout << '[';
		pair<string, double> valor = a.value();
		if (a.left().empty() or a.right().empty()) {
			cout << valor.first;
		}
		else {
			cout << '(' << valor.first << ", " << valor.second << ") ";
			Imprimeix_arbre(a.left());
			Imprimeix_arbre(a.right());
		}
		cout << ']';
	}
}
	 
void Cjt_Clusters::Imprimeix_clusters(const string& id)
{
	map<string, BinTree<pair<string, double> > >::iterator it = mapa_clusters.find(id);
	if (it != mapa_clusters.end()) {
		Imprimeix_arbre(it->second);
		cout << endl;
	}
	else {
		cout << "ERROR: El cluster " << id << " no existe." << endl;
	}
}

void Cjt_Clusters::Imprimeix_arbre_filogenetic()
{
	if (set_clusters.size() > 0) {
		while (set_clusters.size() > 1) {
			Executa_pas_wpgma();
		}
		string id = *(set_clusters.begin());
		Imprimeix_arbre(mapa_clusters.find(id)->second);
		cout << endl;

	}
	else {
		cout << "ERROR: El conjunto de clusters es vacio." << endl;
	}

}

