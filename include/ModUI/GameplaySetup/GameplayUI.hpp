#pragma once

#include "custom-types/shared/macros.hpp"
#include "HMUI/ViewController.hpp"

#define GET_FIND_METHOD(mPtr) il2cpp_utils::il2cpp_type_check::MetadataGetter<mPtr>::get()

DECLARE_CLASS_CODEGEN(Technicolour::UI::Gameplay, UIManager, Il2CppObject,
    DECLARE_INSTANCE_FIELD(HMUI::ViewController*, settingsViewController);

    DECLARE_CTOR(ctor);
    public:
        static UIManager *get_instance();
    private:
        static SafePtr<UIManager> instance;
)