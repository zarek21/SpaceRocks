#include <iostream> // para std::cin y std::getline
#include <cstdlib> //Para system("cls") y system("pause")
#include <ctime> // Para usar srand y rand
#include <string>   // Para usar string
#include <thread>   // Necesario para sleep
#include <chrono>   // Necesario para manipular el tiempo sin problemas 
#include <locale> //Para usar � y acentos en el texto
#include <windows.h> // Para usar Sleep en Windows
#include <limits> //Para limpiar e buffer (BY CHATGPT)

//Nomenclatura
//Variables = camelCase ( ejemplo: nombreJugador, progresoInvestigacion)
//Funciones = PascalCase (ejemplo: CambiarColoraRojo, MostrarEstadisticasAlienigena)
//Gets y Sets = camelCase (ejemplo: getMunicion, setMunicion)
//Clases = PascalCase (ejemplo: JugadorPrincipal, Alienigena)
//Parametros = camelCase (ejemplo: _astronauta, _alienigena)

using namespace std; // Ya se la saben nms jaja (SALUDITOS PANAS)

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////FUNCIONES GLOBALES/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Nave ASCII
void NaveASCII() 
{
	cout << "     /\\\n";
	cout << "    /  \\\n";
	cout << "   /____\\\n";
	cout << "  |      |\n";
	cout << "  |  []  |\n";
	cout << "  |______|\n";
	cout << " /        \\\n";
	cout << "/__________\\\n\n";
}

//Carta con codigo ASCII
void CartaASCII()
{
	cout << "  _______________________\n";
	cout << " /                       \\\n";
	cout << "|  C�digo de arranque:   |\n";
	cout << "|  184419702002          |\n";
	cout << " \\_______________________/\n\n";
}

//Alien�gena ASCII
void AlienigenaASCII() 
{
    cout << R"(

           .-""""-.
         .'        '.
        / _   __   _ \
       | / \ |__| / \ |
       || o | __ | o ||
       |\__/      \__/|
        \    /\  /\   /
         '.  \/\/  .'
           '-.__.-'

       Un ser de otro mundo te observa...
       �Amigo o enemigo?

    )" << endl;

}

//Astronauta ASCII
void AstronautaASCII()
{
    cout << R"(
       .-.
      /___\
      |0 0|
     |  ^  |
     | '-' |
     +-----+
    /       \
   |         |
  /| |     | |\
 /_|_|_____|_|_\
   | |     | |
   |_|     |_|
  /__\     /__\
    )";
}

//CODIGO ASCII MADE BY CHATGPT

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

void CambiarColoraRojo() {
	system("color C0");
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


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////CLASES/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


// Creamos la clase con las estadisticas de nuestro jugador
class JugadorPrincipal {
public:
    string nombreJugador;
    int progresoInvestigacion;
    int oxigeno;
    int municion;
    int danioDisparo = 50;
    int danioCuerpoACuerpo = 20;

    // Constructor de nuestro jugador para establecer sus estad�sticas
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
        if (_municion <= 0)
        {
            municion = 0; // Si la munici�n es menor a 0, se establece en 0
            CambiaColorRojo();
            cout << "Te has quedado sin balas, has perdido ya que una orda de alienigenas te han matado ya que tus pu�os no fueron suficiente ante tal fuerza.\n";
            exit(0); // Termina el juego si la munici�n es menor o igual a 0
        }
        else
        {
            municion = _municion; // Si la munici�n es mayor a 0, se establece el valor
        }
    }

    int getMunicion() {
        return municion;
    }

    void setOxigeno(int _oxigeno) {
        if (_oxigeno <= 0) {
            oxigeno = 0;
		} // Si el ox�geno es menor o igual a 0, se establece en 0
        else {
            oxigeno = _oxigeno;
        }
    }

    int getOxigeno() {
        return oxigeno;
    }



    void setProgresoInvestigacion(int _progresoInvestigacion)
    {
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
    // Funcion para aleatorizar entre dos n�meros
    int AleatorizarEstadisticas(int _minimo, int _maximo) {
        return _minimo + rand() % (_maximo - _minimo + 1);
    }

    // Funcion para iniciar semilla de aleatoriedad
    void SemillaRandom() {
		srand(static_cast<unsigned int>(time(0))); // Inicia la semilla de aleatoriedad con el tiempo actual
    }
#pragma endregion

    // Opcion narrativa del jugador
    void HistoriaElegida()
    {
        string opcionHistoriaElegida;

        do {
            cout << "Ahora elige c�mo quieres afrontar a los alien�genas:\n\n";
            cout << "1. Atacar\n2. Contactar con ellos\n3. Tengo miedo, ya me quiero ir\n";
            cout << "\n/////////////////////////////////////////  Selecciona una opci�n (1-3)  ///////////////////////////////////////////////\n";
            cout << "\nOpci�n elegida: ";
            getline(cin, opcionHistoriaElegida);  // Usamos getline para aceptar cualquier entrada

            if (opcionHistoriaElegida == "1") {
                CambiaColorRojo();
                cout << "\nHas decidido atacar a los alien�genas, sin embargo al estar cerca de ellos, ellos ya se han ido,\npero logras ver que se meten a un t�nel subterr�neo y decides seguirlos.\n";
                LimpiarPantalla();
                break;

            }
            else if (opcionHistoriaElegida == "2") {
                CambiarColorPurpura();
                cout << "\nHas decidido contactar con ellos, sin embargo tu IA espacial no logra decodificar su idioma,\npero logras ver que se meten a un t�nel subterr�neo y decides seguirlos.\n";
                LimpiarPantalla();
                break;

            }
            else if (opcionHistoriaElegida == "3") {
                CambiarColorCafe();
                cout << "\nHas decidido no seguirlos despu�s de haberte cagado encima por lo que comunicas a la Tierra tu inmediata extracci�n,\nsiendo conocido como el astronauta m�s cobarde de la galaxia.\n";
                exit(0);  // Termina el juego

            }
            else {
                cout << "\nOpci�n no v�lida. Por favor, elige una opci�n entre 1 y 3.\n";
                LimpiarPantalla();
            }

        } while (true);
    }


    // Funci�n para imprimir estad�sticas del personaje
    void MostrarInventario() 
    {
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
        case 1: setOxigeno(oxigeno + 100);
            cout << "Has ganado 100 de oxigeno, ahora tienes: " << oxigeno << " de oxigeno";
            break;
        case 2: setOxigeno(oxigeno - 20);
            cout << "Has perdido 20 de oxigeno, ahora tienes: " << oxigeno << " de oxigeno";
            break;
        case 3: setMunicion(municion + 6);
            cout << "Has ganado 6 de municion, ahora tienes: " << municion << " de municion";
            break;
        case 4: setMunicion(municion - 2);
            cout << "Has perdido 2 de municion, ahora tienes: " << municion << " de municion";
            break;
        }
        cout << "\n\n";
        system("pause");
        system("cls");
    }
};



// Clase para el enemigo alien�gena
class Alienigena {
public:
    string nombreAlienigena;
    int vidaAlienigena;
    int ataqueAlienigena;

    //Constructor Alienigena
    Alienigena() 
    {
        nombreAlienigena = "Alienigena";
        vidaAlienigena = 100;
        ataqueAlienigena = 20;
    }


    void MostrarEstadisticasAlienigena() {
        cout << "Enemigo: " << nombreAlienigena << endl;
        cout << "Vida: " << vidaAlienigena << endl;
        cout << "Ataque: " << ataqueAlienigena << "\n\n";
    }

    // Funciones para establecer y obtener las estad�sticas del alien�gena
#pragma region SeccionesGettersySettersAlienigena
    void setVidaAlienigena(int _vidaAlienigena) {
        if (_vidaAlienigena < 0) {
            vidaAlienigena = 0;
        }
        else {
            vidaAlienigena = _vidaAlienigena;
        }
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







//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////FUNCIONES FUERA DE CLASES///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Funcion para saber si el jugador muere
bool JugadorMuere(JugadorPrincipal& _jugadorMuerto, Alienigena& _alienigena) 
{
    if (_jugadorMuerto.getOxigeno() <= 0) 
    {
		CambiaColorRojo();
		cout << "\n�Has muerto!\n";
		cout << "Progreso de investigaci�n: " << _jugadorMuerto.getProgresoInvestigacion() << "\n";
        exit(0);
		
	}
	else
	{
		return false; // El jugador sigue vivo
    
    }
}



// Funcion para saber si alien muere y sumar puntos de progreso 
bool AlienMuere(Alienigena& _alienigenaMuerto, JugadorPrincipal& _astronauta) {

    if (_alienigenaMuerto.getVidaAlienigena() <= 0) {
        cout << "\n�El alien�gena ha muerto por skill issue :(!\n";
        
        _astronauta.setProgresoInvestigacion(_astronauta.getProgresoInvestigacion() + 20);
        return true; // El alien�gena ha muerto
    }
    else 
    {
        return false; // El alien�gena sigue vivo
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////SISTEMA DE COMBATE/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Creamos funcion Disparar Jugador
void Disparar(JugadorPrincipal& _astronauta, Alienigena& _alienigena)
{
    _alienigena.setVidaAlienigena(_alienigena.getVidaAlienigena() - _astronauta.danioDisparo); // Hacemos la operacion
    cout << "\nHas decidido dispararle al alien�gena, gener�ndole 50 de da�o.\n";
    cout << "Vida Alien�gena: " << _alienigena.getVidaAlienigena() << " de vida\n";
    _astronauta.setMunicion(_astronauta.getMunicion() - 1);
    cout << "Municion Restante: " << _astronauta.getMunicion() << " de munici�n\n";


}

//Creamos funcion AtaqueCuerpoACuerpo Jugador
void AtaqueCuerpoACuerpo(JugadorPrincipal& _astronauta, Alienigena& _alienigena)
{
    _alienigena.setVidaAlienigena(_alienigena.getVidaAlienigena() - _astronauta.getDanioCuerpoACuerpo()); // Hacemos la operacion
    cout << "\nHas decidido atacar cuerpo a cuerpo al alien�gena, gener�ndole 20 de da�o.\n";
    cout << "Vida Alien�gena: " << _alienigena.getVidaAlienigena() << " de vida\n";

}

//Creamos funcion para que el alienigena ataque al jugador
void AtaqueAlienigena(JugadorPrincipal& _astronauta, Alienigena& _alienigena)
{
    _astronauta.setOxigeno(_astronauta.getOxigeno() - _alienigena.getAtaqueAlienigena()); // Hacemos la operacion
    cout << "\nEl alien�gena te ha atacado, gener�ndote " << _alienigena.getAtaqueAlienigena() << " de da�o.\n";
    cout << "Oxigeno Restante: " << _astronauta.getOxigeno() << " de ox�geno\n";
}



//Creamos funcion para seleccionar la accion que nuestro jugador hara para juntar puntos de investigacion 
void OpcionInteraccionSeleccionada(JugadorPrincipal& _astronauta, Alienigena& _alienigena) {
    while (!AlienMuere(_alienigena, _astronauta) && !JugadorMuere(_astronauta, _alienigena)) {
        cout << "Selecciona c�mo quieres interactuar contra el alien�gena:\n\n";
        cout << "Opci�n 1: Disparar\nOpci�n 2: Atacar cuerpo a cuerpo\nOpci�n 3: Abrir Caja de Riesgo (-10 Puntos de Investigaci�n)\nOpci�n 4: Mostrar Inventario\n";
        cout << "\n//////////////////////////////////  Selecciona una opci�n (1-4)  //////////////////////////////////////////////////////\n";
        cout << "\nOpci�n seleccionada: ";

        string opcionSeleccionada;
        getline(cin, opcionSeleccionada); // Acepta cualquier entrada, incluso con espacios

        if (opcionSeleccionada == "1") 
        {
            Disparar(_astronauta, _alienigena);
            if (!AlienMuere(_alienigena, _astronauta)) 
            {
                AtaqueAlienigena(_astronauta, _alienigena);
            }
            CambiarColoraBlanco();
            LimpiarPantalla();
        }
        else if (opcionSeleccionada == "2") {
            AtaqueCuerpoACuerpo(_astronauta, _alienigena);
            if (!AlienMuere(_alienigena, _astronauta)) {
                AtaqueAlienigena(_astronauta, _alienigena);
            }
            CambiarColoraAmarillo();
            LimpiarPantalla();
        }
        else if (opcionSeleccionada == "3") {
            if (_astronauta.getProgresoInvestigacion() < 10) 
			{
				CambiaColorRojo();
                LimpiarPantalla();
                cout << "No tienes suficientes puntos de investigaci�n para abrir la Caja de Riesgo.\n";
            }
            else 
            {
                _astronauta.setProgresoInvestigacion(_astronauta.getProgresoInvestigacion() - 10);
                CambiarColorPurpura();
                cout << "\nHas decidido abrir la Caja de Riesgo.\n";
                _astronauta.CajaDeRiesgoUnion();
                LimpiarPantalla();
            }

        }
        else if (opcionSeleccionada == "4") 
        {
            CambiarColorPurpura();
            cout << "\nHas decidido revisar tu inventario.\n";
            _astronauta.MostrarInventario();
            LimpiarPantalla();

        }
        else 
        {
            CambiaColorRojo();
            cout << "\nLa opci�n que escogiste no es v�lida. Por favor, escoge una opci�n del 1 al 4.\n";
            LimpiarPantalla();
        }
    }
}


void QuedaPocoOxigeno(JugadorPrincipal& _astronauta, Alienigena& _alienigena)
{
    string opcionElegida;

    do {
        cout << "\nTe queda muy poco ox�geno. Debes decidir qu� hacer:\n";
        cout << "1. Seguir avanzando\n";
        cout << "2. Volver a la nave espacial (-10 progreso de investigaci�n)\n";
        cout << "\nSelecciona una opci�n (1 o 2): ";
        getline(cin, opcionElegida);  

        if (opcionElegida == "1") 
        {
			CambiaColorRojo();
            cout << "\nHas decidido seguir avanzando, sin embargo, te has quedado sin ox�geno y has muerto.\n";
            _astronauta.setOxigeno(0); 
			JugadorMuere(_astronauta, _alienigena); // Llama a la funci�n para verificar si el jugador muere
        }
        else if (opcionElegida == "2") 
        {
            if (_astronauta.getProgresoInvestigacion() < 10) 
            {
                CambiaColorRojo();
                cout << "No tienes suficientes puntos de investigaci�n para volver a la nave espacial.\n";
            }
            else 
            {
                CambiarColorVerde();
                _astronauta.setProgresoInvestigacion(_astronauta.getProgresoInvestigacion() - 10);
                cout << "\nHas decidido volver a la nave espacial para llenar ox�geno.\n";
                _astronauta.setOxigeno(100); 
                cout << "Ahora tienes: " << _astronauta.getOxigeno() << " de ox�geno\n";
            }

        }
        else 
        {
            CambiaColorRojo();
            cout << "\nLa opci�n que has seleccionado no es v�lida. Por favor selecciona 1 o 2.\n";
            LimpiarPantalla();
        }

    } while (opcionElegida != "1" && opcionElegida != "2");
}


void ArmaSeleccionada(JugadorPrincipal& _astronauta)
{
    string opcionArma;

    do {
        cout << "\nSelecciona tu arma:\n";
        cout << "1. Arma de plasma\n";
        cout << "2. Mazo de gravedad\n";
        cout << "Opci�n: ";
        getline(cin, opcionArma);  

        if (opcionArma == "1") {
            CambiarColorVerde();
            cout << "\nHas seleccionado el arma de plasma, esta arma es muy potente y te ayudar� a derrotar al jefe alien�gena.\n";
        }
        else if (opcionArma == "2") {
            CambiarColoraAmarillo();
            cout << "\nHas seleccionado el mazo de gravedad, este arma es muy potente y te ayudar� a derrotar al jefe alien�gena.\n";
        }
        else {
            CambiarColoraRojo();
            cout << "\nLa opci�n que has seleccionado no es v�lida. Por favor, selecciona una opci�n v�lida.\n";
            LimpiarPantalla();
        }

    } while (opcionArma != "1" && opcionArma != "2");
}


//Funcion para mostrar cuando matemos al alien final
void MatarAlienJefe()
{
    string opcionElegida;

    do {
        cout << "\n�C�mo deseas matar al jefe final?\n";
        cout << "1. Exterminarlo con un golpe final a melee\n";
        cout << "2. Explotarlo con un �ltimo ataque de tu arma\n";
        cout << "Elige una opci�n (1 o 2): ";
        getline(cin, opcionElegida);

        if (opcionElegida == "1") {
            CambiarColoraRojo();
            cout << "Has matado al jefe final de un �ltimo puuuuh taso\n";
        }
        else if (opcionElegida == "2") {
			CambiarColoraRojo();
            cout << "Has matado al jefe final de manera brutal.\nYa no era necesaria tanta fuerza, eres medio psycho.\n";
        }
        else {
			CambiaColorRojo();
            cout << "Opci�n no v�lida. Intenta de nuevo.\n";
            LimpiarPantalla();
        }

    } while (opcionElegida != "1" && opcionElegida != "2");
}


// Funcion para obtener el codigo de arranque del vehiculo alienigena
void CodigoArranqueVehiculoAlienigena()
{
    string opcionCodigo;

    do {
        cout << "1. Abrir carta con c�digo\n2. No abrir\n> ";
        getline(cin, opcionCodigo);

        if (opcionCodigo == "1") 
        {
			CambiarColorVerde();
			CartaASCII();
        }
        else if (opcionCodigo == "2") 
        {
            CambiarColoraRojo();
            cout << "No has abierto la carta, por lo que no sabes el c�digo y no puedes arrancar el veh�culo alien�gena.\n";
            cout << "Has muerto por no poder arrancar el veh�culo alien�gena.\n";
            exit(0); // Termina el juego
        }
        else 
        {
			CambiarColoraRojo();
            cout << "La opci�n que has seleccionado no es v�lida, por favor selecciona una opci�n v�lida.\n";
            LimpiarPantalla();
        }

    } while (opcionCodigo != "1" && opcionCodigo != "2");
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////HISTORIA PRINCIPAL/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void HistoriaPrincipal(JugadorPrincipal& _astronauta, Alienigena& _alienigena)
{
    string opcionElegida;
    cout << "BIENVENIDO A SPACE ROCKS\n\n";
    cout << "Introduce tu nombre: ";
    getline(cin, _astronauta.nombreJugador); 
    CambiarColorVerde();
    cout << "Bienvenido a bordo " << _astronauta.nombreJugador << "\n";
    NaveASCII();
    LimpiarPantalla();
    cout << "Has llegado al espacio despues de 9 largos meses de viaje del planeta Tierra al planeta Marte.\n";
    LimpiarPantalla();
    cout << "Tu mision es investigar los minerales de ese planeta para poder extraerlos y llevarlos de vuelta a la Tierra.\n";
    cout << "Sin embargo te has topado con vida alienigena que has visto a lo lejos, aqui empieza tu peligrosa aventura.\n";
	AlienigenaASCII();
    LimpiarPantalla();
    _astronauta.HistoriaElegida();
    cout << "Has decidido seguir a los alienigenas, sin embargo no sabes que te espera en el tunel subterraneo.\n";
    LimpiarPantalla();
    cout << "Has llegado a donde estaban los alienigenas, te encuentras de espalda a un solo alienigena revisando el terreno" << endl;
    OpcionInteraccionSeleccionada(_astronauta, _alienigena); 
	LimpiarPantalla();
    cout << "Has conseguido derrotar al alieningena y continuas tu camino en el terreno enemigo" << endl;
    LimpiarPantalla();
    _astronauta.setOxigeno(_astronauta.getOxigeno()-70);
    JugadorMuere(_astronauta, _alienigena);
    cout << "\nSin embargo otro alienigena te dispara a lo lejos da�ando tu tanque de oxigeno, quitandote 70 de oxigeno";
	CambiarColoraRojo();
	cout << "\n\nAhora tienes: " << _astronauta.getOxigeno() << " de oxigeno\n";
    LimpiarPantalla();
	QuedaPocoOxigeno(_astronauta, _alienigena);
    LimpiarPantalla();
    cout << "Decides tomar tu nave y cambiar de posicion\nya que el alienigena que te ha disparado ha avisado de tu presencia";
	LimpiarPantalla();
	cout << "Te has posicionado en una monta�a desde la cual puedes ver el tunel de la base alienigena\n";
    LimpiarPantalla();
    cout << "Quedas observando desde la altura el comportamiento enemigo" << endl;
    LimpiarPantalla();
	cout << "Ves que hay un alienigena que parece ser el jefe de la base alienigena, \neste alienigena parece tener una gran fuerza y poder.\n";
    LimpiarPantalla();
	cout << "Decides que para obtener informacion de la base alienigena debes derrotar a este alienigena.\n";
    LimpiarPantalla();
	cout << "Debes decidir que camino tomar para tomarlo desprevenido\ny poder terminar con el para obtener la informacion necesaria" << endl;
    LimpiarPantalla();
	cout << "LLegas a un cruce de caminos, donde puedes ir por la derecha o por la izquierda\n";
	cout << "1. Ir por la derecha\n2. Ir por la izquierda\n";
    getline(cin, opcionElegida);
	cout << "Has decidido el camino a seguir, sin embargo no sabes que te espera en el camino.\n";
    LimpiarPantalla();
	cout << "En el camino te encuentras dos armas alienigenas\nDebes seleccionar una de las dos armas para poder enfrentarte al jefe alienigena\n";
	cout << "Arma de plasma\nMazo de gravedad\n";
	ArmaSeleccionada(_astronauta);
	LimpiarPantalla();
	cout << "Continuas tu camino con tu arma seleccionada\n";
    LimpiarPantalla();
	cout << "Llegas a la base alienigena y te encuentras con el jefe alienigena\n";
	cout << "El jefe alienigena te mira y dice\n Hasta aqui llegaste mi perro, no podras detenerme\n";
    LimpiarPantalla();
	cout << "El jefe alien te suelta un puuuuuh taso y te baja 70 de oxigeno\n";
	CambiaColorRojo();
	_astronauta.setOxigeno(_astronauta.getOxigeno() -70);
	cout << "Ahora tienes: " << _astronauta.getOxigeno() << " de oxigeno\n";
	LimpiarPantalla();
	cout << "Ahora tu lo atacas con el arma que has seleccionado\n";
	CambiarColorVerde();
    LimpiarPantalla();
	cout << "El jefe alienigena ha recibido 480 de da�o, sin embargo no ha muerto\n";
	cout << "Vida del jefe alienigena\n20 de vida";
    LimpiarPantalla();
    cout << "El jefe alienigena te ataca, pero logras esquivarlo papi, que buenos reflejos.\n";
    CambiarColorVerde();
    LimpiarPantalla();
    cout << "Selecciona como deseas terminar al jefe alien";
    MatarAlienJefe();
    LimpiarPantalla();
    cout << "Has acabado con el jefe final\nsumando asi los puntos de investigacion necesarios" << endl;
    _astronauta.setProgresoInvestigacion(_astronauta.getOxigeno() + 100);
    _astronauta.MostrarInventario();
    LimpiarPantalla();
    cout << "Ahora tienes que escapar del planeta y regresar a Tierra" << endl;
    LimpiarPantalla();
    cout << "Decides tomar un vehiculo alienigena  " << endl;
	cout << "Sin embargo al subir te pide un codigo para arrancar el vehiculo" << endl;
    LimpiarPantalla();
	cout << "El  codigo esta escrito en un papel que tienes que buscar en el cuerpo del jefe alien\n";
	cout << "Sin embargo un alien intenta evitar que lo tomes" << endl;
	OpcionInteraccionSeleccionada(_astronauta, _alienigena);
	LimpiarPantalla();
	cout << "Has matado al alienigena y has conseguido el codigo\n";
	CodigoArranqueVehiculoAlienigena();
    LimpiarPantalla();
	cout << "Introduce el codigo para arrancar el vehiculo alienigena: ";
	string codigoVehiculo;
    getline(cin,codigoVehiculo);

	// Pedimos al usuario que introduzca el c�digo del veh�culo alien�gena
	if (codigoVehiculo == "184419702002") 
    {
		CambiarColorVerde();
		cout << "Veh�culo alien�gena arrancado correctamente. �Felicidades, has completado la misi�n!\n";
		cout << "Has regresado a la Tierra con �xito y has sido reconocido como un h�roe.\n";
	}
	else 
    {
		CambiaColorRojo();
		cout << "C�digo incorrecto. El veh�culo no puede arrancar. Has muerto en el intento.\n";
		exit(0); // Termina el juego si el c�digo es incorrecto
	}
	cout << "Gracias por jugar Space Rocks, esperamos que hayas disfrutado de la aventura.\n";
	cout << "Hasta la proxima!\n";
	AstronautaASCII();
	exit(0); // Termina el juego al finalizar la historia

}


///////////////////////////////////////////////////////////////////////////////////////////// MAIN /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


int main() {
    // Configuraci�n de la localizaci�n para permitir caracteres especiales
    setlocale(LC_ALL, "");

	JugadorPrincipal _astronauta; // Creamos un objeto de la clase JugadorPrincipal
	Alienigena _alienigena; // Creamos un objeto de la clase Alienigena
	HistoriaPrincipal(_astronauta, _alienigena); // Llamamos a la funci�n principal de la historia
	
	return 0; 
}