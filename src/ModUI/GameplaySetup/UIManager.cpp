#include "ModUI/MainMenuSetup/Flows/TechniFlow.hpp"
#include "ModUI/GameplaySetup/GameplayUI.hpp"
#include "ModConfig.hpp"

#include "questui/shared/BeatSaberUI.hpp"
#include "UnityEngine/Resources.hpp"

#include "HMUI/ViewController_AnimationDirection.hpp"
#include "HMUI/ViewController_AnimationType.hpp"

DEFINE_TYPE(Technicolour::UI::Gameplay, UIManager);

namespace Technicolour::UI::Gameplay
{
    SafePtr<UIManager> UIManager::instance;
    UIManager *UIManager::get_instance()
    {
        if (!instance)
            instance = UIManager::New_ctor();
        return instance.ptr();
    }
    void UIManager::ctor() { }
    

    void UIManager::OpenTechnicolour()
    {
        auto currentFlow = QuestUI::BeatSaberUI::GetMainFlowCoordinator()->YoungestChildFlowCoordinatorOrSelf();
        auto techniFlow = QuestUI::BeatSaberUI::CreateFlowCoordinator<Technicolour::UI::MainMenuSetup::TechniFlow*>();

        currentFlow->PresentFlowCoordinator(techniFlow, nullptr, HMUI::ViewController::AnimationDirection::Horizontal, HMUI::ViewController::AnimationType::Out, false);
    }


    bool UIManager::get_ModToggle() { return getModConfig().ModToggle.GetValue(); }
    void UIManager::set_ModToggle(bool value) { getModConfig().ModToggle.SetValue(value); }

    bool UIManager::get_ForceTechnicolour() { return getModConfig().ForceTechnicolour_UI.GetValue(); }
    void UIManager::set_ForceTechnicolour(bool value) { getModConfig().ForceTechnicolour_UI.SetValue(value); }
}