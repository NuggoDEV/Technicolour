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
        HMUI::FlowCoordinator *flowCoordinator;
        auto techniFlow = UnityEngine::Resources::FindObjectsOfTypeAll<Technicolour::UI::MainMenuSetup::TechniFlow *>().FirstOrDefault();

        flowCoordinator->PresentFlowCoordinator(techniFlow, nullptr, HMUI::ViewController::AnimationDirection::Horizontal, HMUI::ViewController::AnimationType::Out, false);
    }


    bool UIManager::get_ModToggle() { return getModConfig().ModToggle.GetValue(); }
    void UIManager::set_ModToggle(bool value) { getModConfig().ModToggle.SetValue(value); }
}