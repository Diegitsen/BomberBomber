#pragma once
#include "Jugador.h"
#include <vector>

using namespace std;

class ArrJugador
{
private:
	vector<CJugador*> arregloJ;
	
public:
 
	ArrJugador();
	~ArrJugador();
	vector<CJugador*> getArreglo();
	
	

	int getPos_jugadorx();
	int getPos_jugadory();
	int getNivel();
	int getX();
	int getY();
	int getCantBomb();
	int getCantExp();
	int getCantVida();
	int getTiempo();
	bool getCambioMapas();
	bool getColocar();
	bool getMuerte();
	int getContPuntos();
	bool getCambio();


	void setPos_jugadorx(int x);
	void setPos_jugadory(int y);
	void setNivel(int nivel);
	void setX(int x);
	void setY(int y);
	void setCantBomb(int v);
	void setCantExp(int v);
	void setCantVida(int v);
	void setTiempo(int v);
	void  setCambioMapas(bool v);
	void  setColocar(bool v);
	void  setMuerte(bool v);
	void setContPuntos(int v);
	void  setCambio(bool v);


	void Agregar(int x, int y);
	void Dibujar(BufferedGraphics^Buffer, Bitmap^bmp, int **Mapa, Bitmap ^fondo);
	void Dibujar_Muerte(BufferedGraphics^Buffer, Bitmap^bmp, Bitmap ^fondo);
	void Coliciones(BufferedGraphics^Buffer, Bitmap^bmp, int **Mapa, Bitmap ^fondo, int i, int j, int X, int Y);
	void Mover(BufferedGraphics^Buffer, Bitmap^bmp, int **Mapa, Bitmap ^fondo);
	void Colicion(BufferedGraphics^Buffer, Bitmap^bmp, int **Mapa, int i, int j, int X, int Y, int Ancho, int Alto);
	void Dibujar_dos(BufferedGraphics^Buffer, Bitmap^bmp, int **Mapa);
	void Cargar(int **Mapa);
	void Guardar(int **Mapa);
	void dibujarCorazones(BufferedGraphics^Buffer, Bitmap^bmp, Bitmap ^fondo, int posicion);
	void Aprobaste(BufferedGraphics^Buffer, Bitmap^bmp, Bitmap ^fondo);
};

ArrJugador::ArrJugador(){}
ArrJugador::~ArrJugador(){}

vector<CJugador*>ArrJugador::getArreglo() { return arregloJ; }



void ArrJugador::Dibujar_Muerte(BufferedGraphics^Buffer, Bitmap^bmp, Bitmap ^fondo)
{
	for (int i = 0; i < arregloJ.size(); i++)
	{
		arregloJ[i]->Dibujar_Muerte(Buffer, bmp, fondo);
	}
}
void ArrJugador::Coliciones(BufferedGraphics^Buffer, Bitmap^bmp, int **Mapa, Bitmap ^fondo, int i, int j, int X, int Y)
{
	for (int i = 0; i < arregloJ.size(); i++)
	{
		arregloJ[i]->Coliciones(Buffer, bmp, Mapa, fondo, i,j,X,Y);
	}
}
void ArrJugador::Mover(BufferedGraphics^Buffer, Bitmap^bmp, int **Mapa, Bitmap ^fondo)
{
	for (int i = 0; i < arregloJ.size(); i++)
	{
		arregloJ[i]->Mover(Buffer, bmp, Mapa, fondo);
	}
}
void ArrJugador::Colicion(BufferedGraphics^Buffer, Bitmap^bmp, int **Mapa, int i, int j, int X, int Y, int Ancho, int Alto)
{
	for (int i = 0; i < arregloJ.size(); i++)
	{
		arregloJ[i]->Colicion(Buffer, bmp, Mapa, i,j,X,Y,Ancho,Alto);
	}
}

void ArrJugador::Dibujar_dos(BufferedGraphics^Buffer, Bitmap^bmp, int **Mapa)
{
	for (int i = 0; i < arregloJ.size(); i++)
	{
		arregloJ[i]->Dibujar_dos(Buffer, bmp, Mapa);
	}
}
void ArrJugador::Cargar(int **Mapa)
{
	for (int i = 0; i < arregloJ.size(); i++)
	{
		arregloJ[i]->Cargar( Mapa);
	}
}
void ArrJugador::Guardar(int **Mapa)
{
	for (int i = 0; i < arregloJ.size(); i++)
	{
		arregloJ[i]->Guardar(Mapa);
	}
}
void ArrJugador::dibujarCorazones(BufferedGraphics^Buffer, Bitmap^bmp, Bitmap ^fondo, int posicion)
{
	for (int i = 0; i < arregloJ.size(); i++)
	{
		arregloJ[i]->dibujarCorazones(Buffer, bmp, fondo, posicion);
	}
}
void ArrJugador::Aprobaste(BufferedGraphics^Buffer, Bitmap^bmp, Bitmap ^fondo)
{
	for (int i = 0; i < arregloJ.size(); i++)
	{
		arregloJ[i]->Aprobaste(Buffer, bmp, fondo);
	}
}

void ArrJugador::Dibujar(BufferedGraphics^Buffer, Bitmap^bmp, int **Mapa, Bitmap ^fondo)
{
	for (int i = 0; i < arregloJ.size(); i++)
	{
		arregloJ[i]->Dibujar(Buffer, bmp, Mapa, fondo);
	}
}

void ArrJugador::Agregar(int x,int y)
{
	CJugador *nuevo = new CJugador(x, y);
	arregloJ.push_back(nuevo);
}

int ArrJugador::getPos_jugadorx(){ 
	for (int i = 0; i < arregloJ.size(); i++)
	{
		return arregloJ[i]->getX();
}

}
int ArrJugador::getPos_jugadory()
{
	for (int i = 0; i < arregloJ.size(); i++)
	{
		return arregloJ[i]->getY();
	}
}
int ArrJugador::getNivel()
{
	for (int i = 0; i < arregloJ.size(); i++)
	{
		return arregloJ[i]->getNivel();
	}
}
int ArrJugador::getX()
{
	for (int i = 0; i < arregloJ.size(); i++)
	{
		return arregloJ[i]->getX();
	}
}
int ArrJugador::getY()
{
	for (int i = 0; i < arregloJ.size(); i++)
	{
		return arregloJ[i]->getX();
	}
}
int ArrJugador::getCantBomb()
{
	for (int i = 0; i < arregloJ.size(); i++)
	{
		return arregloJ[i]->getCantidad_bombas();
	}
}
int ArrJugador::getCantExp()
{
	for (int i = 0; i < arregloJ.size(); i++)
	{
		return arregloJ[i]->getCantidad_explosion();
	}
}
int ArrJugador::getCantVida()
{
	for (int i = 0; i < arregloJ.size(); i++)
	{
		return arregloJ[i]->getCantidad_Vida();
	}
}
int ArrJugador::getTiempo()
{
	for (int i = 0; i < arregloJ.size(); i++)
	{
		return arregloJ[i]->getTiempo();
	}
}
bool ArrJugador::getCambioMapas()
{
	for (int i = 0; i < arregloJ.size(); i++)
	{
		return arregloJ[i]->getCambio_Mapas();
	}
}
bool ArrJugador::getColocar()
{
	for (int i = 0; i < arregloJ.size(); i++)
	{
		return arregloJ[i]->getColocar();
	}
}
bool ArrJugador::getMuerte()
{
	for (int i = 0; i < arregloJ.size(); i++)
	{
		return arregloJ[i]->getMuerte();
	}
}
int ArrJugador::getContPuntos()
{
	for (int i = 0; i < arregloJ.size(); i++)
	{
		return arregloJ[i]->getContador_puntos();
	}
}
bool ArrJugador::getCambio()
{
	for (int i = 0; i < arregloJ.size(); i++)
	{
		return arregloJ[i]->getCambio();
	}
}


void ArrJugador::setPos_jugadorx(int x)
{
	for (int i = 0; i < arregloJ.size(); i++)
	{
		arregloJ[i]->setX(x);
	}
}
void ArrJugador::setPos_jugadory(int y)
{
	for (int i = 0; i < arregloJ.size(); i++)
	{
		arregloJ[i]->setY(y);
	}
}
void ArrJugador::setNivel(int nivel)
{
	for (int i = 0; i < arregloJ.size(); i++)
	{
		arregloJ[i]->setNivel(nivel);
	}
}
void ArrJugador::setX(int x)
{
	for (int i = 0; i < arregloJ.size(); i++)
	{
		arregloJ[i]->setX(x);
	}
}
void ArrJugador::setY(int y)
{
	for (int i = 0; i < arregloJ.size(); i++)
	{
		arregloJ[i]->setY(y);
	}

}
void ArrJugador::setCantBomb(int v)
{
	for (int i = 0; i < arregloJ.size(); i++)
	{
		arregloJ[i]->setcantidad_bombas(v);
	}
}
void ArrJugador::setCantExp(int v)
{
	for (int i = 0; i < arregloJ.size(); i++)
	{
		arregloJ[i]->setcantidad_explosion(v);
	}
}
void ArrJugador::setCantVida(int v)
{
	for (int i = 0; i < arregloJ.size(); i++)
	{
		arregloJ[i]->setCantidad_Vida(v);
	}
}
void ArrJugador::setTiempo(int v)
{
	for (int i = 0; i < arregloJ.size(); i++)
	{
		arregloJ[i]->settiempo(v);
	}
}
void ArrJugador::setCambioMapas(bool v)
{
	for (int i = 0; i < arregloJ.size(); i++)
	{
		arregloJ[i]->setCambio_Mapas(v);
	}
}
void ArrJugador::setColocar(bool v)
{
	for (int i = 0; i < arregloJ.size(); i++)
	{
		arregloJ[i]->setColocar(v);
	}
}
void ArrJugador::setMuerte(bool v)
{
	for (int i = 0; i < arregloJ.size(); i++)
	{
		arregloJ[i]->setMuerte(v);
	}
}
void ArrJugador::setContPuntos(int v)
{
	for (int i = 0; i < arregloJ.size(); i++)
	{
		arregloJ[i]->setContador_puntos(v);
	}
}
void ArrJugador::setCambio(bool v)
{
	for (int i = 0; i < arregloJ.size(); i++)
	{
		arregloJ[i]->setCambio(v);
	}
}