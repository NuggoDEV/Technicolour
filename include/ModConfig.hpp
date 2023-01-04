#include "config-utils/shared/config-utils.hpp"

DECLARE_CONFIG(ModConfig,
    CONFIG_VALUE(ModToggle, bool, "Mod Toggle Switch", false);

    CONFIG_VALUE(RainbowNotes, bool, "Makes Notes Rainbows :D", false);
    CONFIG_VALUE(RainbowSabers, bool, "Makes Sabers Rainbows :D", false);
    CONFIG_VALUE(RainbowWalls, bool, "Makes Walls Rainbows :D", false);
)