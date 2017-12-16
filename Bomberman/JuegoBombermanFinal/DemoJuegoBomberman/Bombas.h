#pragma once
#include <fstream>
//recursividad linea de codigo 176
using namespace System::Drawing;
using namespace std;
using namespace System;


class CBombas
{
public:
	int x;
	int y;
	int Indicex;
	int contador;
	int IndiceY_E;
	int explosion;
	int pos_Jugador_X;
	int pos_Jugador_Y;
	bool termino;
	int tiemp;


	int pos_enemigo_X;
	int pos_enemigo_Y;



public:
	CBombas();
	~CBombas();
	CBombas(int x, int y, int tiemp);
	int getX() { return x; }
	int getY() { return y; }
	bool getTermino() { return termino; }
	void setPos_Jugador_X(int pos_Jugador_X) { this->pos_Jugador_X = pos_Jugador_X; }
	void setPos_Jugador_Y(int pos_Jugador_Y) { this->pos_Jugador_Y = pos_Jugador_Y; }

	void setExplosio(int explosion) { this->explosion = explosion; }

	void Bomba(BufferedGraphics^Buffer, Bitmap^bmp2, Bitmap^bmp3, int **Mapa, bool &c, int &d, int &e, int x, int y, bool &muerte);
	void Colicion_B(BufferedGraphics^Buffer, Bitmap^bmp, int **Mapa, int i, int j, int X, int Y, int Ancho, int Alto, float x, float y, int IndiceX, bool &c, int &d, int &e, bool &veri, bool &muerte);

	void setPos_pos_enemigo_x(int pos_enemigo_X) { this->pos_enemigo_X = pos_enemigo_X; }
	void setPos_pos_enemigo_y(int pos_enemigo_Y) { this->pos_enemigo_Y = pos_enemigo_Y; }


};

CBombas::CBombas() {


}


CBombas::~CBombas() {}

CBombas::CBombas(int x, int y, int tiemp) {
	this->x = x;
	this->y = y;
	this->tiemp = tiemp;
	Indicex = 0;
	contador = 1;
	IndiceY_E = 1;
	explosion = 1;
	termino = false;

}



void CBombas::Bomba(BufferedGraphics^Buffer, Bitmap^bmp, Bitmap^bmp2, int **Mapa, bool &c, int &d, int &e, int x, int y, bool &muerte) {
	int Ancho = 59;
	int Alto = 100;
	System::Drawing::Rectangle Porcion = System::Drawing::Rectangle(Ancho * Indicex + 3, 0, Ancho, Alto);
	System::Drawing::Rectangle Aumento = System::Drawing::Rectangle(x + 12, y + 10, Ancho*0.45, Alto*0.45);
	Buffer->Graphics->DrawImage(bmp, Aumento, Porcion, System::Drawing::GraphicsUnit::Pixel);


	Indicex++;
	contador++;
	if (Indicex >= 3) {
		Indicex = 1;
	}
	if (contador >= tiemp) {

		Indicex = 0; contador++;
		bool uno, muerte = true;
		if (explosion == 1) {

			Colicion_B(Buffer, bmp2, Mapa, 0, 0, 0, 0, 32, 32, x + 14, y + 26, 0, c, d, e, uno, muerte);

			Colicion_B(Buffer, bmp2, Mapa, 0, 0, 0, 0, 32, 32, x + 39, y + 26, 5, c, d, e, uno, muerte);
			Colicion_B(Buffer, bmp2, Mapa, 0, 0, 0, 0, 32, 32, x - 12, y + 26, 6, c, d, e, uno, muerte);
			Colicion_B(Buffer, bmp2, Mapa, 0, 0, 0, 0, 32, 32, x + 14, y + 51, 4, c, d, e, uno, muerte);
			Colicion_B(Buffer, bmp2, Mapa, 0, 0, 0, 0, 32, 32, x + 14, y - 3, 3, c, d, e, uno, muerte);

			termino = true;
		}
		if (explosion == 2) {

			Colicion_B(Buffer, bmp2, Mapa, 0, 0, 0, 0, 32, 32, x + 12, y + 24, 0, c, d, e, uno, muerte);

			//derecha

			Colicion_B(Buffer, bmp2, Mapa, 0, 0, 0, 0, 32, 32, x + 39, y + 26, 2, c, d, e, uno, muerte);

			if (uno, muerte == true) {
				Colicion_B(Buffer, bmp2, Mapa, 0, 0, 0, 0, 32, 32, x + 72, y + 26, 5, c, d, e, uno, muerte);

			}
			//izquierda
			uno = true;
			Colicion_B(Buffer, bmp2, Mapa, 0, 0, 0, 0, 32, 32, x - 12, y + 26, 2, c, d, e, uno, muerte);

			if (uno == true) {
				Colicion_B(Buffer, bmp2, Mapa, 0, 0, 0, 0, 32, 32, x - 45, y + 26, 6, c, d, e, uno, muerte);

			}
			//abajo
			uno = true;
			Colicion_B(Buffer, bmp2, Mapa, 0, 0, 0, 0, 32, 32, x + 14, y + 51, 1, c, d, e, uno, muerte);

			if (uno == true) {
				Colicion_B(Buffer, bmp2, Mapa, 0, 0, 0, 0, 32, 32, x + 14, y + 85, 4, c, d, e, uno, muerte);

			}
			//arriba
			uno = true;
			Colicion_B(Buffer, bmp2, Mapa, 0, 0, 0, 0, 32, 32, x + 14, y - 3, 1, c, d, e, uno, muerte);

			if (uno == true) {
				Colicion_B(Buffer, bmp2, Mapa, 0, 0, 0, 0, 32, 32, x + 14, y - 37, 3, c, d, e, uno, muerte);

			}
			termino = true;
		}
		//falta 
		if (explosion == 3) {

			Colicion_B(Buffer, bmp2, Mapa, 0, 0, 0, 0, 32, 32, x + 14, y + 26, 0, c, d, e, uno, muerte);

			Colicion_B(Buffer, bmp2, Mapa, 0, 0, 0, 0, 32, 32, x + 39, y + 26, 2, c, d, e, uno, muerte);
			if (uno == true)
				Colicion_B(Buffer, bmp2, Mapa, 0, 0, 0, 0, 32, 32, x + 72, y + 26, 2, c, d, e, uno, muerte);
			if (uno == true)
				Colicion_B(Buffer, bmp2, Mapa, 0, 0, 0, 0, 32, 32, x + 105, y + 26, 5, c, d, e, uno, muerte);

			uno = true;

			Colicion_B(Buffer, bmp2, Mapa, 0, 0, 0, 0, 32, 32, x - 12, y + 26, 2, c, d, e, uno, muerte);
			if (uno == true)
				Colicion_B(Buffer, bmp2, Mapa, 0, 0, 0, 0, 32, 32, x - 45, y + 26, 2, c, d, e, uno, muerte);
			if (uno == true)
				Colicion_B(Buffer, bmp2, Mapa, 0, 0, 0, 0, 32, 32, x - 78, y + 26, 6, c, d, e, uno, muerte);

			uno = true;

			Colicion_B(Buffer, bmp2, Mapa, 0, 0, 0, 0, 32, 32, x + 14, y + 51, 1, c, d, e, uno, muerte);
			if (uno == true)
				Colicion_B(Buffer, bmp2, Mapa, 0, 0, 0, 0, 32, 32, x + 14, y + 85, 1, c, d, e, uno, muerte);
			if (uno == true)
				Colicion_B(Buffer, bmp2, Mapa, 0, 0, 0, 0, 32, 32, x + 14, y + 119, 4, c, d, e, uno, muerte);

			uno = true;

			Colicion_B(Buffer, bmp2, Mapa, 0, 0, 0, 0, 32, 32, x + 14, y - 3, 1, c, d, e, uno, muerte);
			if (uno == true)
				Colicion_B(Buffer, bmp2, Mapa, 0, 0, 0, 0, 32, 32, x + 14, y - 37, 1, c, d, e, uno, muerte);
			if (uno == true)
				Colicion_B(Buffer, bmp2, Mapa, 0, 0, 0, 0, 32, 32, x + 14, y - 71, 3, c, d, e, uno, muerte);
			termino = true;
		}

		//Colicion_P(Buffer, bmp2, Mapa, 0, 0, 0, 0, 32, 32, x + 14, y + 26, 0);
		//Colicion_P(Buffer, bmp2, Mapa, 0, 0, 0, 0, 32, 32, x + 39, y + 26, 5);
		//Colicion_P(Buffer, bmp2, Mapa, 0, 0, 0, 0, 32, 32, x - 12, y + 26, 6);
		//Colicion_P(Buffer, bmp2, Mapa, 0, 0, 0, 0, 32, 32, x + 14, y + 51, 4);
		//Colicion_P(Buffer, bmp2, Mapa, 0, 0, 0, 0, 32, 32, x + 14, y - 3, 3);


		return;
	}

}

void CBombas::Colicion_B(BufferedGraphics^Buffer, Bitmap^bmp, int **Mapa, int i, int j, int X, int Y, int Ancho, int Alto, float x, float y, int IndiceX_E, bool &c, int &d, int &e, bool &veri, bool &muerte) {
	Random rand;


	int cambio = rand.Next(10, 250);
	if (i >= 20) { return; }
	else
	{
		if (j < 20) {
			System::Drawing::Rectangle  Jugador1 = System::Drawing::Rectangle(x + 4, y + 8, (Ancho - 20), (Alto - 20));
			Buffer->Graphics->FillRectangle(System::Drawing::Brushes::Transparent, Jugador1);
			System::Drawing::Rectangle  Jugador2 = System::Drawing::Rectangle(pos_Jugador_X + 10, pos_Jugador_Y + 15, 33, 33);
			Buffer->Graphics->FillRectangle(System::Drawing::Brushes::Transparent, Jugador2);
			System::Drawing::Rectangle  Jugador3 = System::Drawing::Rectangle(pos_enemigo_X + 10, pos_enemigo_Y + 15, 26, 26);
			Buffer->Graphics->FillRectangle(System::Drawing::Brushes::Transparent, Jugador2);

			System::Drawing::Rectangle  Rec1 = System::Drawing::Rectangle(X, Y, 32, 32);

			if (Jugador1.IntersectsWith(Jugador3))muerte = true;


			if (Jugador1.IntersectsWith(Jugador2)) {

				c = true;
				d = 0;
			}
			if (Mapa[i][j] == 0) {

				if (Jugador1.IntersectsWith(Rec1)) {
					System::Drawing::Rectangle Porcion = System::Drawing::Rectangle(Ancho * IndiceX_E, Alto*IndiceY_E, Ancho, Alto);
					System::Drawing::Rectangle Aumento = System::Drawing::Rectangle(x, y, Ancho, Alto);
					Buffer->Graphics->DrawImage(bmp, Aumento, Porcion, System::Drawing::GraphicsUnit::Pixel);
					veri = true;
				}
			}

			if (Mapa[i][j] == 7) {

				if (Jugador1.IntersectsWith(Rec1)) {

					System::Drawing::Rectangle Porcion = System::Drawing::Rectangle(Ancho * IndiceX_E, Alto*IndiceY_E, Ancho, Alto);
					System::Drawing::Rectangle Aumento = System::Drawing::Rectangle(x, y, Ancho, Alto);
					Buffer->Graphics->DrawImage(bmp, Aumento, Porcion, System::Drawing::GraphicsUnit::Pixel);
					veri = true;
					if (cambio > 15)
						Mapa[i][j] = 0;
					else
						Mapa[i][j] = cambio;
				}

			}

			if (Mapa[i][j] == 1) {

				if (Jugador1.IntersectsWith(Rec1)) {
					veri = false;
				}
			}

			Colicion_B(Buffer, bmp, Mapa, i, j + 1, X + 32, Y, Ancho, Alto, x, y, IndiceX_E, c, d, e, veri, muerte);
		}
		else
		{
			Colicion_B(Buffer, bmp, Mapa, i + 1, 0, 0, Y + 32, Ancho, Alto, x, y, IndiceX_E, c, d, e, veri, muerte);
		}
	}

}

