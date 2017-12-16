#pragma once
#include <vector>

#include "Bombas.h"

using namespace std;

class CArrBombas
{
private:
	vector<CBombas*>arreglo;
	int pos_jugadorx;
	int pos_jugadory;

	int pos_enemigo_X;
	int pos_enemigo_Y;



	int explosion;
	int cantidad_bobas;
public:

	CArrBombas();
	~CArrBombas();
	vector<CBombas*>getArreglo();
	void setCantidad_Bombas(int cantidad_bobas) { this->cantidad_bobas = cantidad_bobas; }
	void setPos_jugadorx(int pos_jugadorx) { this->pos_jugadorx = pos_jugadorx; };
	void setPos_jugadory(int pos_jugadory) { this->pos_jugadory = pos_jugadory; };
	void setExplosio(int explosion) { this->explosion = explosion; }
	void Bomba(BufferedGraphics^Buffer, Bitmap^bmp2, Bitmap^bmp3, int **Mapa, bool &c, int&d, int &e, bool&muerte);

	void setPos_pos_enemigo_x(int pos_enemigo_X) { this->pos_enemigo_X = pos_enemigo_X; }
	void setPos_pos_enemigo_y(int pos_enemigo_Y) { this->pos_enemigo_Y = pos_enemigo_Y; }



	void agregar(int x, int y, int tiempo);
	void eliminar();
	void validacion();
	void explosion_bomba();
};



CArrBombas::CArrBombas()
{
}


CArrBombas::~CArrBombas()
{
}

vector<CBombas*>CArrBombas::getArreglo() { return arreglo; }

void CArrBombas::agregar(int x, int y, int tiempo) {
	if (arreglo.size() < cantidad_bobas) {
		CBombas *nuevo = new CBombas(x, y, tiempo);
		arreglo.push_back(nuevo);
	}
}
void CArrBombas::Bomba(BufferedGraphics^Buffer, Bitmap^bmp, Bitmap^bmp2, int **Mapa, bool &c, int&d, int &e, bool&muerte) {

	for (int i = 0; i < arreglo.size(); i++) {
		arreglo[i]->Bomba(Buffer, bmp, bmp2, Mapa, c, d, e, arreglo[i]->getX(), arreglo[i]->getY(), muerte);
	}

}
void CArrBombas::eliminar() {

	for (int i = 0; i < arreglo.size(); i++) {
		if (arreglo[i]->getTermino() == true) {
			arreglo.erase(arreglo.begin() + i);
		}
	}
}

void  CArrBombas::validacion() {

	for (int i = 0; i < arreglo.size(); i++) {
		arreglo[i]->setPos_Jugador_X(pos_jugadorx);
		arreglo[i]->setPos_Jugador_Y(pos_jugadory);
	}

}

void CArrBombas::explosion_bomba() {
	for (int i = 0; i < arreglo.size(); i++) {
		arreglo[i]->setExplosio(explosion);
	}
}