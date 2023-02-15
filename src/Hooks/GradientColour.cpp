#include "main.hpp"
#include "Hooks.hpp"
#include "ModConfig.hpp"

#include "GlobalNamespace/GameplayCoreInstaller.hpp"
#include "GlobalNamespace/AudioTimeSyncController.hpp"
using namespace GlobalNamespace;

#include "sombrero/shared/FastColor.hpp"
using namespace Sombrero;

#include "chroma/shared/SaberAPI.hpp"
#include "chroma/shared/BombAPI.hpp"
#include "chroma/shared/NoteAPI.hpp"
#include "chroma/shared/ObstacleAPI.hpp"
#include "chroma/shared/LightAPI.hpp"

#include <array>

float leftSaberPos, rightSaberPos, leftNotePos, rightNotePos, obstaclePos, bombPos, lightPos;
bool firstActivation = true;

const int GRADIENT_STEPS = 256;

std::vector<FastColor> gradientColours;

void PrecomputeGradientColours()
{
  gradientColours.resize(GRADIENT_STEPS + 1);
  for (int i = 0; i <= GRADIENT_STEPS; i++)
  {
    float t = (float)i / GRADIENT_STEPS;

    FastColor colour;
    if (t < 0.33f)
    {
      colour = FastColor::Lerp(FastColor(1.0f, 0.0f, 0.0f, 1.0f), /*Double check this later*/ FastColor(0.0f, 1.0f, 0.0f, 1.0f), t * 3.0f);
    }
    else if (t < 0.66f)
    {
      colour = FastColor::Lerp(FastColor(0.0f, 1.0f, 0.0f, 1.0f), FastColor(0.0f, 0.0f, 1.0f, 1.0f), (t - 0.33f) * 3.0f);
    }
    else
    {
      colour = FastColor::Lerp(FastColor(0.0f, 0.0f, 1.0f, 1.0f), FastColor(1.0f, 0.0f, 0.0f, 1.0f), (t - 0.66f) * 3.0f);
    }

    gradientColours[i] = colour;
  }
}

FastColor GradientGen(int index)
{
  return gradientColours[index];
}

MAKE_AUTO_HOOK_MATCH(GameplayCoreInstaller_InstallBindings, &GameplayCoreInstaller::InstallBindings, void, GameplayCoreInstaller *self)
{
  GameplayCoreInstaller_InstallBindings(self);

  if (!firstActivation) return;

  if (getModConfig().ForceDisableTechnicolour.GetValue()) return;

  PrecomputeGradientColours();

  leftSaberPos = getModConfig().LeftSaberGradientOffset.GetValue();
  rightSaberPos = getModConfig().RightSaberGradientOffset.GetValue();
  bombPos = getModConfig().BombGradientOffset.GetValue();
  leftNotePos = getModConfig().LeftNoteGradientOffset.GetValue();
  rightNotePos = getModConfig().RightNoteGradientOffset.GetValue();
  obstaclePos = getModConfig().ObstacleGradientOffset.GetValue();
  lightPos = getModConfig().LightGradientOffset.GetValue();
}

MAKE_AUTO_HOOK_MATCH(AudioTimeSyncController_Update, &AudioTimeSyncController::Update, void, AudioTimeSyncController *self)
{
  AudioTimeSyncController_Update(self);

  if (getModConfig().ForceDisableTechnicolour.GetValue() || !getModConfig().ModToggle.GetValue()) return;

  if (getModConfig().BombStyle.GetValue() == "Gradient")
  {
    // Bomb Colour
    FastColor Bomb = GradientGen(bombPos);
    Chroma::BombAPI::setGlobalBombColorSafe(Bomb);
    bombPos++;
    if (bombPos > 255)
      bombPos = 0;
  }

  if (getModConfig().SaberStyle.GetValue() == "Gradient") {
    FastColor LeftColour = GradientGen(leftSaberPos);
    FastColor RightColour = GradientGen(rightSaberPos);

    Chroma::SaberAPI::setGlobalSaberColorSafe(SaberType::SaberA, LeftColour);
    Chroma::SaberAPI::setGlobalSaberColorSafe(SaberType::SaberB, RightColour);

    leftSaberPos++;
    rightSaberPos++;

    if (leftSaberPos > 255)
      leftSaberPos = 0;
    if (rightSaberPos > 255)
      rightSaberPos = 0;
  }

  if (getModConfig().NoteStyle.GetValue() == "Gradient")
  {
    // Left & Right Colour
    FastColor LeftColour = GradientGen(leftNotePos);
    FastColor RightColour = GradientGen(rightNotePos);

    Chroma::NoteAPI::setGlobalNoteColorSafe(LeftColour, RightColour);

    if (getModConfig().SaberStyle.GetValue() == "Same as Notes")
    {
      Chroma::SaberAPI::setGlobalSaberColorSafe(SaberType::SaberA, LeftColour);
      Chroma::SaberAPI::setGlobalSaberColorSafe(SaberType::SaberB, RightColour);
    }
    
    leftNotePos++;
    rightNotePos++;
    if (leftNotePos > 255)
      leftNotePos = 0;
    if (rightNotePos > 255)
      rightNotePos = 0;
  }

  if (getModConfig().ObstacleStyle.GetValue() == "Gradient") 
  {
    FastColor ObstacleColour = GradientGen(obstaclePos);

    Chroma::ObstacleAPI::setAllObstacleColorSafe(ObstacleColour);
    obstaclePos++;
    if (obstaclePos > 255)
      obstaclePos = 0;
  }


  if (getModConfig().LightStyle.GetValue() == "Gradient")
  {
    FastColor LightColour = GradientGen(lightPos);

    Chroma::LightAPI::setAllLightingColorsSafe(true, Chroma::LightAPI::LSEData{LightColour, LightColour, LightColour, LightColour});
    lightPos++;
    if (lightPos > 255)
      lightPos = 0;
  }
}
