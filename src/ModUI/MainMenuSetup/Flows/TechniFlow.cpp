#include "ModUI/MainMenuSetup/Flows/TechniFlow.hpp"
#include "ModUI/MainMenuSetup/Views/TechniView.hpp"
DEFINE_TYPE(Technicolour::UI::MainMenuSetup, TechniFlow);

#include "HMUI/ViewController_AnimationDirection.hpp"
#include "HMUI/ViewController_AnimationType.hpp"
using namespace HMUI;

#include "questui/shared/BeatSaberUI.hpp"
using namespace QuestUI;

void Technicolour::UI::MainMenuSetup::TechniFlow::DidActivate(bool firstActivation, bool addedToHierarchy, bool screenSystemEnabling)
{
    if (!firstActivation) return;
    TechniView = BeatSaberUI::CreateViewController<Technicolour::UI::MainMenuSetup::TechniView *>();

    showBackButton = true;
    ProvideInitialViewControllers(TechniView, nullptr, nullptr, nullptr, nullptr);
    SetTitle("Technicolour RC1 Settings", ViewController::AnimationType::In);
}

void Technicolour::UI::MainMenuSetup::TechniFlow::BackButtonWasPressed(ViewController *topViewController)
{
    this->parentFlowCoordinator->DismissFlowCoordinator(this, ViewController::AnimationDirection::Horizontal, nullptr, false);
}