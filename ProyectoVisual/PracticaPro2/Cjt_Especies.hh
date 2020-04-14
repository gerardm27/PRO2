/** 
	*\file Cjt_Especies.hh
	*\brief Representa un conjunt d'Especies amb atributs \b kmer_value i \b map_especies, on l'ultim agrupa totes les especies.
*/
#pragma once
#include <map>
#include <vector>
#include <string>
#include <set>
#include <iostream>
using namespace std;

/**
	*\class Cjt_Especies Cjt_Especies.hh 
	*\brief Classe de conjunt d'Especies, conte el valor \a kmer i un <em>mapa d'especies</em>.
*/
class Cjt_Especies
{
private:
	/**
		*\short Valor de \a k per a calcular distancies.
	*/
	int kmer_value;
	/** 
		*\short Mapa d'especies amb \a identificador i \a gen, respectivament. Agrupa especies per al calcul de \a WPGMA.
	*/
	map<string, string> map_especies;

	/**
		*\short Taula de distancies amb Identificador i Vector de distancies.
	*/
	map<string, vector<double>> Taula_distancies;

	/**
		*\brief Buida el conjunt d'especies.
		*\note Aquesta funcio no pot ser cridada per l'usuari. Es d'us auxiliar.
		*\pre Cert
		*\post S'ha buidat el conjunt d'especies.
	*/
	void Cjt_Especies::Buida_cjt_especies();

	/**
		*\brief Afegeix un element a la taula.
		*\pre S'ha llegit un string id pel canal estandard d'entrada.
		*\post S'ha afegit un element a la taula de distancies.
		*\param string id Identificador de l'element a afegir per referencia constant.
	*/
	void Cjt_Especies::Afegir_element_taula_distancies(const string& id);

	/**
		*\brief Separa el gen en kmer_value chars.
		*\pre S'ha llegit un string gen pel canal estandard d'entrada.
		*\post S'ha re-estructurat l'string en grups de kmer_value chars.
		*\param string gen Gen de l'element a re-estructurar.
	*/
	set<string> Cjt_Especies::Calcular_kmer(string gen);

	/**
	\brief Comproba si l'element donat esta al conjunt.
	\note Aquesta funcio no pot ser cridada per l'usuari. Es d'us auxiliar.
	\pre Found = false.
	\post Found si existeix l'element al conjunt, !Found si no existeix.
	\param bool found Boolea per referencia.
	\param string id Identificador de l'especie a evaluar per referencia constant.
	*/
	void Cjt_Especies::Esta_al_conjunt(bool& found, const string& id);

public:

	/**
		*\brief Funció constructora de la clasee Cjt_Especies.
		*\short La funció recull el valor inicial de la \a k de l'algoritme \a kmer, i inicialitza el mapa d'especies (posteriorment explicat) en un mapa buit.
	*/
	Cjt_Especies();
	/**
		*\brief Funció destructora de la classe	Cjt_Especies.
	*/
	~Cjt_Especies();
	
	/**
		*\brief Crea una especie i la afegeix al conjunt.
		*\warning Salta error si ja existeix una especie amb el mateix identificador.
		*\pre S'han llegit dos strings id, i gen pel canal estandard d'entrada.
		*\post S'ha afegit l'especie al conjunt.
		*\param string id Identificador de l'especie.
		*\param string gen Gen de l'especie.
	*/
	void Cjt_Especies::Crea_especie(const string& id,const string& gen);
	
	/**
		*\brief Imprimeix el gen d'un identificador donat.
		*\warning Salta error si no existeix una especie amb l'identificador donat.
		*\pre S'ha llegit l'identificador pel canal estandard d'entrada.
		*\post S'ha escrit el gen associat a l'identificador pel canal estandard de sortida.
		*\param string id Identificador a associar amb un gen
	*/
	void Cjt_Especies::Obtenir_gen(const string& id);

	/**
		*\brief Imprimeix la distancia entre dues especies donades.
		*\warning Salta error si no existeix una de les especies donades.
		*\pre S'han llegit els identificadors pel canal estandard d'entrada.
		*\post S'ha escrit la distancia pel canal estandard de sortida.
		*\param string id1 Identificador de la primera especie.
		*\param string id2 Identificador de la segona especie.
	*/
	void Cjt_Especies::Distancia(const string& id1,const string& id2);

	/**
		*\brief Elimina l'especie del conjunt.
		*\warning Salta error si no existeix l'especie donada.
		*\pre S'ha llegit l'identificador pel canal estandard d'entrada.
		*\post S'ha eliminat l'especie del conjunt.
		*\param string id Identificador de l'especie a eliminar.
	*/
	void Cjt_Especies::Elimina_especie(const string& id);

	/**
		*\brief Imprimeix si exiteix l'especie donada.
		*\pre S'ha llegit l'identificador pel canal estandard d'entrada.
		*\post S'ha escrit si existeix o no l'especie donada pel canal estandard de sortida.
		*\param string id Identificador de l'especie a evaluar.
	*/
	void Cjt_Especies::Existeix_especie(const string& id);

	/**
		*\brief Llegeix i omple un conjunt d'n especies.
		*\pre Cert
		*\post S'han llegit n parells d'identificadors i gens (Especies) pel canal estandard d'entrada i s'han introduit al conjunt buit.
		*\param int n Enter n per referencia
	*/
	void Cjt_Especies::Llegeix_cjt_especies(int& n);

	/**
		*\brief Imprimeix el conjunt d'especies.
		*\pre Cert.
		*\post S'ha escrit pel canal estandard de sortida.
		*\note Si el conjunt es buit, no s'escriura res.
	*/
	void Cjt_Especies::Imprimeix_cjt_especies()
	
	/**
		*\brief Imprimeix la taula de distancies
		*\pre Cert
		*\post S'ha impres pel canal estandard de sortida la taula de distancies.
	*/
	void Imprimeix_taula_distancies();
};

