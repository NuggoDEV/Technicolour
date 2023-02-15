#include "main.hpp"
#include "Hooks.hpp"
#include "ModConfig.hpp"

#include "GlobalNamespace/BombNoteController.hpp"
#include "GlobalNamespace/NoteController.hpp"
#include "GlobalNamespace/NoteData.hpp"
#include "GlobalNamespace/ColorType.hpp"

#include "GlobalNamespace/ObstacleController.hpp"
#include "GlobalNamespace/ObstacleData.hpp"
#include "GlobalNamespace/ColorType.hpp"

// Light related shit
/*#include "GlobalNamespace/BasicBeatmapEventType.hpp"
#include "GlobalNamespace/EventsTestGameplayManager.hpp"
#include "GlobalNamespace/ColorBoostBeatmapEventData.hpp"
#include "GlobalNamespace/BeatmapCallbacksController.hpp"
#include "GlobalNamespace/BasicBeatmapEventData.hpp"
#include "GlobalNamespace/LightSwitchEventEffect.hpp"
#include "GlobalNamespace/BasicBeatmapEventData.hpp"*/
using namespace GlobalNamespace;

#include "UnityEngine/Color.hpp"
#include "UnityEngine/Vector3.hpp"
using namespace UnityEngine;

#include <iostream>
#include <cstdlib>
#include <random>

#include "sombrero/shared/FastColor.hpp"
using namespace Sombrero;

#include "chroma/shared/BombAPI.hpp"
#include "chroma/shared/NoteAPI.hpp"
#include "chroma/shared/ObstacleAPI.hpp"
#include "chroma/shared/LightAPI.hpp"

FastColor RandomColourGen()
{
  static std::mt19937 gen(std::random_device{}());
  static std::uniform_real_distribution<> dis(0.0, 1.0);
  float hue = dis(gen);
  float saturation = 1.0f;
  float value = 1.0f;

  FastColor colour = FastColor::HSVToRGB(hue, saturation, value);
  return colour;
}

MAKE_AUTO_HOOK_MATCH(NoteController_Init, &NoteController::Init, void, NoteController *self, NoteData *noteData, float worldRotation, Vector3 moveStartPos, Vector3 moveEndPos, Vector3 jumpEndPos, float moveDuration, float jumpDuration, float jumpGravity, float endRotation, float uniformScale, bool rotateTowardsPlayer, bool useRandomRotation)
{
  NoteController_Init(self, noteData, worldRotation, moveStartPos, moveEndPos, jumpEndPos, moveDuration, jumpDuration, jumpGravity, endRotation, uniformScale, rotateTowardsPlayer, useRandomRotation);

  if (getModConfig().ForceDisableTechnicolour.GetValue()) return;

  if (getModConfig().ModToggle.GetValue() && getModConfig().NoteStyle.GetValue() == "True Random" && noteData->colorType == ColorType::ColorA)
    Chroma::NoteAPI::setInitialNoteControllerColorSafe(self, RandomColourGen());

  else if (getModConfig().ModToggle.GetValue() && getModConfig().NoteStyle.GetValue() == "True Random" && noteData->colorType == ColorType::ColorB)
    Chroma::NoteAPI::setInitialNoteControllerColorSafe(self, RandomColourGen());
}

MAKE_AUTO_HOOK_MATCH(BombController_Init, &BombNoteController::Init, void, BombNoteController *self, NoteData *noteData, float worldRotation, Vector3 moveStartPos, Vector3 moveEndPos, Vector3 jumpEndPos, float moveDuration, float jumpDuration, float jumpGravity)
{
  BombController_Init(self, noteData, worldRotation, moveStartPos, moveEndPos, jumpEndPos, moveDuration, jumpDuration, jumpGravity);

  if (getModConfig().ForceDisableTechnicolour.GetValue()) return;

  if (getModConfig().ModToggle.GetValue() && getModConfig().BombStyle.GetValue() == "True Random")
    Chroma::BombAPI::setBombColorSafe(self, RandomColourGen());
}

MAKE_AUTO_HOOK_MATCH(ObstacleController_Init, &ObstacleController::Init, void, ObstacleController *self, ObstacleData *obstacleData, float worldRotation, Vector3 startPos, Vector3 midPos, Vector3 endPos, float move1Duration, float move2Duration, float singleLineWidth, float height)
{
  ObstacleController_Init(self, obstacleData, worldRotation, startPos, midPos, endPos, move1Duration, move2Duration, singleLineWidth, height);

  if (getModConfig().ForceDisableTechnicolour.GetValue()) return;

  if (getModConfig().ModToggle.GetValue() && getModConfig().ObstacleStyle.GetValue() == "True Random")
    Chroma::ObstacleAPI::setObstacleColorSafe(self, RandomColourGen());
}


// Still a WIP
/*
#include "GlobalNamespace/BeatmapCallbacksController.hpp"
#include "GlobalNamespace/BeatmapDataItem.hpp"
#include "GlobalNamespace/BeatmapData.hpp"

#include "GlobalNamespace/LightWithIdManager.hpp"

MAKE_AUTO_HOOK_MATCH(theuhf, &LightWithIdManager::LateUpdate, void, LightWithIdManager *self)
{
  theuhf(self);

  auto a = Chroma::LightAPI::getLightsSafe(self);
  
}

MAKE_AUTO_HOOK_MATCH(pain_jpeg, &BeatmapCallbacksController::HandleBeatmapEventDataWasInserted, void, BeatmapCallbacksController *self, BeatmapEventData *beatmapEventData, System::Collections::Generic::LinkedListNode_1<BeatmapDataItem *> *node)
{
  pain_jpeg(self, beatmapEventData, node);

  Chroma::LightAPI::getLightsSafe();
}*/

/*MAKE_AUTO_HOOK_MATCH(sdfjhkgf, &LightSwitchEventEffect::HandleColorChangeBeatmapEvent, void, LightSwitchEventEffect *self, BasicBeatmapEventData *basicBeatmapEventData)
{
  sdfjhkgf(self, basicBeatmapEventData);
  getLogger().info("Activated Light Switch Event!");

  auto lights = Chroma::LightAPI::getLightsSafe(self);

  for (auto light : lights.value())
  {
    FastColor colour = RandomColourGen();
    Chroma::LightAPI::setLightColorSafe(self->event, true, Chroma::LightAPI::LSEData{colour, colour, colour, colour});
    light->ColorWasSet(colour);
  }
}*/