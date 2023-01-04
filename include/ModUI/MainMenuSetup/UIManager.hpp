#pragma once

#include "bsml/shared/Helpers/creation.hpp"
#include "bsml/shared/BSML.hpp"

#include "HMUI/FlowCoordinator.hpp"
#include "HMUI/ViewController_AnimationDirection.hpp"
#include "HMUI/ViewController_AnimationType.hpp"
#include "ModUI/MainMenuSetup/Flows/TechniFlow.hpp"

#include "questui/shared/BeatSaberUI.hpp"
using namespace QuestUI;

namespace Technicolour::UI::MainMenuSetup
{
    class UIManager
    {
        HMUI::FlowCoordinator *parentFlow;
        Technicolour::UI::MainMenuSetup::TechniFlow *flow;

        public:
            void Init()
            {
                BSML::Register::RegisterMenuButton("Technicolour", "Rainbows!", [this]()
                {
                    ShowFlow(false);
                });
            }

            void ShowFlow(bool immediately)
            {
                if (flow == nullptr || flow->m_CachedPtr.m_value == nullptr)
                    flow = BSML::Helpers::CreateFlowCoordinator<Technicolour::UI::MainMenuSetup::TechniFlow *>();
                
                parentFlow = QuestUI::BeatSaberUI::GetMainFlowCoordinator()->YoungestChildFlowCoordinatorOrSelf();
                parentFlow->PresentFlowCoordinator(flow, nullptr, HMUI::ViewController::AnimationDirection::Horizontal, HMUI::ViewController::AnimationType::Out, false);
            }
    };

    inline static UIManager manager;
}