#include "main.hpp"
#include "Hooks.hpp"
#include "ModConfig.hpp"

#include "pinkcore/shared/API.hpp"
using namespace PinkCore;

#include "chroma/shared/CoreAPI.hpp"

#include "GlobalNamespace/StandardLevelDetailView.hpp"
using namespace GlobalNamespace;

#include <any>
#include <vector>
#include <string>

MAKE_AUTO_HOOK_MATCH(Level, &StandardLevelDetailView::RefreshContent, void, StandardLevelDetailView *self)
{
    Level(self);
    PinkCore::API::GetFoundRequirementCallbackSafe() += [](const std::vector<std::string>& requirements) 
    {
        bool chromaReq = std::any_of(requirements.begin(), requirements.end(), [](auto const& s) { return s == "chroma"; });

        if (chromaReq)
            Chroma::CoreAPI::removeForceEnableChromaHooks(modInf());
        else 
            Chroma::CoreAPI::addForceEnableChromaHooks(modInf());
    };
    
}
