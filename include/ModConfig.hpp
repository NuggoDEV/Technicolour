#include "config-utils/shared/config-utils.hpp"

DECLARE_CONFIG(ModConfig,
    CONFIG_VALUE(ModToggle, bool, "Mod Toggle Switch", false);

    CONFIG_VALUE(NoteStyle, std::string, "Makes Notes Colourful :D", "Off");
    CONFIG_VALUE(SaberStyle, std::string, "Makes Sabers Colourful :D", "Same as Notes");
    CONFIG_VALUE(BombStyle, std::string, "Makes Bombs Colourful :D", "Off");
    CONFIG_VALUE(ObstacleStyle, std::string, "Makes Obstacles Colourful :D", "Off");
    CONFIG_VALUE(LightStyle, std::string, "Makes Lights Colourful :D", "Off");

    CONFIG_VALUE(LeftSaberGradientOffset, float, "Offset for the left sabers gradient", 1.0f);
    CONFIG_VALUE(RightSaberGradientOffset, float, "Offset for the right sabers gradient", 128.0f);
    CONFIG_VALUE(LeftNoteGradientOffset, float, "Offset for the left notes gradient", 1.0f);
    CONFIG_VALUE(RightNoteGradientOffset, float, "Offset for the right notes gradient", 128.0f);
    CONFIG_VALUE(BombGradientOffset, float, "Offset for the bomb gradient", 45.0f);
    CONFIG_VALUE(ObstacleGradientOffset, float, "Offset for the Obstacle gradient", 90.0f);
    CONFIG_VALUE(LightGradientOffset, float, "Offset for the light gradient", 170.0f);

)