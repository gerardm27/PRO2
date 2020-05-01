/**
	*\file Especie.hh
	*\brief Representa una Especie amb atributs \b gen i \b kmers, on l'ultim agrupa tots els strings de la separacio per kmer.
*/
#pragma once
#include <string>
#include <map>
#include <iostream>
using namespace std;

/**
	*\class Especie Especie.hh
	*\brief Classe Especie, conte un \a gen i un <em>mapa de kmers<\em>.
*/
class Especie
{
private:
	string gen;
	map<string,int> map_kmers;
	map<string, double> map_distancies;
	
	/**
		*\brief Calcula els kmer d'un gen d'una especie.
		*\pre Cert.
		*\post S'ha separat el gen en strings de longitud k.
		*\param map<string,int> map_kmers Mapa de kmers resultant per referencia.
	*/
	void Calcula_kmer(map<string,int>& map_kmers);
	static int k;

public: 
	/**
		*\brief Funcio constructora de la classe Especie.
		*\pre Cert.
		*\post S'ha creat una especie amb el gen donat.
		*\param string gen Gen de l'especie a crear per referencia constant.
	*/
	Especie(const string& gen);
	
	Especie();

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
		*\pre S'han entrat una Especie.
		*\post S'ha retornat la distancia pel canal estandard de sortida.
		*\param Especie e2 Segona especie a calcula per referencia.
	*/
	double Calcula_distancia(Especie &e2);

	/**
		*\brief S'utilitza per a obtenir el valor de k.
		*\pre Cert.
		*\post S'ha afegit el valor de k del programa.
		*\param int valor Valor de k.
		*\note Funcio auxiliar.
	*/
	static void Canviar_k(int valor);

	

};

