/** 
	*\file Cjt_Especies.hh
	*\brief Representa un conjunt d'Especies amb atributs kmer_value i map_especies, on l'ultim agrupa totes les especies.
**/
#pragma once
#include <map>

/**
	*\class Cjt_Especies Cjt_Especies.hh
	*\brief Classe de conjunt d'Especies, conte el valor \a kmer i un mapa d'especies.
*/
class Cjt_Especies
{
	/**
		*\brief Funció constructora de la clase Cjt_Especies.
		*\short La funció recull el valor inicial de la \a k de l'algoritme \a kmer, i inicialitza el mapa d'especies (posteriorment explicat) en un mapa buit.
	*/
	Cjt_Especies::Cjt_Especies() {
		cin >> kmer_value;
	}
	Cjt_Especies::~Cjt_Especies() {

	}
private:
	/**
		*\short Valor de \a k per a calcular distancies.
	*/
	int kmer_value;
	/** 
		*\short Mapa d'especies amb \a identificador i \a gen, respectivament. Agrupa especies per al calcul de WPGMA.
	*/
	map<string, string> map_especies;

public:
	
	/**
		*\brief Crea una especie i la afegeix al conjunt.
		*\warning Salta error si ja existeix una especie amb el mateix identificador.
		*\pre S'han llegit dos strings id, i gen pel canal estandard d'entrada.
		*\post S'ha afegit l'especie al conjunt.
		*\param string id Identificador de l'especie.
		*\param string gen Gen de l'especie.
	*/
	void Cjt_Especies::crea_especie(string id, string gen);
	
	/**
		*\brief Imprimeix el gen d'un identificador donat.
		*\warning Salta error si no existeix una especie amb l'identificador donat.
		*\pre S'ha llegit l'identificador pel canal estandard d'entrada.
		*\post S'ha escrit el gen associat a l'identificador pel canal estandard de sortida.
		*\param string id Identificador a associar amb un gen
	*/
	void Cjt_Especies::obtenir_gen(string id);

	/**
		*\brief Imprimeix la distancia entre dues especies donades.
		*\warning Salta error si no existeix una de les especies donades.
		*\pre S'han llegit els identificadors pel canal estandard d'entrada.
		*\post S'ha escrit la distancia pel canal estandard de sortida.
		*\param string id1 Identificador de la primera especie.
		*\param string id2 Identificador de la segona especie.
	*/
	void Cjt_Especies::distancia(string id1, string id2);

	/**
		*\brief Elimina l'especie del conjunt.
		*\warning Salta error si no existeix l'especie donada.
		*\pre S'ha llegit l'identificador pel canal estandard d'entrada.
		*\post S'ha eliminat l'especie del conjunt.
		*\param string id Identificador de l'especie a eliminar.
	*/
	void Cjt_Especies::elimina_especie(string id);

	/**
		*\brief Imprimeix si exiteix l'especie donada.
		*\pre S'ha llegit l'identificador pel canal estandard d'entrada.
		*\post S'ha escrit si existeix o no l'especie donada pel canal estandard de sortida.
		*\param string id Identificador de l'especie a evaluar.
	*/
	void Cjt_Especies::existeix_especie(string id);

	/**
		*\brief Buida el conjunt d'especies.
		*\note Aquesta funcio no pot ser cridada per l'usuari. Es d'us auxiliar.
		*\pre Cert
		*\post S'ha buidat el conjunt d'especies.
	*/
	void Cjt_Especies::buida_cjt_especies();

	/**
		*\brief Llegeix i omple un conjunt d'n especies.
		*\pre Cert
		*\post S'han llegit n parells d'identificadors i gens (Especies) pel canal estandard d'entrada i s'han introduit al conjunt buit.
	*/
	void Cjt_Especies::lee_cjt_especies();





};

