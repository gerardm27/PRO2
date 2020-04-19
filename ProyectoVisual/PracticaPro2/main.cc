#include "main.hh"

int main(){
		gestiona_input();
}

void gestiona_input() {
	string comandament, id1, id2, gen;
	Cjt_Especies Especies;
	Cjt_Clusters Clusters;
	while (cin >> comandament and comandament != "fin") {

		if (comandament == "crea_especie") {
			cin >> id1 >> gen;
			Especies.Crea_especie(id1, gen);
		}
		else if (comandament == "obtener_gen") {
			cin >> id1;
			Especies.Obtenir_gen(id1);
		}
		else if (comandament == "distancia") {
			cin >> id1 >> id2;
			cout << Especies.Calcula_distancia(id1, id2);
		}
		else if (comandament == "elimina_especie") {
			cin >> id1;
			Especies.Elimina_especie(id1);
		}
		else if (comandament == "existe_especie") {
			cin >> id1;
			Especies.Existeix_especie(id1);
		}
		else if (comandament == "lee_cjt_especies") {
			int n;
			cin >> n;
			Especies.Llegeix_cjt_especies(n);
		}
		else if (comandament == "imprime_cjt_especies") {
			Especies.Imprimeix_cjt_especies();
		}
		else if (comandament == "tabla_distancias") {
			Especies.Imprimeix_taula_distancies();
		}
		else if (comandament == "inicializa_clusters") {
			Clusters.Inicialitza_clusters(Especies);
		}
		else if (comandament == "ejecuta_paso_wpgma") {
			Clusters.Executa_pas_wpgma();
		}
		else if (comandament == "imprime_cluster") {
			cin >> id1;
			Clusters.Imprimeix_clusters(id1);
		}
		else if (comandament == "imprime_arbol_filogenetico") {
			Clusters.Imprimeix_arbre_filogenetic();
		}
	}
}



