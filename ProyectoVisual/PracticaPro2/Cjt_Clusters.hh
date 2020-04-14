/**
	*\file Cjt_Clusters.hh
	*\brief Representa un conjunt de clusters amb l'atribut \b map_clusters, on aquest agrupa tots els clusters.
*/
#pragma once
#include "BinTree.hh"
#include <iostream>
using namespace std;

/**
	*\class Cjt_Clusters Cjt_Clusters.hh
	*\brief Classe de conjunt de Clusters, conte un <em>BinTree de clusters</em>.
*/
class Cjt_Clusters
{

private:

	map<?,?> map_clusters;

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
		*\warning Salta error si el numero de clusters del conjunt es menor o igual a u.
		*\pre Cert.
		*\post S'ha executat un pas de l'algorisme WPGMA.
		*\param cluster1
		*\param cluster2
	*/
	Cjt_Clusters::Executa_pas_wpgma(cluster1, cluster2);

	/**
		*\brief Inicialitza el conjunt de clusters.
		*\pre Existeix un Cjt_Especies.
		*\post S'ha inicialitzat el Conjunt de clusters amb el Cjt_Especies actual. S'imprimiran els clusters resultants i la taula de distancies corresponent.
		*\note Si el conjunt es buit, no s'imprimira res.
	*/
	Cjt_Clusters::Inicialitza_clusters();

	/**
		*\brief Donat un identificador, imprimeix l'arbre corresponent.
		*\warning Salta error si no existeix un cluster amb l'identificador donat.
		*\pre S'ha llegit un identificador pel canal estandard d'entrada.
		*\post S'ha escrit pel canal estandard de sortida l'arbre corresponent a l'identificador donat.
		*\param string id Identificador del cluster per referencia constant.
	*/
	Cjt_Clusters::Imprimeix_clusters(const string& id);


	/**
		*\brief Imprimeix l'arbre resultant de tot l'algorisme WPGMA.
		*\warning Salta error si el nou conjunt de clusters es buit.
		*\pre Cert.
		*\post S'ha escrit pel canal estandard de sortida l'arbre resultant de l'algorisme WPGMA amb el Cjt_Especies actual.
	*/
	Cjt_Clusters::Imprimeix_arbre_filogenetic()

};
