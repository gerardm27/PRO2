/**
	*\file program.cc
	*\brief Arxiu base del programa. Gestiona l'input.
*/

#include "program.hh"

int main(){
		gestiona_input();
}

void gestiona_input() {
	//Obtenir la k.
	int valor;
	cin >> valor;
	Especie::Canviar_k(valor);

	string comandament, id, id2, gen;
	Cjt_Especies Especies;
	Cjt_Clusters Clusters;
	while (cin >> comandament and comandament != "fin") {
		if (comandament == "crea_especie") {
			cin >> id >> gen;
			cout << "# crea_especie " << id << " " << gen << endl;
			Especies.Crea_especie(id, gen);
			cout << endl;
		}
		else if (comandament == "obtener_gen") {
			cin >> id;
			cout << "# obtener_gen " << id << endl;
			Especies.Obtenir_gen(id);
			cout << endl;
		}
		else if (comandament == "distancia") {
			cin >> id >> id2;
			cout << "# distancia " << id << " " << id2 << endl;
			double dis = Especies.Calcula_distancia(id, id2);
			if (dis != -1) cout << dis << endl;
			cout << endl;
		}
		else if (comandament == "elimina_especie") {
			cin >> id;
			cout << "# elimina_especie " << id << endl;
			Especies.Elimina_especie(id);
			cout << endl;
		}
		else if (comandament == "existe_especie") {
			cin >> id;
			cout << "# existe_especie " << id << endl;
			Especies.Existeix_especie(id);
			cout << endl;
		}
		else if (comandament == "lee_cjt_especies") {
			int n;
			cin >> n;
			cout << "# lee_cjt_especies" << endl;
			Especies.Llegeix_cjt_especies(n);
			cout << endl;
		}
		else if (comandament == "imprime_cjt_especies") {
			cout << "# imprime_cjt_especies" << endl;
			Especies.Imprimeix_cjt_especies();
			cout << endl;
		}
		else if (comandament == "tabla_distancias") {
			cout << "# tabla_distancias" << endl;
			Especies.Imprimeix_taula_distancies();
			cout << endl;
		}
		else if (comandament == "inicializa_clusters") {
			cout << "# inicializa_clusters" << endl;
			Clusters.Inicialitza_clusters(Especies);
			cout << endl;
		}
		else if (comandament == "ejecuta_paso_wpgma") {
			cout << "# ejecuta_paso_wpgma" << endl;
			Clusters.Executa_pas_wpgma(true);
			cout << endl;
		}
		else if (comandament == "imprime_cluster") {
			cin >> id;
			cout << "# imprime_cluster " << id << endl;
			Clusters.Imprimeix_clusters(id);
			cout << endl;
		}
		else if (comandament == "imprime_arbol_filogenetico") {
			cout << "# imprime_arbol_filogenetico" << endl;
			Clusters.Inicialitza_clusters(Especies, false);
			Clusters.Imprimeix_arbre_filogenetic();
			cout << endl;
		}
	}
}



