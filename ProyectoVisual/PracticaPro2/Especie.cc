/**
	*\file Especie.cc
	*\brief Representa una Especie.
*/

#include "Especie.hh"

Especie::Especie(const string& gen)
{
	this->gen = gen;
	Calcula_kmer(map_kmers);
}

Especie::Especie()
{
}


Especie::~Especie()
{
	
}
int Especie::k;

string Especie::Obtenir_gen()
{
	return gen;
}

void Especie::Calcula_kmer(map<string,int>& map_kmers)
{
	for (int i = 0; i <= gen.size() - k; ++i) {
		string aux;
		aux.append(gen.begin()+i, gen.begin()+i+k);
		if (map_kmers.find(aux) == map_kmers.end()) {
			map_kmers.insert(make_pair(aux, 1));
		}
		else {
			map_kmers.find(aux)->second += 1;
		}
	}
}

double Especie::Calcula_distancia(Especie& e2)
{
	map<string, int> map_kmers_2 = e2.map_kmers;
	double unio = 0;
	double interseccio = 0;
	for (map<string, int>::iterator it = map_kmers.begin(); it != map_kmers.end(); ++it) {
		map<string, int>::iterator it2 = map_kmers_2.find(it->first);
		
		if (it2 != map_kmers_2.end()) {
			if (it->second <= it2->second) {
				interseccio += it->second;
				unio += it2->second;
			}
			else if (it->second > it2->second) {
				interseccio += it2->second;
				unio += it->second;
			}
			map_kmers_2.erase(it->first);
		}
		else {
			unio += it->second;
		}
		
	}
	for (map<string, int>::iterator it = map_kmers_2.begin(); it != map_kmers_2.end(); ++it) {
		unio += it->second;
	}
	return ((1 - (interseccio / unio)) * 100);
}

void Especie::Canviar_k(int valor)
{
	if (k == 0) {
		k = valor;
	}
}

