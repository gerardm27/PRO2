/**
	*\file Cjt_Clusters.hh
	*\brief Representa un conjunt de clusters amb l'atribut \b map_clusters, \b distancia_min, \b taula_clusters i \b set_clusters.
*/
#pragma once
#include "BinTree.hh"
#include "Cjt_Especies.hh"

/**
	*\class Cjt_Clusters Cjt_Clusters.hh
	*\brief Classe de conjunt de Clusters, forma un arbre filogenetic usant l'algorisme WPGMA.
*/
class Cjt_Clusters
{

private:
	
	/**
		*\short Valor molt alt per inicialitzar la distancia_minima;
	*/
	const int HIGH_VALUE = 999999;

	/**
		*\short Mapa de clusters, conte els clusters ordenats i en forma arborescent.
	*/
	map<string, BinTree<pair<string, double> > > mapa_clusters;

	/**
		*\short Mapa de clusters, conte els clusters ordenats i en forma arborescent.
	*/
	double distancia_min = HIGH_VALUE;

	/**
		*\short Taula de clusters, conte els clusters ordenats i les distancies respecte als altres.
	*/
	map<pair<string, string>, double> taula_clusters;
	
	/**
		*\short Set de clusters, conte la llista de clusters.
	*/
	set<string> set_clusters;

	/**
		*\brief Funcio recursiva per imprimir un cluster en forma arborescent.
		*\pre Cert.
		*\post S'ha impres l'arbre del parametre pel canal estandard de sortida.
		*\param Bintree<pair<string,double>> arbre Arbre a imprimir per referencia constant.
		*\note Funcio auxiliar.
	*/
	void Imprimeix_arbre(BinTree<pair<string, double> > arbre);

public:
	/**
		*\brief Funcio constructora de la classe Cjt_Clusters.
	*/
	Cjt_Clusters();

	/**
		*\brief Funcio destructora de la classe Cjt_Clusters.
	*/
	~Cjt_Clusters();

	/**
		*\brief Executa un pas de l'algorisme WPGMA.
		*\warning Salta error si el numero de clusters del conjunt implicit es menor o igual a u.
		*\pre Cert.
		*\post S'ha executat un pas de l'algorisme WPGMA.
		*\param bool print Boolea per definir si es necessita imprimir la taula de clusters. Fals de forma predeterminada.
	*/
	void Executa_pas_wpgma(bool print = false);

	/**
		*\brief Elimina un element de la taula de clusters.
		*\pre Cert.
		*\post S'ha eliminat un element de la taula de clusters.
		*\param string id Identificador del cluster a eliminar per referencia constant.
	*/
	void Eliminar_element_taula_clusters(const string& id);

	/**
		*\brief Afegeix un element a la taula de clusters.
		*\pre Cert.
		*\post S'ha afegit un element a la taula de clusters.
		*\param string id1 Identificador de la primera especie a fusionar.
		*\param string id2 Identificador de la segona especie a fusionar.
	*/
	void Afegir_element_taula_clusters(const string& id1, const string& id2);

	/**
		*\brief Inicialitza el conjunt de clusters.
		*\pre Existeix un Cjt_Especies.
		*\post S'ha inicialitzat el Conjunt de clusters amb el Cjt_Especies actual. S'imprimiran els clusters resultants i la taula de distancies corresponent.
		*\note Si el conjunt es buit, no s'imprimira res.
		*\param Cjt_Especies cjt_esp Conjunt d'Especies per referencia constant.
		*\param bool print Boolea per saber si imprimir o no. Cert de forma predeterminada.
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

	/**
		*\brief Imprimeix la taula de clusters.
		*\pre Cert.
		*\post S'ha escrit pel canal estandard de sortida la taula de clusters i les distancies corresponents.
		*\note Funcio auxiliar.
	*/
	void Imprimeix_taula_clusters();
};

