#include "program.hh"

int main(){
		gestiona_input();
}

void gestiona_input() {
	//Obtenir la k.
	int valor;
	cin >> valor;
	Especie::Canviar_k(valor);

	string comandament, id1, id2, gen;
	Cjt_Especies Especies;
	Cjt_Clusters Clusters;
	while (cin >> comandament and comandament != "fin") {

		if (comandament == "crea_especie") {
			cin >> id1 >> gen;
			cout << "# crea_especie " << id1 << " " << gen << endl;
			Especies.Crea_especie(id1, gen);
			cout << endl;
		}
		else if (comandament == "obtener_gen") {
			cin >> id1;
			cout << "# obtener_gen " << id1 << endl;
			Especies.Obtenir_gen(id1);
			cout << endl;
		}
		else if (comandament == "distancia") {
			cin >> id1 >> id2;
			cout << "# distancia " << id1 << " " << id2 << endl;
			double dis = Especies.Calcula_distancia(id1, id2);
			if (dis != -1) cout << dis << endl;
			cout << endl;
		}
		else if (comandament == "elimina_especie") {
			cin >> id1;
			cout << "# elimina_especie " << id1 << endl;
			Especies.Elimina_especie(id1);
			cout << endl;
		}
		else if (comandament == "existe_especie") {
			cin >> id1;
			cout << "# existe_especie " << id1 << endl;
			Especies.Existeix_especie(id1);
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
		/*
		else if (comandament == "inicializa_clusters") {
			Clusters.Inicialitza_clusters(Especies);
			cout << endl;
		}
		else if (comandament == "ejecuta_paso_wpgma") {
			Clusters.Executa_pas_wpgma();
			cout << endl;
		}
		else if (comandament == "imprime_cluster") {
			cin >> id1;
			Clusters.Imprimeix_clusters(id1);
			cout << endl;
		}
		else if (comandament == "imprime_arbol_filogenetico") {
			Clusters.Imprimeix_arbre_filogenetic();
			cout << endl;
		}
		*/
	}
}



