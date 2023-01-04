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
}