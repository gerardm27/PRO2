/**
	*\file program.hh
	*\brief Controla el programa.
*/

/**
	*\mainpage Documentacio de la Practica.
	*\section introduccio Objectius:
	*\arg Crear una implementacio adequada acord a l'enunciat presentat.
	*\arg Aprendre a documentar correctament un projecte.
	*\arg Escriure un codi eficient i poc costos.
	* 
	*\section v1 Versio 1:
	*\arg Creades les classes.
	*\arg Creada la especificacio de les classes i de les seves funcions.
	*
	*\section v2 Versio 2:
	*\arg Creades les instruccions de l'entrega intermitja.
	*\arg Creades les funcions de les classes Especie i Cjt_Especies.
	*
	*\section v3 Versio 3:
	*\arg Creades les instruccions de l'entrega final.
	*\arg Afegides les funcions de la classe Cjt_Clusters.
	*\arg Creades funcions auxiliars per a millorar el rendiment.
	*\arg Maximitzada l'eficiencia.

*/

#pragma once
#include "Cjt_Clusters.hh"

/**
	*\brief Primera funcio que s'executa al programa.
*/
int main();

/**
	*\brief Gestiona l'input rebut.
	*\pre Cert.
	*\post Ha rebut l'input i ha actuat en consequencia a l'instruccio.
	*
	*\short Analitza totes les comandes del programa:
	*\arg \b crea_especie: Crea una nova especie amb identificador i gen, i l'afegeix al conjunt.
	*\arg \b obtener_gen: Retorna el gen de l'identificador donat.
	*\arg \b distancia: Retorna la distancia entre dos identificadors (Especies).
	*\arg \b elimina_especie: Elimina l'Especie assignada a l'identificador donat.
	*\arg \b existe_especie: Indica si existeix o no l'Especie amb l'identificador donat.
	*\arg \b lee_cjt_especies: Buida el Cjt_Especies anterior i en llegeix un de nou.
	*\arg \b imprime_cjt_especies: Retorna el Cjt_Especies per pantalla.
	*\arg \b tabla_distancias: Imprimeix la taula de distancies entre Especies.
	*\arg \b inicializa_clusters: Inicialitza el Cjt_Clusters amb el Cjt_Especies actual.
	*\arg \b ejecuta_paso_wpgma: Executa una iteracio de l'algorisme WPGMA i ho imprimeix per pantalla.
	*\arg \b imprime_cluster: Imprimeix el cluster donat.
	*\arg \b imprime_arbol_filogenetico: Imprimeix l'arbre filogenetic resultant de tot l'algorisme WPGMA.
	*\arg \b fin: Finalitza l'execucio del programa.
*/
void gestiona_input();