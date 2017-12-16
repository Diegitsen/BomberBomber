#pragma once
#pragma once
#include <vector>
#include "Enemigo.h"
using namespace std;

class CArrEnemigo
{
private:
	vector<CEnemigo*>arreglo;
	int pos_jugadorx;
	int pos_jugadory;


	int cant_enemigos;

	bool muerte = false;


public:
	CArrEnemigo();
	~CArrEnemigo();

	vector<CEnemigo*>getArreglo();


	int get_x() {
		for (int i = 0; i < arreglo.size(); i++)
		{
			return	arreglo[i]->get_x();

		}

	}
	int get_y() {

		for (int i = 0; i < arreglo.size(); i++)
		{
			return arreglo[i]->get_y();
		}

	}


	void setPos_jugadorx(int pos_jugadorx)
	{
		this->pos_jugadorx = pos_jugadorx;

	}
	void setPos_jugadory(int pos_jugadory)
	{
		this->pos_jugadory = pos_jugadory;
	}
	void setCant_enemigos(int cant_enemigos) { this->cant_enemigos = cant_enemigos; };
	void dibujar_enemy(BufferedGraphics^Buffer, Bitmap^bmp, int **Mapa, Bitmap ^fondo, int pos_Rec1_x, int pos_Rec2_y);
	void mover(BufferedGraphics^Buffer, Bitmap^bmp, int **Mapa, Bitmap ^fondo, int x_pos_inicio, int x_rebote, bool &c);
	void Agregar_enemy(int x, int y, int iz, int der, int valor);
	void eliminar();
	void Colision();

	bool  get_muerte() { return muerte; }
	void set_muerte(bool muerte) { this->muerte = muerte; }
};

CArrEnemigo::CArrEnemigo()
{
}

CArrEnemigo::~CArrEnemigo()
{
}

vector<CEnemigo*> CArrEnemigo::getArreglo() {
	return arreglo;
};

void CArrEnemigo::Colision() {
	for (int i = 0; i < arreglo.size(); i++) {
		arreglo[i]->setPos_Jugador_X(pos_jugadorx);
		arreglo[i]->setPos_Jugador_Y(pos_jugadory);
	}
}
void CArrEnemigo::dibujar_enemy(BufferedGraphics^Buffer, Bitmap^bmp, int **Mapa, Bitmap ^fondo, int pos_Rec1_x, int pos_Rec2_y)
{

	for (int i = 0; i < arreglo.size(); i++)
	{
		arreglo[i]->dibujar_enemy(Buffer, bmp, Mapa, fondo, pos_Rec1_x, pos_Rec2_y);
	}



}
void CArrEnemigo::mover(BufferedGraphics^Buffer, Bitmap^bmp, int **Mapa, Bitmap ^fondo, int x_pos_inicio, int x_rebote, bool &c)
{
	for (int i = 0; i < arreglo.size(); i++)
	{
		arreglo[i]->mover(Buffer, bmp, Mapa, fondo, x_pos_inicio, x_rebote, c);
	}

}

void CArrEnemigo::Agregar_enemy(int x, int y, int iz, int der, int valor)
{
	CEnemigo* nuevo = new CEnemigo(x, y, iz, der, valor);
	arreglo.push_back(nuevo);

}


void CArrEnemigo::eliminar()
{
	for (int i = 0; i < arreglo.size(); i++)
	{
		if (muerte == true)
			arreglo.erase(arreglo.begin() + i);

	}


}

