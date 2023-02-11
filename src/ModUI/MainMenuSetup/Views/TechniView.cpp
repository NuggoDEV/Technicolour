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

    void TechniView::StylesDefault()
    {
        getModConfig().TechniNotes.SetValue(getModConfig().TechniNotes.GetDefaultValue());
        getModConfig().TechniBombs.SetValue(getModConfig().TechniBombs.GetDefaultValue());
        getModConfig().TechniWalls.SetValue(getModConfig().TechniWalls.GetDefaultValue());
        getModConfig().TechniLights.SetValue(getModConfig().TechniLights.GetDefaultValue());
    }

    void TechniView::OffsetsDefault()
    {
        getModConfig().LeftGradientOffset.SetValue(getModConfig().LeftGradientOffset.GetDefaultValue());
        getModConfig().RightGradientOffset.SetValue(getModConfig().RightGradientOffset.GetDefaultValue());
        getModConfig().BombGradientOffset.SetValue(getModConfig().BombGradientOffset.GetDefaultValue());
        getModConfig().WallGradientOffset.SetValue(getModConfig().WallGradientOffset.GetDefaultValue());
        getModConfig().LightGradientOffset.SetValue(getModConfig().LightGradientOffset.GetDefaultValue());


        getModConfig().LeftWarmOffset.SetValue(getModConfig().LeftWarmOffset.GetDefaultValue());
        getModConfig().RightCoolOffset.SetValue(getModConfig().RightCoolOffset.GetDefaultValue());
    }

    void TechniView::AllDefault()
    {
        StylesDefault();
        OffsetsDefault();
    }

    void TechniView::ResetLeftGradient() {
        getModConfig().LeftGradientOffset.SetValue(getModConfig().LeftGradientOffset.GetDefaultValue());
    }

    void TechniView::ResetRightGradient() {
        getModConfig().RightGradientOffset.SetValue(getModConfig().RightGradientOffset.GetDefaultValue());
    }

    void TechniView::ResetBombGradient() {
        getModConfig().BombGradientOffset.SetValue(getModConfig().BombGradientOffset.GetDefaultValue());
    }

    void TechniView::ResetWallGradient() {
        getModConfig().WallGradientOffset.SetValue(getModConfig().WallGradientOffset.GetDefaultValue());
    }

    void TechniView::ResetLightGradient() {
        getModConfig().LightGradientOffset.SetValue(getModConfig().LightGradientOffset.GetDefaultValue());
    }


    void TechniView::ResetLeftWarm() {
        getModConfig().LeftWarmOffset.SetValue(getModConfig().LeftWarmOffset.GetDefaultValue());
    }

    void TechniView::ResetRightCool() {
        getModConfig().RightCoolOffset.SetValue(getModConfig().RightCoolOffset.GetDefaultValue());
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

    
    float TechniView::get_LeftGradientOffset() { return getModConfig().LeftGradientOffset.GetValue(); }
    void TechniView::set_LeftGradientOffset(float value) { getModConfig().LeftGradientOffset.SetValue(value); }

    float TechniView::get_RightGradientOffset() { return getModConfig().RightGradientOffset.GetValue(); }
    void TechniView::set_RightGradientOffset(float value) { getModConfig().RightGradientOffset.SetValue(value); }

    float TechniView::get_BombGradientOffset() { return getModConfig().BombGradientOffset.GetValue(); }
    void TechniView::set_BombGradientOffset(float value) { getModConfig().BombGradientOffset.SetValue(value); }

    float TechniView::get_WallGradientOffset() { return getModConfig().WallGradientOffset.GetValue(); }
    void TechniView::set_WallGradientOffset(float value) { getModConfig().WallGradientOffset.SetValue(value); }

    float TechniView::get_LightGradientOffset() { return getModConfig().LightGradientOffset.GetValue(); }
    void TechniView::set_LightGradientOffset(float value) { getModConfig().LightGradientOffset.SetValue(value); }


    float TechniView::get_LeftWarmOffset() { return getModConfig().LeftWarmOffset.GetValue(); }
    void TechniView::set_LeftWarmOffset(float value) { getModConfig().LeftWarmOffset.SetValue(value); }

    float TechniView::get_RightCoolOffset() { return getModConfig().RightCoolOffset.GetValue(); }
    void TechniView::set_RightCoolOffset(float value) { getModConfig().RightCoolOffset.SetValue(value); }
}