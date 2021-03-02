///-----------------------------------------------------------------
///
/// @file      GRUPO3-ProyectoT9FINALFrm.h
/// @author     UNKNOWN
/// Created:   08/01/2021 07:18:49 p.m.
/// @section   REQUIERE LIBRERIAS DE WXWIDGETS.
///            GRUPO3_ProyectoT9FINALFrm class declaration
///
///------------------------------------------------------------------

#ifndef __GRUPO3_PROYECTOT9FINALFRM_H__
#define __GRUPO3_PROYECTOT9FINALFRM_H__

#ifdef __BORLANDC__
	#pragma hdrstop
#endif

#ifndef WX_PRECOMP
	#include <wx/wx.h>
	#include <wx/frame.h>
#else
	#include <wx/wxprec.h>
#endif

////Header Include Start
#include <wx/menu.h>
#include <wx/msgdlg.h>
#include <wx/button.h>
#include <wx/textctrl.h>
#include <wx/stattext.h>
#include <wx/listbox.h>
#include <wx/statusbr.h>
////Header Include End

//Headers internos Init.
#include <wx/event.h>
#include <wx/app.h>
#include <wx/textentry.h>
#include <wx/string.h>
#include <wx/arrstr.h>
#include <wx/dynarray.h>
#include <wx/textfile.h>
#include <wx/unichar.h>
#include <wx/listctrl.h>
#include <string>
#include <iostream>
//Headers internos final.

////Dialog Style Start
#undef GRUPO3_ProyectoT9FINALFrm_STYLE
#define GRUPO3_ProyectoT9FINALFrm_STYLE wxCAPTION | wxSYSTEM_MENU | wxMINIMIZE_BOX | wxCLOSE_BOX
////Dialog Style End

class GRUPO3_ProyectoT9FINALFrm : public wxFrame
{
	private:
		DECLARE_EVENT_TABLE();

	public:
        //Funciones GUI FIN
		GRUPO3_ProyectoT9FINALFrm(wxWindow *parent, wxWindowID id = 1, const wxString &title = wxT("GRUPO3-ProyectoT9FINAL"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = GRUPO3_ProyectoT9FINALFrm_STYLE);
		virtual ~GRUPO3_ProyectoT9FINALFrm();
		void GRUPO3_ProyectoT9FINALFrmActivate(wxActivateEvent& event);
		void WxEdit1Updated(wxCommandEvent& event);
		void WxButton1Click(wxCommandEvent& event);
		void listaSugerenciasSelected(wxCommandEvent& event);
		void OnMenuSobre(wxCommandEvent& event);
		void OnUpdateUIMenuSobre(wxUpdateUIEvent& event);
		void OnSobreMembrete(wxCommandEvent& event);
		void OnUpdateUISobreMembrete(wxUpdateUIEvent& event);
		void CargarPalabrasBoton(wxCommandEvent& event);
	   //Funciones GUI FIN

        //Funciones Personalizadas
       	bool ProgramaIniciado();
        int ContarPalabras(wxTextFile &p);
        int ConstruirArregloInt(wxString Temporal);
        void AlgoritmoBruto(int CantidadPalabras, wxArrayString &DicciStr);
	    void listaSugerenciasDoubleClicked(wxCommandEvent& event);
		void t9UNO_NULLClick(wxCommandEvent& event);
		void ENTRADAT9Updated(wxCommandEvent& event);
        void t9DOS_ABCClick(wxCommandEvent& event);
		void t9TRES_DEFClick(wxCommandEvent& event);
		void t9CUATRO_GHIClick(wxCommandEvent& event);
		void t9CINCO_JKLClick(wxCommandEvent& event);
		void t9SEIS_MNOClick(wxCommandEvent& event);
		void t9SIETE_PQRSClick(wxCommandEvent& event);
		void t9OCHO_TUVClick(wxCommandEvent& event);
		void t9NUEVE_WXYZClick(wxCommandEvent& event);
		void t9CERO_ESPACIOClick(wxCommandEvent& event);

      	//Fin Funciones Personalizadas

        //Variables de Inter�s

         wxArrayString DiccionarioCOD;
         wxArrayString DiccionarioSTR;
		void WxListCtrl1BeginDrag(wxListEvent& event);
        //Fin Variables de Inter�s

	private:
	   //Control de eventos.
		wxMessageDialog *PopUpMembrete;
		wxMenuBar *Menu;
		wxMessageDialog *InicieElPrograma;
		wxMessageDialog *ArchivoNoEncontradoDialogo;
		wxStaticText *TextoHint;
		wxButton *CargarArchivos;
		wxStaticText *IndicadorPalabras;
		wxButton *t9CERO_ESPACIO;
		wxButton *t9NUEVE_WXYZ;
		wxButton *t9OCHO_TUV;
		wxButton *t9SIETE_PQRS;
		wxButton *t9SEIS_MNO;
		wxButton *t9CINCO_JKL;
		wxButton *t9CUATRO_GHI;
		wxButton *t9TRES_DEF;
		wxButton *t9DOS_ABC;
		wxButton *t9UNO_NULL;
		wxTextCtrl *SALIDAT9;
		wxTextCtrl *ENTRADAT9;
		wxStaticText *Sugerencias;
		wxListBox *listaSugerencias;
		wxStatusBar *BarraDeEstado;
		////Control de eventos.

	private:

		enum
		{
			////GUI Enum Control ID Start
			ID_MENU_SOBRE = 1021,
			ID_MENU_MEMBRETE = 1022,

			ID_TEXTOHINT = 1025,
			ID_CARGARARCHIVOS = 1024,
			ID_INDICADORPALABRAS = 1023,
			ID_T9CERO_ESPACIO = 1020,
			ID_T9NUEVE_WXYZ = 1019,
			ID_T9OCHO_TUV = 1018,
			ID_T9SIETE_PQRS = 1017,
			ID_T9SEIS_MNO = 1016,
			ID_T9CINCO_JKL = 1015,
			ID_T9CUATRO_GHI = 1014,
			ID_T9TRES_DEF = 1013,
			ID_T9DOS_ABC = 1012,
			ID_T9UNO_NULL = 1011,
			ID_SALIDAT9 = 1007,
			ID_ENTRADAT9 = 1006,
			ID_SUGERENCIAS = 1005,
			ID_LISTASUGERENCIAS = 1002,
			ID_BARRADEESTADO = 1001,
		    ID_DUMMY_VALUE_ //don't remove this value unless you have other enum values
		};

	private:
		void OnClose(wxCloseEvent& event);
		void CreateGUIControls();
};

#endif
