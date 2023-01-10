#include "main.hpp"
#include "Hooks.hpp"
#include "ModConfig.hpp"
#include "Controllers/WarmCoolController.hpp"
using namespace Technicolour::Controllers;

#include "GlobalNamespace/AudioTimeSyncController.hpp"
using namespace GlobalNamespace;

#include "sombrero/shared/FastColor.hpp"
using namespace Sombrero;


#include "chroma/shared/SaberAPI.hpp"
#include "chroma/shared/BombAPI.hpp"
#include "chroma/shared/NoteAPI.hpp"
#include "chroma/shared/ObstacleAPI.hpp"
#include "chroma/shared/LightAPI.hpp"

int i = 0, ii = 0;

MAKE_AUTO_HOOK_MATCH(WC_AudioTimeSyncController_Update, &GlobalNamespace::AudioTimeSyncController::Update, void, GlobalNamespace::AudioTimeSyncController* self)
{
    WC_AudioTimeSyncController_Update(self);

    if (getModConfig().ModToggle.GetValue() && getModConfig().TechniNotes.GetValue() == "Warm/Cold")
    {
        FastColor LeftColour = WarmColourGen(i);
        FastColor RightColour = CoolColourGen(ii);

        Chroma::NoteAPI::setGlobalNoteColorSafe(LeftColour, RightColour);
        Chroma::SaberAPI::setGlobalSaberColorSafe(SaberType::SaberA, LeftColour);
        Chroma::SaberAPI::setGlobalSaberColorSafe(SaberType::SaberB, RightColour);
        i++;
        ii++;
        if (i > 255)
            i = 150;
        if (i < 150)
            i = 150;
        
        if (ii > 115)
            ii = 0;

    }
}