/***************************************************************
 * Name:      gameApp.cpp
 * Purpose:   Code for Application Class
 * Author:    a ()
 * Created:   2019-12-08
 * Copyright: a ()
 * License:
 **************************************************************/

#include "gameApp.h"
//(*AppHeaders
#include "gameMain.h"
#include "intro.h"
//*)

IMPLEMENT_APP(gameApp);

bool gameApp::OnInit()
{

    Intro* Int1 = new Intro(0,".\\memory.sys",this);
    Int1->Show();
    return true;
}

bool gameApp::stdinit(){
    gameFrame* Frame = new gameFrame(0);
    Frame->Show();
    Frame->Next();
    return true;
}
