#include "main.hpp"
#include "ModConfig.hpp"
#include "Hooks.hpp"

#include "chroma/shared/CoreAPI.hpp"

#include "assets.hpp"
#include "bsml/shared/BSML.hpp"
#include "bsml/shared/BSMLDataCache.hpp"
#include "ModUI/MainMenuSetup/UIManager.hpp"
#include "ModUI/GameplaySetup/GameplayUI.hpp"
using namespace Technicolour::UI::MainMenuSetup;

static ModInfo modInfo;

ModInfo& modInf() {
    return modInfo;
}

Configuration& getConfig() {
    static Configuration config(modInfo);
    return config;
}

// Returns a logger, useful for printing debug messages
Logger& getLogger() {
    static Logger* logger = new Logger(modInfo);
    return *logger;
}

// Called at the early stages of game loading
extern "C" void setup(ModInfo& info) {
    info.id = MOD_ID;
    info.version = VERSION;
    modInfo = info;
	
    getConfig().Load();
    getLogger().info("Completed setup!");
}

// Called later on in the game loading - a good time to install function hooks
extern "C" void load() {
    il2cpp_functions::Init();

    getLogger().info("Initializing Config & UI.");
    getModConfig().Init(modInfo);
    BSML::Init();
    BSML::Register::RegisterGameplaySetupTab("Technicolour", MOD_ID "_settings", Technicolour::UI::Gameplay::UIManager::get_instance(), BSML::MenuType::All);
    manager.Init();
    getLogger().info("Initialized Config & UI Successfully!");

    getLogger().info("Installing Technicolour Hooks.");
    Hooks::InstallHooks(getLogger());
    Chroma::CoreAPI::addForceEnableChromaHooks(modInfo);
    Modloader::requireMod("Chroma");
    getLogger().info("Installed all Technicolour Hooks!");
}

BSML_DATACACHE(settings)
{
    return IncludedAssets::gameplaySettings_bsml;
}