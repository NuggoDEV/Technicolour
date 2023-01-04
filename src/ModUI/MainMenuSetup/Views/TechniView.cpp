#include "ModUI/MainMenuSetup/Views/TechniView.hpp"
using namespace Technicolour::UI::MainMenuSetup;

#include "ModConfig.hpp"
#include "bsml/shared/BSML.hpp"
#include "assets.hpp"

DEFINE_TYPE(Technicolour::UI::MainMenuSetup, TechniView);

namespace Technicolour::UI::MainMenuSetup
{
    void TechniView::DidActivate(bool firstActivation, bool addedToHierarchy, bool screenSystemEnabling)
    {
        if (!firstActivation) return;

        BSML::parse_and_construct(IncludedAssets::mainmenuSettings_bsml, this->get_transform(), this);
    }
}