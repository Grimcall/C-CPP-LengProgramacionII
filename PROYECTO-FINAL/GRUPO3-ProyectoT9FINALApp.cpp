//---------------------------------------------------------------------------
//
// Name:        GRUPO3-ProyectoT9FINALApp.cpp
// Author:      Grimcall
// Created:     08/01/2021 07:18:49 p.m.
// Description: REQUIERE LIBRERIAS DE WXWIDGETS.
//
//---------------------------------------------------------------------------

#include "GRUPO3-ProyectoT9FINALApp.h"
#include "GRUPO3-ProyectoT9FINALFrm.h"

IMPLEMENT_APP(GRUPO3_ProyectoT9FINALFrmApp)

bool GRUPO3_ProyectoT9FINALFrmApp::OnInit()
{
    GRUPO3_ProyectoT9FINALFrm* frame = new GRUPO3_ProyectoT9FINALFrm(NULL);
    SetTopWindow(frame);
    frame->Show();
    return true;



}

int GRUPO3_ProyectoT9FINALFrmApp::OnExit()
{
	return 0;
}
