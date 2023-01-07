#include "ModUI/GameplaySetup/GameplayUI.hpp"
#include "ModConfig.hpp"

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


    //bool UIManager::get_ModToggle() { getModConfig().ModToggle.GetValue(); }
    //void UIManager::set_ModToggle(bool value) { getModConfig().ModToggle.SetValue(value); }
}