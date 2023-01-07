#pragma once

#include "main.hpp"

#include "HMUI/FlowCoordinator.hpp"
#include "HMUI/ViewController.hpp"

#include "bsml/shared/BSML/Components/Settings/DropdownListSetting.hpp"
#include "custom-types/shared/macros.hpp"
#include "bsml/shared/macros.hpp"


DECLARE_CLASS_CODEGEN(Technicolour::UI::MainMenuSetup, TechniView, HMUI::ViewController,
    DECLARE_OVERRIDE_METHOD(void, DidActivate, il2cpp_utils::FindMethodUnsafe("HMUI", "ViewController", "DidActivate", 3), bool firstActivation, bool addedToHierarchy, bool screenSystemEnabling);

    BSML_OPTIONS_LIST_STRING(TechniNotesChoice, "Off", "Warm/Cold", "True Random", "Gradient");
    BSML_OPTIONS_LIST_STRING(TechniBombsChoice, "Off", "True Random", "Gradient");
    BSML_OPTIONS_LIST_STRING(TechniWallsChoice, "Off", "True Random", "Gradient");
    BSML_OPTIONS_LIST_STRING(TechniLightsChoice, "Off", "Warm/Cold", "True Random", "Gradient");

    DECLARE_BSML_PROPERTY(bool, ModToggle);

    DECLARE_BSML_PROPERTY(StringW, TechniNotes);
    DECLARE_BSML_PROPERTY(StringW, TechniBombs);
    DECLARE_BSML_PROPERTY(StringW, TechniWalls);
    DECLARE_BSML_PROPERTY(StringW, TechniLights);

    DECLARE_BSML_PROPERTY(float, GradientTime);
)