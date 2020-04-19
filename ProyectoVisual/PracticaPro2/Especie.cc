#include "Especie.hh"

Especie::Especie(const string& gen)
{
	this->gen = gen;
	Calcula_kmer(map_kmers);
}

Especie::~Especie()
{
	
}

string Especie::Obtenir_gen()
{
	return gen;
}

void Especie::Calcula_kmer(map<string,int>& map_kmers)
{
	int kmer_value = Get_kmer();
	int counter = 0;
	string aux;
	for (int i = 0; i < gen.size() - kmer_value; ++i) {
		aux.append(gen.begin()+counter, gen.begin()+counter+kmer_value);
		counter++;
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
	int unio, interseccio;
	for (map<string, int>::iterator it = map_kmers.begin(); it != map_kmers.end(); ++it) {
		if (map_kmers_2.find(it->first) != map_kmers_2.end()) {
			if (it->second == map_kmers_2.find(it->first)->second) {
				interseccio += it->second;
				unio += it->second;
			}
			else if (it->second > map_kmers_2.find(it->first)->second) {
				interseccio += map_kmers_2.find(it->first)->second;
				unio += it->second;
			}
			else {
				interseccio += it->second;
				unio += map_kmers_2.find(it->first)->second;
			}
			map_kmers_2.erase(it->first);
		}
		else {
			unio += it->second;
		}
		
	}
	for (map<string, int>::iterator it = map_kmers_2.begin(); it != map_kmers.end(); ++it) {
		unio += it->second;
	}
	return ((1 - (interseccio / unio)) * 100);
}

