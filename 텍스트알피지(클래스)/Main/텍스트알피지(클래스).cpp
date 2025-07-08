#include "pch.h"
#include "CMainGame.h"

int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    CMainGame MainGame;
    //int* leakTest = new int(123);
    if (MainGame.Initialize())
    {
        MainGame.Update();
    }

    

    return 0;
}

