#include "config-utils/shared/config-utils.hpp"

DECLARE_CONFIG(ModConfig,
    // Special Config Value - Not in UI
    CONFIG_VALUE(ForceDisableTechnicolour, bool, "Changes value based on whether you've selected a Chroma dependant map or not.", false);


    CONFIG_VALUE(ModToggle, bool, "Mod Toggle Switch", false);

    // Style Values
    CONFIG_VALUE(NoteStyle, std::string, "Makes Notes Colourful :D", "Off");
    CONFIG_VALUE(SaberStyle, std::string, "Makes Sabers Colourful :D", "Same as Notes");
    CONFIG_VALUE(BombStyle, std::string, "Makes Bombs Colourful :D", "Off");
    CONFIG_VALUE(ObstacleStyle, std::string, "Makes Obstacles Colourful :D", "Off");
    CONFIG_VALUE(LightStyle, std::string, "Makes Lights Colourful :D", "Off");

    // Gradient Offset Values
    CONFIG_VALUE(LeftSaberGradientOffset, float, "Offset for the left sabers gradient", 1.0f);
    CONFIG_VALUE(RightSaberGradientOffset, float, "Offset for the right sabers gradient", 128.0f);
    CONFIG_VALUE(LeftNoteGradientOffset, float, "Offset for the left notes gradient", 1.0f);
    CONFIG_VALUE(RightNoteGradientOffset, float, "Offset for the right notes gradient", 128.0f);
    CONFIG_VALUE(BombGradientOffset, float, "Offset for the bomb gradient", 45.0f);
    CONFIG_VALUE(ObstacleGradientOffset, float, "Offset for the Obstacle gradient", 90.0f);
    CONFIG_VALUE(LightGradientOffset, float, "Offset for the light gradient", 170.0f);

    // Warm/Cool Offset Values
    CONFIG_VALUE(LeftSaberWarmCoolOffset, float, "Offet for the left sabers warm/cool", 128.0f);
    CONFIG_VALUE(RightSaberWarmCoolOffset, float, "Offet for the right sabers warm/cool", 128.0f);
    CONFIG_VALUE(LeftNoteWarmCoolOffset, float, "Offet for the left notes warm/cool", 128.0f);
    CONFIG_VALUE(RightNoteWarmCoolOffset, float, "Offet for the right notes warm/cool", 128.0f);

)