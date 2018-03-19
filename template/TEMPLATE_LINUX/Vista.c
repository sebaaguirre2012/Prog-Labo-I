#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Validaciones.h"
#include "ArrayList.h"
#include "Vista.h"
#include "Controlador.h"
#include "Cliente.h"

static void opcionAltaX();
static void opcionBajaX();
static void opcionModificacionX();
static void opcionListadoX();
static void opcionOrdenarX();

/********************************************************************/

static void opcionAltaCliente();
static void opcionBajaCliente();
static void opcionModificacionCliente();
static void opcionListadoCliente();
static void opcionOrdenarCliente();

/********************************************************************/

static int idiomaVista;

/********************************************************************/

int vista_init (int idioma)
{
    idiomaVista = idioma;
    return 0;
}

int vista_mostrarMenu()
{
    char buffer[10];
    int option=0;

    while(option != 6)
    {
        val_getInt(buffer, MENU_PPAL_ES, MENU_PPAL_ERROR_ES,2,5);
        option = atoi(buffer);

        switch(option)
        {
            case 1:
                opcionAltaCliente();
                break;
            case 2:
                opcionAltaX();
                break;
            case 3:
                opcionBajaX();
                break;
            case 4:
                opcionModificacionX();
                break;
            case 5:
                opcionOrdenarX();
                break;
        }
    }

    return 0;
}

void mostrarError(char * mensaje)
{

    printf("\n%s\n", mensaje);

}

/********************************************************************/

void vista_mostrarX(ArrayList* pListaSocios)
{

    printf("\nIMPRIMO LISTA DE ENTIDAD X\n");

}

static void opcionAltaX()
{
    char a[50];
    char b[50];
    char c[50];
    if(val_getString(a, "A? ", "Error",2,50) == 0 &&
       val_getString(b, "B? ", "Error",2,50) == 0 &&
       val_getInt(c, "C? ", "Error",2,50) == 0)
    {
        cont_altaX(a,b,atoi(c));
    }


}

static void opcionBajaX()
{
    char auxId[10];
    int id;

    if((val_getUnsignedInt(auxId,"Id a dar de baja" , "Error",2,10)==0))
    {
        id = atoi(auxId);
        cont_bajaX(id);
    }

}

static void opcionModificacionX()
{
    char auxId[10];
    int id;
    char a[50];
    char b[50];
    char c[50];

    if((val_getUnsignedInt(auxId,"Id a dar de baja" , "Error",2,10)==0))
    {
        id = atoi(auxId);
        if(val_getString(a, "A? ", "Error",2,50) == 0 &&
           val_getString(b, "B? ", "Error",2,50) == 0 &&
           val_getInt(c, "C? ", "Error",2,50) == 0)
        {
            cont_modificarX(id,a,b,atoi(c));
        }
    }


}

static void opcionListadoX()
{
    cont_listarX();
}

static void opcionOrdenarX()
{
    cont_ordenarX();
}

/********************************************************************/

void vista_mostrarCliente(ArrayList* pListaSocios)
{

    printf("\nIMPRIMO LISTA DE ENTIDAD X\n");

}

static void opcionAltaCliente()
{
    char nombre[50];
    char apellido[50];
    char dni[50];
    if(val_getString(nombre, "Nombre? ", "Error\n",2,50) == 0 &&
       val_getString(apellido, "Apellido? ", "Error\n",2,50) == 0 &&
       val_getInt(dni, "dni? ", "Error\n",2,50) == 0)
    {
        cont_altaCliente(nombre,apellido,atoi(dni));
    }
}

static void opcionBajaCliente()
{
    char auxId[10];
    int id;

    if((val_getUnsignedInt(auxId,"Id a dar de baja" , "Error",2,10)==0))
    {
        id = atoi(auxId);
        cont_bajaCliente(id);
    }

}

static void opcionModificacionCliente()
{
    char auxId[10];
    int id;
    char a[50];
    char b[50];
    char c[50];

    if((val_getUnsignedInt(auxId,"Id a dar de baja" , "Error",2,10)==0))
    {
        id = atoi(auxId);
        if(val_getString(a, "A? ", "Error",2,50) == 0 &&
           val_getString(b, "B? ", "Error",2,50) == 0 &&
           val_getInt(c, "C? ", "Error",2,50) == 0)
        {
            cont_modificarCliente(id,a,b,atoi(c));
        }
    }


}

static void opcionListadoCliente()
{
    cont_listarCliente();
}

static void opcionOrdenarCliente()
{
    cont_ordenarCliente();
}

/********************************************************************/

