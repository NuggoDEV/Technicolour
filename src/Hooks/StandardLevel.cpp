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

static inline const std::string ChromaReq = "Chroma";

MAKE_AUTO_HOOK_MATCH(Level, &StandardLevelDetailView::RefreshContent, void, StandardLevelDetailView *self)
{
    Level(self);
    
    // Used code from NE to instead check for Chroma
    PinkCore::API::GetFoundRequirementCallbackSafe() += [](const std::vector<std::string>& requirements) 
    {
        bool chromaReq = std::any_of(requirements.begin(), requirements.end(), [](auto const& s) { return s == ChromaReq; });

        if (getModConfig().ForceTechnicolour_UI.GetValue())
        {
            getModConfig().ForceDisableTechnicolour.SetValue(false);
            return;
        }

        if (chromaReq)
        {
            Chroma::CoreAPI::removeForceEnableChromaHooks(modInf());
            getModConfig().ForceDisableTechnicolour.SetValue(true);
        }
        else 
        {
            Chroma::CoreAPI::addForceEnableChromaHooks(modInf());
            getModConfig().ForceDisableTechnicolour.SetValue(false);
        }
    };

    getLogger().info(&"Technicolour forced to: " [ getModConfig().ForceDisableTechnicolour.GetValue() ]);
}
