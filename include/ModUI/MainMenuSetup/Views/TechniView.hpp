#pragma once

#include "main.hpp"

#include "HMUI/FlowCoordinator.hpp"
#include "HMUI/ViewController.hpp"

#include "bsml/shared/BSML/Components/Settings/SliderSetting.hpp"
#include "custom-types/shared/macros.hpp"
#include "bsml/shared/macros.hpp"

#include "UnityEngine/GameObject.hpp"

DECLARE_CLASS_CODEGEN(Technicolour::UI::MainMenuSetup, TechniView, HMUI::ViewController,
    DECLARE_OVERRIDE_METHOD(void, DidActivate, il2cpp_utils::FindMethodUnsafe("HMUI", "ViewController", "DidActivate", 3), bool firstActivation, bool addedToHierarchy, bool screenSystemEnabling);

    DECLARE_BSML_PROPERTY(bool, ModToggle);

    // Page Default Functions
    DECLARE_INSTANCE_METHOD(void, GradientPageDefault);
    DECLARE_INSTANCE_METHOD(void, WarmCoolPageDefault);
    DECLARE_INSTANCE_METHOD(void, StylePageDefault);
    DECLARE_INSTANCE_METHOD(void, AllPageDefault);

    // Gradient Offset Default Functions
    DECLARE_INSTANCE_METHOD(void, LeftSaberGradientOffsetDefault);
    DECLARE_INSTANCE_METHOD(void, RightSaberGradientOffsetDefault);
    DECLARE_INSTANCE_METHOD(void, LeftNoteGradientOffsetDefault);
    DECLARE_INSTANCE_METHOD(void, RightNoteGradientOffsetDefault);
    DECLARE_INSTANCE_METHOD(void, ObstacleGradientOffsetDefault);
    DECLARE_INSTANCE_METHOD(void, BombGradientOffsetDefault);
    DECLARE_INSTANCE_METHOD(void, LightGradientOffsetDefault);

    // Warm/Cool Offset Default Functions
    DECLARE_INSTANCE_METHOD(void, LeftSaberWarmCoolOffsetDefault);
    DECLARE_INSTANCE_METHOD(void, RightSaberWarmCoolOffsetDefault);
    DECLARE_INSTANCE_METHOD(void, LeftNoteWarmCoolOffsetDefault);
    DECLARE_INSTANCE_METHOD(void, RightNoteWarmCoolOffsetDefault);

    // Gradient Offset Objects
    DECLARE_INSTANCE_FIELD(BSML::SliderSetting*, LeftSaberGradientObject);
    DECLARE_INSTANCE_FIELD(BSML::SliderSetting*, RightSaberGradientObject);
    DECLARE_INSTANCE_FIELD(BSML::SliderSetting*, LeftNoteGradientObject);
    DECLARE_INSTANCE_FIELD(BSML::SliderSetting*, RightNoteGradientObject);
    DECLARE_INSTANCE_FIELD(BSML::SliderSetting*, ObstacleGradientObject);
    DECLARE_INSTANCE_FIELD(BSML::SliderSetting*, BombGradientObject);
    DECLARE_INSTANCE_FIELD(BSML::SliderSetting*, LightGradientObject);

    // Warm/Cool Offset Objects
    DECLARE_INSTANCE_FIELD(BSML::SliderSetting*, LeftSaberWarmCoolObject);
    DECLARE_INSTANCE_FIELD(BSML::SliderSetting*, RightSaberWarmCoolObject);
    DECLARE_INSTANCE_FIELD(BSML::SliderSetting*, LeftNoteWarmCoolObject);
    DECLARE_INSTANCE_FIELD(BSML::SliderSetting*, RightNoteWarmCoolObject);

    // Style Choices
    BSML_OPTIONS_LIST_STRING(SaberStyleList, "Same as Notes", "Warm/Cool", "Gradient");
    BSML_OPTIONS_LIST_STRING(NoteStyleList, "Off", "True Random", "Warm/Cool", "Gradient");
    BSML_OPTIONS_LIST_STRING(ObstacleStyleList, "Off", "True Random", "Gradient");
    BSML_OPTIONS_LIST_STRING(BombStyleList, "Off", "True Random", "Gradient");
    BSML_OPTIONS_LIST_STRING(LightStyleList, "Off", "Gradient");

    // Style Values
    DECLARE_BSML_PROPERTY(StringW, SaberStyle);
    DECLARE_BSML_PROPERTY(StringW, NoteStyle);
    DECLARE_BSML_PROPERTY(StringW, ObstacleStyle);
    DECLARE_BSML_PROPERTY(StringW, BombStyle);
    DECLARE_BSML_PROPERTY(StringW, LightStyle);

    // Gradient Offset Values
    DECLARE_BSML_PROPERTY(float, LeftSaberGradientOffset);
    DECLARE_BSML_PROPERTY(float, RightSaberGradientOffset);
    DECLARE_BSML_PROPERTY(float, LeftNoteGradientOffset);
    DECLARE_BSML_PROPERTY(float, RightNoteGradientOffset);
    DECLARE_BSML_PROPERTY(float, ObstacleGradientOffset);
    DECLARE_BSML_PROPERTY(float, BombGradientOffset);
    DECLARE_BSML_PROPERTY(float, LightGradientOffset);

    // Warm/Cool Offset Values
    DECLARE_BSML_PROPERTY(float, LeftSaberWarmCoolOffset);
    DECLARE_BSML_PROPERTY(float, RightSaberWarmCoolOffset);
    DECLARE_BSML_PROPERTY(float, LeftNoteWarmCoolOffset);
    DECLARE_BSML_PROPERTY(float, RightNoteWarmCoolOffset);
)