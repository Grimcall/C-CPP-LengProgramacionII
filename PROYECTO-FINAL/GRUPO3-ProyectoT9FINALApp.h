//---------------------------------------------------------------------------
//
// Name:        GRUPO3-ProyectoT9FINALApp.h
// Author:      UNKNOWN
// Created:     08/01/2021 07:18:49 p.m.
// Description: REQUIERE LIBRERIAS DE WXWIDGETS.
//
//---------------------------------------------------------------------------

#ifndef __GRUPO3_PROYECTOT9FINALFRMApp_h__
#define __GRUPO3_PROYECTOT9FINALFRMApp_h__

#ifdef __BORLANDC__
	#pragma hdrstop
#endif

#ifndef WX_PRECOMP
	#include <wx/wx.h>
#else
	#include <wx/wxprec.h>
#endif

class GRUPO3_ProyectoT9FINALFrmApp : public wxApp
{
	public:
		bool OnInit();
		int OnExit();
};

#endif
