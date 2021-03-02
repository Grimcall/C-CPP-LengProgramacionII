///-----------------------------------------------------------------
///
/// @file      GRUPO3-ProyectoT9FINALFrm.cpp
/// @author    UNKNOWN
/// Created:   08/01/2021 07:18:49 p.m.
/// @section   REQUIERE LIBRERIAS DE WXWIDGETS.
///            GRUPO3_ProyectoT9FINALFrm class implementation
///
///------------------------------------------------------------------
/* CUARTO, PROYECTO FINAL; INTERFAZ GRÁFICA
	*/

#include "GRUPO3-ProyectoT9FINALFrm.h"


//----------------------------------------------------------------------------
// GRUPO3_ProyectoT9FINALFrm
//----------------------------------------------------------------------------

BEGIN_EVENT_TABLE(GRUPO3_ProyectoT9FINALFrm,wxFrame)

	EVT_CLOSE(GRUPO3_ProyectoT9FINALFrm::OnClose)
	EVT_ACTIVATE(GRUPO3_ProyectoT9FINALFrm::GRUPO3_ProyectoT9FINALFrmActivate)
	EVT_MENU(ID_MENU_MEMBRETE, GRUPO3_ProyectoT9FINALFrm::OnSobreMembrete)
	EVT_UPDATE_UI(ID_MENU_MEMBRETE, GRUPO3_ProyectoT9FINALFrm::OnUpdateUISobreMembrete)
	EVT_BUTTON(ID_CARGARARCHIVOS,GRUPO3_ProyectoT9FINALFrm::CargarPalabrasBoton)
	EVT_BUTTON(ID_T9CERO_ESPACIO,GRUPO3_ProyectoT9FINALFrm::t9CERO_ESPACIOClick)
	EVT_BUTTON(ID_T9NUEVE_WXYZ,GRUPO3_ProyectoT9FINALFrm::t9NUEVE_WXYZClick)
	EVT_BUTTON(ID_T9OCHO_TUV,GRUPO3_ProyectoT9FINALFrm::t9OCHO_TUVClick)
	EVT_BUTTON(ID_T9SIETE_PQRS,GRUPO3_ProyectoT9FINALFrm::t9SIETE_PQRSClick)
	EVT_BUTTON(ID_T9SEIS_MNO,GRUPO3_ProyectoT9FINALFrm::t9SEIS_MNOClick)
	EVT_BUTTON(ID_T9CINCO_JKL,GRUPO3_ProyectoT9FINALFrm::t9CINCO_JKLClick)
	EVT_BUTTON(ID_T9CUATRO_GHI,GRUPO3_ProyectoT9FINALFrm::t9CUATRO_GHIClick)
	EVT_BUTTON(ID_T9TRES_DEF,GRUPO3_ProyectoT9FINALFrm::t9TRES_DEFClick)
	EVT_BUTTON(ID_T9DOS_ABC,GRUPO3_ProyectoT9FINALFrm::t9DOS_ABCClick)
	EVT_BUTTON(ID_T9UNO_NULL,GRUPO3_ProyectoT9FINALFrm::t9UNO_NULLClick)

	EVT_TEXT(ID_SALIDAT9,GRUPO3_ProyectoT9FINALFrm::WxEdit1Updated)

	EVT_TEXT(ID_ENTRADAT9,GRUPO3_ProyectoT9FINALFrm::ENTRADAT9Updated)
	EVT_LISTBOX(ID_LISTASUGERENCIAS,GRUPO3_ProyectoT9FINALFrm::listaSugerenciasSelected)
	EVT_LISTBOX_DCLICK(ID_LISTASUGERENCIAS,GRUPO3_ProyectoT9FINALFrm::listaSugerenciasDoubleClicked)
END_EVENT_TABLE()
////Event Table End

GRUPO3_ProyectoT9FINALFrm::GRUPO3_ProyectoT9FINALFrm(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &position, const wxSize& size, long style)
: wxFrame(parent, id, title, position, size, style)
{
	CreateGUIControls();
}

GRUPO3_ProyectoT9FINALFrm::~GRUPO3_ProyectoT9FINALFrm()
{
}

void GRUPO3_ProyectoT9FINALFrm::CreateGUIControls()
{
	//Gui ITEMS

	BarraDeEstado = new wxStatusBar(this, ID_BARRADEESTADO);

	wxArrayString arrayStringFor_listaSugerencias;
	listaSugerencias = new wxListBox(this, ID_LISTASUGERENCIAS, wxPoint(22, 83), wxSize(198, 230), arrayStringFor_listaSugerencias, wxLB_SINGLE);

	Sugerencias = new wxStaticText(this, ID_SUGERENCIAS, _("Sugerencias: "), wxPoint(24, 62), wxDefaultSize, 0, _("Sugerencias"));

	ENTRADAT9 = new wxTextCtrl(this, ID_ENTRADAT9, _("Entrada."), wxPoint(24, 35), wxSize(197, 19), wxTE_READONLY, wxDefaultValidator, _("ENTRADAT9"));
	ENTRADAT9->SetFont(wxFont(9, wxSWISS, wxNORMAL, wxNORMAL, false, _("Times New Roman")));

	SALIDAT9 = new wxTextCtrl(this, ID_SALIDAT9, _("Salida."), wxPoint(260, 35), wxSize(226, 19), wxTE_READONLY, wxDefaultValidator, _("SALIDAT9"));

	t9UNO_NULL = new wxButton(this, ID_T9UNO_NULL, _("1\nLimpiar"), wxPoint(286, 84), wxSize(53, 55), 0, wxDefaultValidator, _("t9UNO_NULL"));

	t9DOS_ABC = new wxButton(this, ID_T9DOS_ABC, _("2\nABC"), wxPoint(349, 84), wxSize(53, 55), wxNO_BORDER, wxDefaultValidator, _("t9DOS_ABC"));

	t9TRES_DEF = new wxButton(this, ID_T9TRES_DEF, _("3\nDEF"), wxPoint(414, 84), wxSize(53, 55), 0, wxDefaultValidator, _("t9TRES_DEF"));

	t9CUATRO_GHI = new wxButton(this, ID_T9CUATRO_GHI, _("4\nGHI"), wxPoint(287, 149), wxSize(53, 55), 0, wxDefaultValidator, _("t9CUATRO_GHI"));

	t9CINCO_JKL = new wxButton(this, ID_T9CINCO_JKL, _("5\nJKL"), wxPoint(349, 149), wxSize(53, 55), 0, wxDefaultValidator, _("t9CINCO_JKL"));

	t9SEIS_MNO = new wxButton(this, ID_T9SEIS_MNO, _("6\nMNO"), wxPoint(414, 148), wxSize(53, 55), 0, wxDefaultValidator, _("t9SEIS_MNO"));

	t9SIETE_PQRS = new wxButton(this, ID_T9SIETE_PQRS, _("7\nPQRS"), wxPoint(287, 211), wxSize(53, 55), 0, wxDefaultValidator, _("t9SIETE_PQRS"));

	t9OCHO_TUV = new wxButton(this, ID_T9OCHO_TUV, _("8\nTUV"), wxPoint(349, 211), wxSize(53, 55), 0, wxDefaultValidator, _("t9OCHO_TUV"));

	t9NUEVE_WXYZ = new wxButton(this, ID_T9NUEVE_WXYZ, _("9\nWXYZ"), wxPoint(414, 211), wxSize(53, 55), 0, wxDefaultValidator, _("t9NUEVE_WXYZ"));

	t9CERO_ESPACIO = new wxButton(this, ID_T9CERO_ESPACIO, _("0\nEspacio"), wxPoint(351, 276), wxSize(53, 35), 0, wxDefaultValidator, _("t9CERO_ESPACIO"));

	IndicadorPalabras = new wxStaticText(this, ID_INDICADORPALABRAS, _(" "), wxPoint(23, 13), wxDefaultSize, 0, _("IndicadorPalabras"));

	CargarArchivos = new wxButton(this, ID_CARGARARCHIVOS, _("Iniciar Programa"), wxPoint(263, 7), wxSize(222, 23), 0, wxDefaultValidator, _("CargarArchivos"));

	TextoHint = new wxStaticText(this, ID_TEXTOHINT, _("Haga doble-click en un item dentro de la caja para seleccionarlo."), wxPoint(22, 315), wxDefaultSize, 0, _("TextoHint"));

	ArchivoNoEncontradoDialogo =  new wxMessageDialog(this, _("Se requiere de un archivo Diccionario.txt para correr este programa. Por favor local�zelo e intente de nuevo."), _("Diccionario.txt no encontrado."), wxOK | wxICON_ERROR | wxCENTRE);

	InicieElPrograma =  new wxMessageDialog(this, _("Necesita iniciar el programa pulsando el bot�n superior derecho antes de realizar cualquier cambio."), _("Inicie el programa!"), wxOK | wxICON_EXCLAMATION | wxCENTRE);

	Menu = new wxMenuBar();
	wxMenu *ID_MENU_SOBRE_Mnu_Obj = new wxMenu();
	ID_MENU_SOBRE_Mnu_Obj->Append(ID_MENU_MEMBRETE, _("&Membrete"), _(""), wxITEM_NORMAL);
	Menu->Append(ID_MENU_SOBRE_Mnu_Obj, _("&Sobre"));
	SetMenuBar(Menu);

	PopUpMembrete =  new wxMessageDialog(this, _("Integrantes: Diego Parra, Katherine Garc�a\n UNEFA-NPC, Ingenier�a de Sistemas 5TO Semestre."), _("Message box"), wxOK | wxICON_INFORMATION | wxCENTRE);

	SetStatusBar(BarraDeEstado);
	SetTitle(_("GRUPO3-ProyectoT9FINAL"));
	SetIcon(wxNullIcon);
	SetSize(8,8,519,417);
	Center();

	////GUI Items Creation End


}

void GRUPO3_ProyectoT9FINALFrm::OnClose(wxCloseEvent& event)
{
	Destroy();
}

/* GRUPO3_ProyectoT9FINALFrmActivate */
void GRUPO3_ProyectoT9FINALFrm::GRUPO3_ProyectoT9FINALFrmActivate(wxActivateEvent& event)
{

    wxTextFile archivoDiccionario;
    archivoDiccionario.Open("Diccionario.txt");

    int cuentaPalabras = 0;

    if(archivoDiccionario.IsOpened() == false){


        BarraDeEstado->SetLabel("�Diccionario.txt no encontrado! Recargue el programa e intente de nuevo.");
        Destroy();
        return;


        }else{

            BarraDeEstado->SetLabel("Diccionario.txt cargado exitosamente.");

                      wxString Texto;
                      Texto << ContarPalabras(archivoDiccionario) << " Palabras Cargadas.";

                      IndicadorPalabras->SetLabel(Texto);

        }
}

/* * WxEdit1Updated */
void GRUPO3_ProyectoT9FINALFrm::WxEdit1Updated(wxCommandEvent& event){}

/* * WxButton1Click */
void GRUPO3_ProyectoT9FINALFrm::WxButton1Click(wxCommandEvent& event){}

/* * listaSugerenciasSelected */
void GRUPO3_ProyectoT9FINALFrm::listaSugerenciasSelected(wxCommandEvent& event){}

/* * OnMenuSobre */
void GRUPO3_ProyectoT9FINALFrm::OnMenuSobre(wxCommandEvent& event){}

/* * OnUpdateUIMenuSobre */
void GRUPO3_ProyectoT9FINALFrm::OnUpdateUIMenuSobre(wxUpdateUIEvent& event){}

/* * OnSobreMembrete */
void GRUPO3_ProyectoT9FINALFrm::OnSobreMembrete(wxCommandEvent& event)
{
	this->PopUpMembrete->ShowModal();
}

/* * OnUpdateUISobreMembrete */
void GRUPO3_ProyectoT9FINALFrm::OnUpdateUISobreMembrete(wxUpdateUIEvent& event){}

/* * CargarPalabrasBoton */
void GRUPO3_ProyectoT9FINALFrm::CargarPalabrasBoton(wxCommandEvent& event)
{

    //Variables
    wxTextFile archivoDiccionario;
    archivoDiccionario.Open("Diccionario.txt");

    int x = ContarPalabras(archivoDiccionario);

//Direccionar memoria en base de la cantidad de palabras.
	DiccionarioSTR.Clear();
	DiccionarioCOD.Clear();

    DiccionarioSTR.Alloc(x);
	DiccionarioCOD.Alloc(x);
	 //Variables


   AlgoritmoBruto(x, DiccionarioSTR);

    CargarArchivos->SetLabel("Iniciado. Empiece a escribir.");
    CargarArchivos->Enable(false);

    ENTRADAT9->Clear();
    SALIDAT9->Clear();

    archivoDiccionario.Close();

}



//void AlgoritmoBruto.
void GRUPO3_ProyectoT9FINALFrm::AlgoritmoBruto(int CantidadPalabras, wxArrayString &DicciStr)
{

     //Variables
    int i, j = 0;

    wxTextFile archivoDiccionario;
    archivoDiccionario.Open("Diccionario.txt");

    wxString Temp, Codigo;
    //Variables FIN.


    //Ciclo para insertar palabras en arreglo.
   for(i = 0; i < CantidadPalabras; i++)
        {

        Temp = archivoDiccionario.GetLine(i);
        Temp.Lower();
        DicciStr.Insert(Temp, j);

        //Funcion que recibe un string y lo codifica.
        Codigo << ConstruirArregloInt(Temp);
        DiccionarioCOD.Insert(Codigo, j);

        j++;
        Codigo.Clear();
        }
     //Ciclo para insertar palabras en arreglo FIN.

    archivoDiccionario.Close();

}


// Contar Palabras
int GRUPO3_ProyectoT9FINALFrm::ContarPalabras(wxTextFile &p)
{
	int x;
    x = p.GetLineCount();
    return x;

}

/* * listaSugerenciasDoubleClicked */
void GRUPO3_ProyectoT9FINALFrm::listaSugerenciasDoubleClicked(wxCommandEvent& event)
{

    int Seleccion;
    Seleccion = listaSugerencias->GetSelection();

    wxString Temp = listaSugerencias->GetString(Seleccion);
    Temp<<" ";

    SALIDAT9->WriteText(Temp);// insert your code here
}

/* * t9UNO_NULLClick */
void GRUPO3_ProyectoT9FINALFrm::t9UNO_NULLClick(wxCommandEvent& event)
{
	if(ProgramaIniciado() == false)return;

    listaSugerencias->Clear();
    ENTRADAT9->Clear();
    SALIDAT9->Clear();
}

/* * ENTRADAT9Updated */
void GRUPO3_ProyectoT9FINALFrm::ENTRADAT9Updated(wxCommandEvent& event)
{

	//Variables INIT.
    wxString TipeoAuxiliar;
    TipeoAuxiliar<< ENTRADAT9->GetLineText(0);

	wxString CodigoAuxiliar;
	wxString Temp;

	int i;
	//Variables FIN.

	if(TipeoAuxiliar.IsNull() == true)return;

	listaSugerencias->Clear();
	for(i = 0; i < DiccionarioCOD.GetCount(); i++)
	{

    CodigoAuxiliar = DiccionarioCOD[i];

    if(CodigoAuxiliar.StartsWith(TipeoAuxiliar) == true)
                {
                Temp = DiccionarioSTR[i];
                listaSugerencias->Append(Temp);
                listaSugerencias->SetSelection(0);
                }


    }


 }

//ProgramaIniciado
bool GRUPO3_ProyectoT9FINALFrm::ProgramaIniciado()
{

 if(CargarArchivos->IsEnabled() == true){

                                    InicieElPrograma->ShowModal();
                                    return false;

                                     }
                                     return true;

}

/* * t9DOS_ABCClick */
void GRUPO3_ProyectoT9FINALFrm::t9DOS_ABCClick(wxCommandEvent& event)
{
		if(ProgramaIniciado() == false)return;

    wxString Temp = "2";

    ENTRADAT9->WriteText(Temp);

}

/* * t9TRES_DEFClick */
void GRUPO3_ProyectoT9FINALFrm::t9TRES_DEFClick(wxCommandEvent& event)
{
		if(ProgramaIniciado() == false)return;

    wxString Temp = "3";

    ENTRADAT9->WriteText(Temp);

}

/* * t9CUATRO_GHIClick */
void GRUPO3_ProyectoT9FINALFrm::t9CUATRO_GHIClick(wxCommandEvent& event)
{
	if(ProgramaIniciado() == false)return;

    wxString Temp = "4";

    ENTRADAT9->WriteText(Temp);

}

/* * t9CINCO_JKLClick */
void GRUPO3_ProyectoT9FINALFrm::t9CINCO_JKLClick(wxCommandEvent& event)
{
	if(ProgramaIniciado() == false)return;

    wxString Temp = "5";

    ENTRADAT9->WriteText(Temp);
}

/* * t9SEIS_MNOClick */
void GRUPO3_ProyectoT9FINALFrm::t9SEIS_MNOClick(wxCommandEvent& event)
{
		if(ProgramaIniciado() == false)return;

    wxString Temp = "6";

    ENTRADAT9->WriteText(Temp);// insert your code here
}

/* * t9SIETE_PQRSClick */
void GRUPO3_ProyectoT9FINALFrm::t9SIETE_PQRSClick(wxCommandEvent& event)
{
		if(ProgramaIniciado() == false)return;

    wxString Temp = "7";

    ENTRADAT9->WriteText(Temp);// insert your code here
}

/* * t9OCHO_TUVClick */
void GRUPO3_ProyectoT9FINALFrm::t9OCHO_TUVClick(wxCommandEvent& event)
{
		if(ProgramaIniciado() == false)return;

    wxString Temp = "8";

    ENTRADAT9->WriteText(Temp);
}

/* * t9NUEVE_WXYZClick */
void GRUPO3_ProyectoT9FINALFrm::t9NUEVE_WXYZClick(wxCommandEvent& event)
{
		if(ProgramaIniciado() == false)return;

    wxString Temp = "9";

    ENTRADAT9->WriteText(Temp);// insert your code here
}

/* * t9CERO_ESPACIOClick */
void GRUPO3_ProyectoT9FINALFrm::t9CERO_ESPACIOClick(wxCommandEvent& event)
{
		if(ProgramaIniciado() == false)return;

    ENTRADAT9->Clear();


}


int GRUPO3_ProyectoT9FINALFrm::ConstruirArregloInt(wxString Temporal)
{

int CodEntero = 0, CodigoFinal = 0, x;
 char CodCaracter = ' ';

 for(x = 0; x < Temporal.Len(); x++)
    {

    CodCaracter = Temporal.GetChar(x);


        switch(CodCaracter){

            case 'a': case 'b': case 'c':
                CodEntero += 2;
                break;

            case 'd': case 'e': case 'f':
                CodEntero += 3;
                break;

            case 'g': case 'h': case 'i':
                CodEntero += 4;
                break;

            case 'j': case 'k': case 'l':
                CodEntero += 5;
                break;

            case 'm': case 'n': case 'o':
                CodEntero += 6;
                break;

           case 'p': case 'q': case 'r': case 's':
                CodEntero += 7;
                break;

           case 't': case 'u': case 'v':
                CodEntero += 8;
                break;

           case 'w': case 'x': case 'y': case 'z':
                CodEntero += 9;
                break;
            default:;
                            }

        CodEntero = CodEntero*10;


    }

    CodigoFinal = CodEntero/10;
    return(CodigoFinal);

}



/* * WxListCtrl1BeginDrag */
void GRUPO3_ProyectoT9FINALFrm::WxListCtrl1BeginDrag(wxListEvent& event){}
