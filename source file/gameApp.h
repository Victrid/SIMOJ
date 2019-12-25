/***************************************************************
 * Name:      gameApp.h
 * Purpose:   Defines Application Class
 * Author:    a ()
 * Created:   2019-12-08
 * Copyright: a ()
 * License:
 **************************************************************/

#ifndef GAMEAPP_H
#define GAMEAPP_H

#include <wx/app.h>

class gameApp : public wxApp
{
public:
    virtual bool OnInit();
    bool stdinit();
};

#endif // GAMEAPP_H
