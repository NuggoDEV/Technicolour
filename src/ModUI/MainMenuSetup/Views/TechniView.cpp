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

    void TechniView::AllPageDefault()
    {
        StylePageDefault();
        GradientPageDefault();
        WarmCoolPageDefault();
    }

    void TechniView::StylePageDefault()
    {
        // Sets Values to Default
        getModConfig().SaberStyle.SetValue(getModConfig().SaberStyle.GetDefaultValue());
        getModConfig().NoteStyle.SetValue(getModConfig().NoteStyle.GetDefaultValue());
        getModConfig().ObstacleStyle.SetValue(getModConfig().ObstacleStyle.GetDefaultValue());
        getModConfig().BombStyle.SetValue(getModConfig().BombStyle.GetDefaultValue());
        getModConfig().LightStyle.SetValue(getModConfig().LightStyle.GetDefaultValue());

        // Updates Visual Text
        SaberStyleObject->dropdown->SelectCellWithIdx(0);
        NoteStyleObject->dropdown->SelectCellWithIdx(0);
        ObstacleStyleObject->dropdown->SelectCellWithIdx(0);
        BombStyleObject->dropdown->SelectCellWithIdx(0);
        LightStyleObject->dropdown->SelectCellWithIdx(0);
    }

    void TechniView::GradientPageDefault()
    {
        LeftSaberGradientOffsetDefault();
        RightSaberGradientOffsetDefault();
        LeftNoteGradientOffsetDefault();
        RightNoteGradientOffsetDefault();
        ObstacleGradientOffsetDefault();
        BombGradientOffsetDefault();
        LightGradientOffsetDefault();
    }

    void TechniView::WarmCoolPageDefault()
    {
        LeftNoteWarmCoolOffsetDefault();
        RightNoteWarmCoolOffsetDefault();
    }

    // Warm/Cool Offset Default Buttons
    void TechniView::LeftNoteWarmCoolOffsetDefault()
    {
        auto value = getModConfig().LeftNoteWarmCoolOffset.GetDefaultValue();
        LeftNoteWarmCoolObject->set_Value(value);
        getModConfig().LeftNoteWarmCoolOffset.SetValue(value);
    }

    void TechniView::RightNoteWarmCoolOffsetDefault()
    {
        auto value = getModConfig().RightNoteWarmCoolOffset.GetDefaultValue();
        RightNoteWarmCoolObject->set_Value(value);
        getModConfig().RightNoteWarmCoolOffset.SetValue(value);
    }


    // Gradient Offset Default Buttons
    void TechniView::LeftSaberGradientOffsetDefault()
    {
        auto value = getModConfig().LeftSaberGradientOffset.GetDefaultValue();
        getModConfig().LeftSaberGradientOffset.SetValue(value);
        LeftSaberGradientObject->set_Value(value);
    }

    void TechniView::RightSaberGradientOffsetDefault()
    {
        auto value = getModConfig().RightSaberGradientOffset.GetDefaultValue();
        getModConfig().RightSaberGradientOffset.SetValue(value);
        RightSaberGradientObject->set_Value(value);
    }

    void TechniView::LeftNoteGradientOffsetDefault()
    {
        auto value = getModConfig().LeftNoteGradientOffset.GetDefaultValue();
        getModConfig().LeftNoteGradientOffset.SetValue(value);
        LeftNoteGradientObject->set_Value(value);
    }

    void TechniView::RightNoteGradientOffsetDefault()
    {
        auto value = getModConfig().RightNoteGradientOffset.GetDefaultValue();
        getModConfig().RightNoteGradientOffset.SetValue(value);
        RightNoteGradientObject->set_Value(value);
    }

    void TechniView::ObstacleGradientOffsetDefault()
    {
        auto value = getModConfig().ObstacleGradientOffset.GetDefaultValue();
        getModConfig().ObstacleGradientOffset.SetValue(value);
        ObstacleGradientObject->set_Value(value);
    }

    void TechniView::BombGradientOffsetDefault()
    {
        auto value = getModConfig().BombGradientOffset.GetDefaultValue();
        getModConfig().BombGradientOffset.SetValue(value);
        BombGradientObject->set_Value(value);
    }

    void TechniView::LightGradientOffsetDefault()
    {
        auto value = getModConfig().LightGradientOffset.GetDefaultValue();
        getModConfig().LightGradientOffset.SetValue(value);
        LightGradientObject->set_Value(value);
    }

    bool TechniView::get_ModToggle() { return getModConfig().ModToggle.GetValue(); }
    void TechniView::set_ModToggle(bool value) { getModConfig().ModToggle.SetValue(value); }

    // Style Values
    StringW TechniView::get_SaberStyle() { return getModConfig().SaberStyle.GetValue(); }
    void TechniView::set_SaberStyle(StringW value) { value->ToString(); getModConfig().SaberStyle.SetValue(value); }
    
    StringW TechniView::get_NoteStyle() { return getModConfig().NoteStyle.GetValue(); }
    void TechniView::set_NoteStyle(StringW value) { value->ToString(); getModConfig().NoteStyle.SetValue(value); }

    StringW TechniView::get_ObstacleStyle() { return getModConfig().ObstacleStyle.GetValue(); }
    void TechniView::set_ObstacleStyle(StringW value) { value->ToString(); getModConfig().ObstacleStyle.SetValue(value); }

    StringW TechniView::get_BombStyle() { return getModConfig().BombStyle.GetValue(); }
    void TechniView::set_BombStyle(StringW value) { value->ToString(); getModConfig().BombStyle.SetValue(value); }

    StringW TechniView::get_LightStyle() { return getModConfig().LightStyle.GetValue(); }
    void TechniView::set_LightStyle(StringW value) { value->ToString(); getModConfig().LightStyle.SetValue(value); }


    // Gradient Offset Values
    float TechniView::get_LeftSaberGradientOffset() { return getModConfig().LeftSaberGradientOffset.GetValue(); }
    void TechniView::set_LeftSaberGradientOffset(float value) { getModConfig().LeftSaberGradientOffset.SetValue(value); }

    float TechniView::get_RightSaberGradientOffset() { return getModConfig().RightSaberGradientOffset.GetValue(); }
    void TechniView::set_RightSaberGradientOffset(float value) { getModConfig().RightSaberGradientOffset.SetValue(value); }

    float TechniView::get_LeftNoteGradientOffset() { return getModConfig().LeftNoteGradientOffset.GetValue(); }
    void TechniView::set_LeftNoteGradientOffset(float value) { getModConfig().LeftNoteGradientOffset.SetValue(value); }

    float TechniView::get_RightNoteGradientOffset() { return getModConfig().RightNoteGradientOffset.GetValue(); }
    void TechniView::set_RightNoteGradientOffset(float value) { getModConfig().RightNoteGradientOffset.SetValue(value); }

    float TechniView::get_ObstacleGradientOffset() { return getModConfig().ObstacleGradientOffset.GetValue(); }
    void TechniView::set_ObstacleGradientOffset(float value) { getModConfig().ObstacleGradientOffset.SetValue(value); }

    float TechniView::get_BombGradientOffset() { return getModConfig().BombGradientOffset.GetValue(); }
    void TechniView::set_BombGradientOffset(float value) { getModConfig().BombGradientOffset.SetValue(value); }

    float TechniView::get_LightGradientOffset() { return getModConfig().LightGradientOffset.GetValue(); }
    void TechniView::set_LightGradientOffset(float value) { getModConfig().LightGradientOffset.SetValue(value); }

    // Warm/Cool Values
    float TechniView::get_LeftNoteWarmCoolOffset() { return getModConfig().LeftNoteWarmCoolOffset.GetValue(); }
    void TechniView::set_LeftNoteWarmCoolOffset(float value) { getModConfig().LeftNoteWarmCoolOffset.SetValue(value); }

    float TechniView::get_RightNoteWarmCoolOffset() { return getModConfig().RightNoteWarmCoolOffset.GetValue(); }
    void TechniView::set_RightNoteWarmCoolOffset(float value) { getModConfig().RightNoteWarmCoolOffset.SetValue(value); }
}