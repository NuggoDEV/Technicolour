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
        getModConfig().SaberStyle.SetValue(getModConfig().SaberStyle.GetDefaultValue());
        getModConfig().NoteStyle.SetValue(getModConfig().NoteStyle.GetDefaultValue());
        getModConfig().ObstacleStyle.SetValue(getModConfig().ObstacleStyle.GetDefaultValue());
        getModConfig().BombStyle.SetValue(getModConfig().BombStyle.GetDefaultValue());
        getModConfig().LightStyle.SetValue(getModConfig().LightStyle.GetDefaultValue());
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

    }

    void TechniView::LeftSaberGradientOffsetDefault()
    {
        auto value = getModConfig().LeftSaberGradientOffset.GetDefaultValue();
        LeftSaberGradientObject->text->SetText(std::to_string((int)value));
        getModConfig().LeftSaberGradientOffset.SetValue(value);
    }

    void TechniView::RightSaberGradientOffsetDefault()
    {
        auto value = getModConfig().RightSaberGradientOffset.GetDefaultValue();
        RightSaberGradientObject->text->SetText(std::to_string((int)value));
        getModConfig().RightSaberGradientOffset.SetValue(value);
    }

    void TechniView::LeftNoteGradientOffsetDefault()
    {
        auto value = getModConfig().LeftNoteGradientOffset.GetDefaultValue();
        LeftNoteGradientObject->text->SetText(std::to_string((int)value));
        getModConfig().LeftNoteGradientOffset.SetValue(value);
    }

    void TechniView::RightNoteGradientOffsetDefault()
    {
        auto value = getModConfig().RightNoteGradientOffset.GetDefaultValue();
        RightNoteGradientObject->text->SetText(std::to_string((int)value));
        getModConfig().RightNoteGradientOffset.SetValue(value);
    }

    void TechniView::ObstacleGradientOffsetDefault()
    {
        auto value = getModConfig().ObstacleGradientOffset.GetDefaultValue();
        ObstacleGradientObject->text->SetText(std::to_string((int)value));
        getModConfig().ObstacleGradientOffset.SetValue(value);
    }

    void TechniView::BombGradientOffsetDefault()
    {
        auto value = getModConfig().BombGradientOffset.GetDefaultValue();
        BombGradientObject->text->SetText(std::to_string((int)value));
        getModConfig().BombGradientOffset.SetValue(value);
    }

    void TechniView::LightGradientOffsetDefault()
    {
        auto value = getModConfig().LightGradientOffset.GetDefaultValue();
        LightGradientObject->text->SetText(std::to_string((int)value));
        getModConfig().LightGradientOffset.SetValue(value);
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
}