/**
	*\file Cjt_Clusters.hh
	*\brief Representa un conjunt de clusters amb l'atribut \b map_clusters, on aquest agrupa tots els clusters.
*/
#pragma once
#include "BinTree.hh"
#include "Cjt_Especies.hh"
#include <set>

/**
	*\class Cjt_Clusters Cjt_Clusters.hh
	*\brief Classe de conjunt de Clusters, conte un <em>BinTree de clusters</em>.
*/
class Cjt_Clusters
{

private:
	
	map<string, BinTree<pair<string, double> > > mapa_clusters;
	double distancia_min = 999999;
	map<pair<string, string>, double> taula_clusters;
	set<string> set_clusters;

	void Imprimeix_arbre(BinTree<pair<string, double> > arbre);

public:
	/**
	\brief Funcio constructora de la classe Cjt_Clusters.
	*/
	Cjt_Clusters();

	/**
		\brief Funcio destructora de la classe Cjt_Clusters.
	*/
	~Cjt_Clusters();

	/**
		*\brief Executa un pas de l'algorisme WPGMA.
		*\warning Salta error si el numero de clusters del conjunt implicit es menor o igual a u.
		*\pre Cert.
		*\post S'ha executat un pas de l'algorisme WPGMA.
	*/
	void Executa_pas_wpgma(bool print = false);

	void Eliminar_element_taula_clusters(const string& id);

	void Afegir_element_taula_clusters(const string& id1, const string& id2);

	/**
		*\brief Inicialitza el conjunt de clusters.
		*\pre Existeix un Cjt_Especies.
		*\post S'ha inicialitzat el Conjunt de clusters amb el Cjt_Especies actual. S'imprimiran els clusters resultants i la taula de distancies corresponent.
		*\note Si el conjunt es buit, no s'imprimira res.
	*/
	void Inicialitza_clusters(const Cjt_Especies& cjt_esp, bool print = true);

	/**
		*\brief Donat un identificador, imprimeix l'arbre corresponent.
		*\warning Salta error si no existeix un cluster amb l'identificador donat.
		*\pre S'ha llegit un identificador pel canal estandard d'entrada.
		*\post S'ha escrit pel canal estandard de sortida l'arbre corresponent a l'identificador donat.
		*\param string id Identificador del cluster per referencia constant.
	*/
	void Imprimeix_clusters(const string& id);


	/**
		*\brief Imprimeix l'arbre resultant de tot l'algorisme WPGMA.
		*\warning Salta error si el nou conjunt de clusters es buit.
		*\pre Cert.
		*\post S'ha escrit pel canal estandard de sortida l'arbre resultant de l'algorisme WPGMA amb el Cjt_Especies actual.
	*/
	void Imprimeix_arbre_filogenetic();

	void Imprimeix_taula_clusters();
	
};

