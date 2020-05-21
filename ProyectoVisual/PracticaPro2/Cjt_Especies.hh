/** 
	*\file Cjt_Especies.hh
	*\brief Representa un conjunt d'Especies amb atribut \b map_especies, on s'agrupen totes les especies.
*/
#pragma once
#include <set>
#include "Especie.hh"

/**
	*\class Cjt_Especies Cjt_Especies.hh 
	*\brief Classe de conjunt d'Especies, conte un \a mapa \a d'especies.
*/
class Cjt_Especies
{
private:
	/** 
		*\short Mapa d'especies amb \a identificador i \a Especie, respectivament. Agrupa especies per al calcul de l'algorisme \a WPGMA.
	*/
	map<string, Especie> map_especies;

	/**
		*\brief Afegeix un element a la taula.
		*\pre S'ha llegit un string id pel canal estandard d'entrada.
		*\post S'ha afegit un element a la taula de distancies.
		*\param string id Identificador de l'element a afegir per referencia constant.
	*/
	void Afegir_element_taula_distancies(const string& id);

	/**
		*\brief Elimina un element de la taula.
		*\pre S'ha llegit un string id pel canal estandard d'entrada.
		*\post S'ha eliminat un element de la taula de distancies.
		*\param string id Identificador de l'element a eliminar per referencia constant.
	*/
	void Eliminar_element_taula_distancies(const string& id);

	/**
		*\brief Comprova si l'element donat esta al conjunt.
		*\note Aquesta funcio no pot ser cridada per l'usuari. Es d'us auxiliar.
		*\pre Found = false.
		*\post Found si existeix l'element al conjunt, !Found si no existeix.
		*\param bool found Boolea per referencia.
		*\param string id Identificador de l'especie a evaluar per referencia constant.
	*/
	void Esta_al_conjunt(bool& found, const string& id);

public:
	
	/**
		*\short Taula de distancies per emmagatzemar les distancies.
	*/
	map<pair<string,string>,double> taula_distancies;

	/**
		*\brief Funcio constructora de la classe Cjt_Especies.
	*/
	Cjt_Especies();

	/**
		*\brief Funcio destructora de la classe	Cjt_Especies.
	*/
	~Cjt_Especies();
	
	/**
		*\brief Crea una especie i l'afegeix al conjunt.
		*\warning Salta error si ja existeix una especie amb el mateix identificador.
		*\pre S'han llegit dos strings id, i gen pel canal estandard d'entrada.
		*\post S'ha afegit l'especie al conjunt.
		*\param string id Identificador de l'especie per referencia constant.
		*\param string gen Gen de l'especie per referencia constant.
	*/
	void Crea_especie(const string& id, const string& gen);
	
	/**
		*\brief Imprimeix el gen d'un identificador donat.
		*\warning Salta error si no existeix una especie amb l'identificador donat.
		*\pre S'ha llegit l'identificador pel canal estandard d'entrada.
		*\post S'ha escrit el gen associat a l'identificador pel canal estandard de sortida.
		*\param string id Identificador a associar amb un gen per referencia constant.
	*/
	void Obtenir_gen(const string& id);
	
	/**
		*\brief Calcula la distancia entre les dues especies.
		*\pre Cert.
		*\warning Salta un error si qualssevol de les dues especies donades no existeix.
		*\post S'ha retornat la distancia entre les dues especies donades.
		*\param string id Identificador de la primera especie per referencia constant.
		*\param string id2 Identificador de la segona especie per referencia constant.

	*/
	double Calcula_distancia(const string& id, const string& id2);

	/**
		*\brief Elimina l'especie del conjunt.
		*\warning Salta error si no existeix l'especie donada.
		*\pre S'ha llegit l'identificador pel canal estandard d'entrada.
		*\post S'ha eliminat l'especie del conjunt.
		*\param string id Identificador de l'especie a eliminar.
	*/
	void Elimina_especie(const string& id);

	/**
		*\brief Imprimeix si existeix l'especie donada.
		*\pre S'ha llegit l'identificador pel canal estandard d'entrada.
		*\post S'ha escrit si existeix o no l'especie donada pel canal estandard de sortida.
		*\param string id Identificador de l'especie a evaluar.
	*/
	void Existeix_especie(const string& id);

	/**
		*\brief Llegeix i omple un conjunt d'n especies.
		*\pre S'ha llegit un enter n pel canal estandard d'entrada.
		*\post S'han llegit n parells d'identificadors i gens (Especies) pel canal estandard d'entrada i s'han introduit al conjunt buit.
		*\param int n Enter n per referencia constant.
	*/
	void Llegeix_cjt_especies(const int& n);

	/**
		*\brief Imprimeix el conjunt d'especies.
		*\pre Cert.
		*\post S'ha escrit pel canal estandard de sortida el conjunt.
		*\note Si el conjunt es buit, no s'escriura res.
	*/
	void Imprimeix_cjt_especies();
	
	/**
		*\brief Imprimeix la taula de distancies.
		*\pre Cert.
		*\post S'ha impres pel canal estandard de sortida la taula de distancies.
	*/
	void Imprimeix_taula_distancies();
};

