#include "config-utils/shared/config-utils.hpp"

DECLARE_CONFIG(ModConfig,
    CONFIG_VALUE(ModToggle, bool, "Mod Toggle Switch", false);

    CONFIG_VALUE(TechniNotes, std::string, "Makes Notes Colourful :D", "Off");
    CONFIG_VALUE(TechniSabers, std::string, "Makes Sabers Colourful :D", "Off");
    CONFIG_VALUE(TechniBombs, std::string, "Makes Bombs Colourful :D", "Off");
    CONFIG_VALUE(TechniWalls, std::string, "Makes Walls Colourful :D", "Off");
)