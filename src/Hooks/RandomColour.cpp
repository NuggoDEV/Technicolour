#include "Hooks.hpp"
#include "ModConfig.hpp"
#include "Controllers/RandomController.hpp"
using namespace Technicolour::Controllers;

#include "GlobalNamespace/NoteController.hpp"
#include "GlobalNamespace/NoteData.hpp"
#include "GlobalNamespace/ColorType.hpp"

#include "GlobalNamespace/BombNoteController.hpp"

#include "GlobalNamespace/ObstacleController.hpp"
#include "GlobalNamespace/ObstacleData.hpp"
#include "GlobalNamespace/ColorType.hpp"

#include "GlobalNamespace/LightSwitchEventEffect.hpp"
#include "GlobalNamespace/BasicBeatmapEventData.hpp"
using namespace GlobalNamespace;

#include "UnityEngine/Color.hpp"
#include "UnityEngine/Vector3.hpp"
using namespace UnityEngine;

#include <iostream>
#include <cstdlib>
#include <random>

#include "sombrero/shared/FastColor.hpp"

#include "chroma/shared/BombAPI.hpp"
#include "chroma/shared/NoteAPI.hpp"
#include "chroma/shared/ObstacleAPI.hpp"
#include "chroma/shared/LightAPI.hpp"



MAKE_AUTO_HOOK_MATCH(NoteController_Init, &NoteController::Init, void, NoteController *self, NoteData *noteData, float worldRotation, Vector3 moveStartPos, Vector3 moveEndPos, 
Vector3 jumpEndPos, float moveDuration, float jumpDuration, float jumpGravity, float endRotation, float uniformScale, bool rotateTowardsPlayer, bool useRandomRotation)
{
    NoteController_Init(self, noteData, worldRotation, moveStartPos, moveEndPos, jumpEndPos, moveDuration, 
    jumpDuration, jumpGravity, endRotation, uniformScale, rotateTowardsPlayer, useRandomRotation);

    if (getModConfig().ModToggle.GetValue() && getModConfig().TechniNotes.GetValue() == "True Random" && noteData->colorType == ColorType::ColorA)
        Chroma::NoteAPI::setInitialNoteControllerColorSafe(self, RandomColourGen());

    else if (getModConfig().ModToggle.GetValue() && getModConfig().TechniNotes.GetValue() == "True Random" && noteData->colorType == ColorType::ColorB)
        Chroma::NoteAPI::setInitialNoteControllerColorSafe(self, RandomColourGen());

}

MAKE_AUTO_HOOK_MATCH(BombController_Init, &BombNoteController::Init, void, BombNoteController *self, NoteData *noteData, float worldRotation,
Vector3 moveStartPos, Vector3 moveEndPos, Vector3 jumpEndPos, float moveDuration, float jumpDuration, float jumpGravity)
{
    BombController_Init(self, noteData, worldRotation, moveStartPos, moveEndPos, jumpEndPos, moveDuration, jumpDuration, jumpGravity);

    if (getModConfig().ModToggle.GetValue() && getModConfig().TechniBombs.GetValue() == "True Random")
        Chroma::BombAPI::setBombColorSafe(self, RandomColourGen());
}

MAKE_AUTO_HOOK_MATCH(ObstacleController_Init, &ObstacleController::Init, void, ObstacleController *self, ObstacleData *obstacleData, float worldRotation, 
Vector3 startPos, Vector3 midPos, Vector3 endPos, float move1Duration, float move2Duration, float singleLineWidth, float height)
{
    ObstacleController_Init(self, obstacleData, worldRotation, startPos, midPos, endPos, move1Duration, move2Duration, singleLineWidth, height);

    if (getModConfig().ModToggle.GetValue() && getModConfig().TechniWalls.GetValue() == "True Random")
        Chroma::ObstacleAPI::setObstacleColorSafe(self, RandomColourGen());
}

