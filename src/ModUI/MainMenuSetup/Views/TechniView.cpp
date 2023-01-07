#include "ModUI/MainMenuSetup/Views/TechniView.hpp"
using namespace Technicolour::UI::MainMenuSetup;

#include "ModConfig.hpp"
#include "assets.hpp"
#include "bsml/shared/BSML.hpp"
#include "bsml/shared/BSML/Components/Settings/DropdownListSetting.hpp"
using namespace BSML;

DEFINE_TYPE(Technicolour::UI::MainMenuSetup, TechniView);

namespace Technicolour::UI::MainMenuSetup
{
    void TechniView::DidActivate(bool firstActivation, bool addedToHierarchy, bool screenSystemEnabling)
    {
        if (!firstActivation) return;

        BSML::parse_and_construct(IncludedAssets::mainmenuSettings_bsml, this->get_transform(), this);

    }
    
    bool TechniView::get_ModToggle() { return getModConfig().ModToggle.GetValue(); }
    void TechniView::set_ModToggle(bool value) { getModConfig().ModToggle.SetValue(value); }


    StringW TechniView::get_TechniNotes() { return getModConfig().TechniNotes.GetValue(); }
    void TechniView::set_TechniNotes(StringW value) { value->ToString(); getModConfig().TechniNotes.SetValue(value); }

    StringW TechniView::get_TechniBombs() { return getModConfig().TechniBombs.GetValue(); }
    void TechniView::set_TechniBombs(StringW value) { value->ToString(); getModConfig().TechniBombs.SetValue(value); }

    StringW TechniView::get_TechniWalls() { return getModConfig().TechniWalls.GetValue(); }
    void TechniView::set_TechniWalls(StringW value) { value->ToString(); getModConfig().TechniWalls.SetValue(value); }

    StringW TechniView::get_TechniLights() { return getModConfig().TechniLights.GetValue(); }
    void TechniView::set_TechniLights(StringW value) { value->ToString(); getModConfig().TechniLights.SetValue(value); }


    float TechniView::get_GradientTime() { return getModConfig().GradientTime.GetValue(); }
    void TechniView::set_GradientTime(float value) { getModConfig().GradientTime.SetValue(value); }
}