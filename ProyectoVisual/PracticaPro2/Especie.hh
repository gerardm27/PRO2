#pragma once
#include <string>
#include <vector>
using namespace std;
/** @file Especie.hh
	@brief Representa una Especie con atributos GEN (una secuencia de simbolos de entre A, C, T y G) y ID
*/
class Especie
{
	Especie(string, string);

private:
	string gen;
	string id;
	
public:
	/**
	@brief 
	*/
	string obtener_gen();
	string obtener_id();
};

