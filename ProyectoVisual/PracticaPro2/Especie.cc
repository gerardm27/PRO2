#include "Especie.hh"

Especie::Especie(const string& gen)
{
	this->gen = gen;
}

Especie::~Especie()
{
}

string Especie::Obtenir_gen()
{
	return gen;
}

double Especie::Calcula_distancia(const string& id2)
{
	
}

