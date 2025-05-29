#include <iostream> // para std::cin y std::getline
#include <cstdlib> //Para system("cls") y system("pause")
#include <ctime> // Para usar srand y rand
#include <string>   // Para usar string
#include <thread>   // Necesario para sleep
#include <chrono>   // Necesario para manipular el tiempo sin problemas 
#include <locale> //Para usar ñ y acentos en el texto
#include <windows.h> // Para usar Sleep en Windows

using namespace std;

// ============================
// Implementación de funciones globales
// ============================

// Funcion para limpiar la pantalla y pausar el juego
void LimpiarPantalla() {
    cout << "\n";
    system("pause");
    system("cls");
}


// Funcion para cambiar el color de la consola
#pragma region CambiarColor
void CambiarColoraBlanco() {
    system("color F0");  
    Sleep(200);
    system("color 07");
}

void CambiarColoraAmarillo() {
    system("color E0");
    Sleep(200);
    system("color 07");
}



void CambiarColorPurpura() {
    system("color 5F");
    Sleep(500);
    system("color 07");
}

void CambiarColorVerde() {
    system("color AF");
    Sleep(500);
    system("color 07");
}
void CambiaColorRojo()
{
    system("color 4F");
    Sleep(500);
    system("color 07");
}

void CambiarColorCafe() {
	system("color 6F");
	Sleep(500);
	system("color 07");
}

#pragma endregion


// ============================
// Clases
// ============================


// Creamos la clase con las estadisticas de nuestro jugador
class JugadorPrincipal {
public:
    string nombreJugador;
    int progresoInvestigacion;
    int oxigeno;
    int municion;
    int danioDisparo = 50;
	int danioCuerpoACuerpo = 20;

    // Constructor de nuestro jugador para establecer sus estadísticas
    JugadorPrincipal() {
        SemillaRandom();
        nombreJugador;
        oxigeno = 100;
        municion = 3;
        progresoInvestigacion = 0;
    }

#pragma region SeccionesGettersySetters
public:
    void setMunicion(int _municion) {
        municion = _municion;
    }

    int getMunicion() {
        return municion;
    }

    void setOxigeno(int _oxigeno) {
        oxigeno = _oxigeno;
    }

    int getOxigeno() {
        return oxigeno;
    }

    void setProgresoInvestigacion(int _progresoInvestigacion) {
        progresoInvestigacion = _progresoInvestigacion;
    }

    int getProgresoInvestigacion() {
        return progresoInvestigacion;
    }

	void setDanioCuerpoACuerpo(int _danioCuerpoACuerpo) {
		danioCuerpoACuerpo = _danioCuerpoACuerpo;
	}

	int getDanioCuerpoACuerpo() {
		return danioCuerpoACuerpo;
	}
#pragma endregion

#pragma region AleatorizarySemilla
    // Funcion para aleatorizar entre dos números
    int AleatorizarEstadisticas(int _minimo, int _maximo) {
        return _minimo + rand() % (_maximo - _minimo + 1);
    }

    // Funcion para iniciar semilla de aleatoriedad
    void SemillaRandom() {
        srand(static_cast<unsigned int>(time(0)));
    }
#pragma endregion

    // Opción narrativa del jugador
    void HistoriaElegida() {
        int opcionHistoriaElegida;
        cout << "Ahora elige como quieres afrontar a los alienigenas:\n\n";
        cout << "1.Atacar\n2.Contactar con ellos\n3.Tengo miedo, ya me quiero ir\n";
        cout << "\n/////////////////////////////////////////  Selecciona una opción (1-3)  ///////////////////////////////////////////////" << endl;
		cout << "\nOpcion elegida: ";
        cin >> opcionHistoriaElegida;
        switch (opcionHistoriaElegida)
        {
        case 1:
			CambiaColorRojo();
            cout << "\nHas decidido atacar a los alienigenas, sin embargo al estar cerca de ellos, ellos ya se han ido,\npero logras ver que se meten a un tunel subterraneo y decides seguirlos.\n";
            LimpiarPantalla();
            break;
        case 2:
			CambiarColorPurpura();
            cout << "\nHas decidido contactar con ellos, sin embargo tu IA espacial no logra decodificar su idioma,\npero logras ver que se meten a un tunel subterraneo y decides seguirlos.\n";
            LimpiarPantalla();
            break;
        case 3:
            if (opcionHistoriaElegida == 3)
            {
                CambiarColorCafe();
                cout << "\nHas decidido no seguirlos despues de haberte cagado encima por lo que comunicas a la Tierra tu inmediata extraccion,\nsiendo conocido como el astronauta mas cobarde de la galaxia.\n";
                exit(0); // Termina el juego si elige no seguirlos
            }
            break;
        }
       
    }


    // Función para imprimir estadísticas del personaje
    void MostrarInventario() {
		cout << " \n\n||||||||||INVENTARIO|||||||||||\n\n";
        cout << "Nombre del Jugador: " << nombreJugador << endl;
        cout << "Oxigeno: " << oxigeno << endl;
        cout << "Municion: " << municion << endl;
        cout << "Progreso de Investigacion: " << progresoInvestigacion << "\n\n";
    }

    // Caja de riesgo: cambia recursos aleatoriamente
    void CajaDeRiesgoUnion() {
        int opcionRuleta = AleatorizarEstadisticas(1, 4);
        switch (opcionRuleta) {
        case 1: setOxigeno(oxigeno + 30);
            cout << "Has ganado 30 de oxigeno, ahora tienes: " << oxigeno << " de oxigeno";
            break;
        case 2: setOxigeno(oxigeno - 20);
            cout << "Has perdido 20 de oxigeno, ahora tienes: " << oxigeno << " de oxigeno";
            break;
        case 3: setMunicion(municion + 3);
            cout << "Has ganado 3 de municion, ahora tienes: " << municion << " de municion";
            break;
        case 4: setMunicion(municion - 1);
            cout << "Has perdido 1 de municion, ahora tienes: " << municion << " de municion";
            break;
        }
        cout << "\n\n";
        system("pause");
        system("cls");
    }
};


// Clase para el enemigo alienígena
class Alienigena {
public:
    string nombreAlienigena;
    int vidaAlienigena;
    int ataqueAlienigena = 25;

    //Constructor Alienigena
    Alienigena() {
        nombreAlienigena = "Alienigena";
        vidaAlienigena = 100;
        ataqueAlienigena = 20;
    }

    void MostrarEstadisticasAlienigena() {
        cout << "Enemigo: " << nombreAlienigena << endl;
        cout << "Vida: " << vidaAlienigena << endl;
        cout << "Ataque: " << ataqueAlienigena << "\n\n";
    }

    // Funciones para establecer y obtener las estadísticas del alienígena
#pragma region SeccionesGettersySettersAlienigena
    void setVidaAlienigena(int _vidaAlienigena) {
        vidaAlienigena = _vidaAlienigena;
    }

    int getVidaAlienigena() {
        return vidaAlienigena;
    }

    void setAtaqueAlienigena(int _ataqueAlienigena) {
        ataqueAlienigena = _ataqueAlienigena;
    }

    int getAtaqueAlienigena() {
        return ataqueAlienigena;
    }
#pragma endregion
};


/////////////////////////////////////////////
/////////Funciones fuera de clases///////////
////////////////////////////////////////////

//Funcion para atacar al alienigena con disparo
void DanioDisparoAlAlienigena(JugadorPrincipal& _astronauta, Alienigena& _alienigena) {
    if ((_alienigena.getVidaAlienigena() - _astronauta.danioDisparo) <= 0)
    {
        _alienigena.setVidaAlienigena(0);
    }
    else
    {
        _alienigena.setVidaAlienigena(_alienigena.getVidaAlienigena() - _astronauta.danioDisparo);
    }
}

//Funcion para atacar al alienigena con cuerpo a cuerpo
void DanioAtaqueCuerpoACuerpoAlAlienigena(JugadorPrincipal& _astronauta, Alienigena& _alienigena) {
    if ((_alienigena.getVidaAlienigena() - _astronauta.getDanioCuerpoACuerpo()) <= 0) {
        _alienigena.setVidaAlienigena(0);
    }
    else {
        _alienigena.setVidaAlienigena(_alienigena.getVidaAlienigena() - _astronauta.getDanioCuerpoACuerpo());
    }
}


// Funcion para saber si alien muere
bool AlienMuere(Alienigena& _alienigenaMuerto, JugadorPrincipal& _astronauta) {

    if (_alienigenaMuerto.getVidaAlienigena() <= 0) {
        cout << "\n¡El alienígena ha muerto por skill issue :(!\n";
        _astronauta.setProgresoInvestigacion(_astronauta.getProgresoInvestigacion() + 10);
		_astronauta.MostrarInventario();
		return true; // El alienígena ha muerto
    }
    else {
		return false; // El alienígena sigue vivo
    }

}

//Creamos funcion para seleccionar la accion que nuestro jugador hara para juntar puntos de investigacion 
void OpcionInteraccionSeleccionada(JugadorPrincipal& _astronauta, Alienigena& _alienigena) {
    int opcionSeleccionada;

    while (!AlienMuere(_alienigena, _astronauta)) {
        cout << "Selecciona cómo quieres interactuar contra el alienígena:\n\n";
        cout << "Opción 1: Disparar\nOpción 2: Atacar cuerpo a cuerpo\nOpción 3: Abrir Caja de Riesgo -10 Puntos de Investigacion\nOpcion 4: Mostrar Inventario\n";
        cout << "\n/////////////////////////////////////////  Selecciona una opción (1-4)  /////////////////////////////////////////" << endl;
        cin >> opcionSeleccionada;

        switch (opcionSeleccionada) {
        case 1:
            DanioDisparoAlAlienigena(_astronauta, _alienigena);
            CambiarColoraBlanco();
            cout << "\nHas decidido dispararle al alienígena, generándole 50 de daño.\n";
            cout << "Vida Alienígena: " << _alienigena.getVidaAlienigena() << " de vida\n";
            _astronauta.setMunicion(_astronauta.getMunicion() - 1);
            cout << "Municion Restante: " << _astronauta.getMunicion() << " de munición\n";
            break;

        case 2:
            DanioAtaqueCuerpoACuerpoAlAlienigena(_astronauta, _alienigena);
            CambiarColoraAmarillo();
            cout << "\nHas decidido atacar cuerpo a cuerpo al alienígena, generándole 20 de daño.\n";
            cout << "Vida Alienígena: " << _alienigena.getVidaAlienigena() << " de vida\n";
            break;

        case 3:
            if (_astronauta.getProgresoInvestigacion() < 10) {
                cout << "No tienes suficientes puntos de investigación para abrir la Caja de Riesgo.\n";
                break;
            }
            _astronauta.setProgresoInvestigacion(_astronauta.getProgresoInvestigacion() - 10);
            CambiarColorPurpura();
            cout << "\nHas decidido abrir la Caja de Riesgo.\n";
            _astronauta.CajaDeRiesgoUnion();
            break;

        case 4:
            cout << "\nHas decidido revisar tu inventario.\n";
            _astronauta.MostrarInventario();
            break;

        default:
            cout << "La opción que escogiste no es válida, por favor escoge una opción válida.\n";
            break;
        }
    }

    
}


// ============================
// Historia principal del juego
// ============================
void HistoriaPrincipal(JugadorPrincipal& _astronauta, Alienigena& _alienigena) {
    cout << "BIENVENIDO A SPACE ROCKS\n\n";
    cout << "Introduce tu nombre: ";
    getline(cin, _astronauta.nombreJugador);
	CambiarColorVerde();
    cout << "Bienvenido a bordo " << _astronauta.nombreJugador << "\n";
    LimpiarPantalla();
    cout << "Has llegado al espacio despues de 9 largos meses de viaje del planeta Tierra al planeta Marte.\n";
    cout << "Tu mision es investigar los minerales de ese planeta para poder extraerlos y llevarlos de vuelta a la Tierra.\n";
    cout << "Sin embargo te has topado con vida alienigena que has visto a lo lejos, aqui empieza tu peligrosa aventura.\n";
    LimpiarPantalla();
    _astronauta.HistoriaElegida();
    cout << "Has decidido seguir a los alienigenas, sin embargo no sabes que te espera en el tunel subterraneo.\n";
    LimpiarPantalla();
    cout << "Has llegado a donde estaban los alienigenas, te encuentras de espalda a un solo alienigena revisando el terreno" << endl;
	OpcionInteraccionSeleccionada(_astronauta, _alienigena);
	

}

// ============================
// Función principal
// ============================
int main() {

	// Configuración de la localización para permitir caracteres especiales
    setlocale(LC_ALL, "");


    JugadorPrincipal astronauta;
    Alienigena alienigena;
    
	HistoriaPrincipal(astronauta, alienigena);
	
	

}