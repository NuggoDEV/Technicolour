#include "config-utils/shared/config-utils.hpp"

DECLARE_CONFIG(ModConfig,
    CONFIG_VALUE(ModToggle, bool, "Mod Toggle Switch", false);

    CONFIG_VALUE(TechniNotes, std::string, "Makes Notes Colourful :D", "Off");
    CONFIG_VALUE(TechniSabers, std::string, "Makes Sabers Colourful :D", "Off");
    CONFIG_VALUE(TechniBombs, std::string, "Makes Bombs Colourful :D", "Off");
    CONFIG_VALUE(TechniWalls, std::string, "Makes Walls Colourful :D", "Off");
    CONFIG_VALUE(TechniLights, std::string, "Makes Lights Colourful :D", "Off");

    CONFIG_VALUE(LeftGradientOffset, float, "Offset for the left notes gradient", 0.0f);
    CONFIG_VALUE(RightGradientOffset, float, "Offset for the right notes gradient", 128.0f);
    CONFIG_VALUE(BombGradientOffset, float, "Offset for the bomb gradient", 45.0f);
    CONFIG_VALUE(WallGradientOffset, float, "Offset for the wall gradient", 90.0f);

    CONFIG_VALUE(LeftWarmOffset, float, "Offset for the left notes warm colour", 128.0f);
    CONFIG_VALUE(RightCoolOffset, float, "Offset for the right notes cool colour", 128.0f);
)