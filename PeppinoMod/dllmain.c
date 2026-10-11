// Peppino mod: STEP 0 "hello" test. It does nothing except load and write log lines.
// Modeled directly on the official ManiaTouchControls dllmain.c.
// UNTESTED. Unverified guesses are marked [CHECK].
#include "GameAPI/Game.h"

#if RETRO_USE_MOD_LOADER
DLLExport bool32 LinkModLogic(EngineInfo *info, const char *id);
#endif

// Runs every time a stage loads (MODCB_ONSTAGELOAD exists in the loader's callback list)
void PeppinoMod_OnStageLoad(void *data)
{
    // [CHECK] RSDK.PrintLog(PRINT_NORMAL, ...) is my recollection of the log call
    RSDK.PrintLog(PRINT_NORMAL, "[PeppinoMod] stage loaded");
}

void InitModAPI(void)
{
    RSDK.PrintLog(PRINT_NORMAL, "[PeppinoMod] mod loaded");
    Mod.AddModCallback(MODCB_ONSTAGELOAD, PeppinoMod_OnStageLoad);
}

#if RETRO_USE_MOD_LOADER
bool32 LinkModLogic(EngineInfo *info, const char *id)
{
#if MANIA_USE_PLUS
    LinkGameLogicDLL(info);
#else
    LinkGameLogicDLL(*info);
#endif

    globals = Mod.GetGlobals();

    modID = id;

    InitModAPI();

    return true;
}
#endif
