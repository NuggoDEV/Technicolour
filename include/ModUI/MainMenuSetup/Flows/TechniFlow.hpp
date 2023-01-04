#pragma once

#include "main.hpp"

#include "HMUI/FlowCoordinator.hpp"
#include "HMUI/ViewController.hpp"
#include "ModUI/MainMenuSetup/Views/TechniView.hpp"
#include "custom-types/shared/macros.hpp"

DECLARE_CLASS_CODEGEN(Technicolour::UI::MainMenuSetup, TechniFlow, HMUI::FlowCoordinator,
    DECLARE_INSTANCE_FIELD(Technicolour::UI::MainMenuSetup::TechniView*, TechniView); //

    DECLARE_OVERRIDE_METHOD(void, DidActivate, il2cpp_utils::FindMethodUnsafe("HMUI", "FlowCoordinator", "DidActivate", 3), bool firstActivation, bool addedToHierarchy, bool screenSystemEnabling);
    DECLARE_OVERRIDE_METHOD(void, BackButtonWasPressed, il2cpp_utils::FindMethodUnsafe("HMUI", "FlowCoordinator", "BackButtonWasPressed", 1), HMUI::ViewController *topViewController);   
)