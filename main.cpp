//
//  main.cpp
//  Battalion
//
//  Created by trineroks on 8/15/14.
//
//

#include "stdafx.h"
#include "MainExec.h"

int main(int argc, char *argv[])
{
    CMainExec *main = new CMainExec(640, 960);
    main->setNextState(STATE_GAME);
    main->exec();
    delete main;
    
    return 0;
}
