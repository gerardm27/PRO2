/**
	*\file Especie.hh
	*\brief Representa una Especie amb atributs \b gen i \b kmers, on l'ultim agrupa tots els strings de la separacio per kmer.
*/
#pragma once
#include <string>
#include <vector>
#include <iostream>
using namespace std;
class Especie
{
private:
	string gen;
	//Aqui tmb podem fer que el vector sigui de un pair<string,int> per a comptar quantes vegades surt cada kmer.
	vector<string> kmers;

	/**
		*\brief Separa el gen en kmer_value chars.
		*\pre S'ha llegit un string gen pel canal estandard d'entrada.
		*\post S'ha re-estructurat l'string en grups de kmer_value chars.
		*\param string gen Gen de l'element a re-estructurar.
	*/
	//set<string> Calcular_kmer(string gen);

public: 
	/**
		*\brief Funcio constructora de la classe Especie.
		*\pre Cert.
		*\post S'ha creat una especie amb el gen donat.
		*\param string gen Gen de l'especie a crear per referencia constant.
	*/
	Especie(const string& gen);

	/**
		*\brief Funcio destructora de la classe Especie.
	*/
	~Especie();


	/**
		*\brief Obte el gen de l'Especie del parametre implícit.
		*\pre Cert.
		*\post Retorna el gen associat a l'especie donada.
	*/
	string Obtenir_gen();

	/**
		*\brief Imprimeix la distancia entre dues especies donades.
		*\warning Salta error si no existeix una de les especies donades.
		*\pre S'han llegit els identificadors pel canal estandard d'entrada.
		*\post S'ha escrit la distancia pel canal estandard de sortida.
		*\param string id1 Identificador de la primera especie.
		*\param string id2 Identificador de la segona especie.
	*/
	double Calcula_distancia(const string& id2);
};

