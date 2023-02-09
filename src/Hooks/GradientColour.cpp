#include "main.hpp"
#include "Hooks.hpp"
#include "ModConfig.hpp"
// #include "Controllers/GradientController.hpp"
// using namespace Technicolour::Controllers;

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
#include <unordered_map>

float bPos;
float lPos;
float rPos;
float wPos;

const int GRADIENT_STEPS = 256;

std::vector<FastColor> gradientColors;

void PrecomputeGradientColors()
{
  gradientColors.resize(GRADIENT_STEPS + 1);
  for (int i = 0; i <= GRADIENT_STEPS; ++i) {
    float t = (float)i / GRADIENT_STEPS;

    FastColor colour;
    if (t < 0.33f) {
      colour = FastColor::Lerp(FastColor(1.0f, 0.0f, 0.0f, 1.0f), FastColor(1.0f, 1.0f, 0.0f, 1.0f), t * 3.0f);
    } else if (t < 0.66f) {
      colour = FastColor::Lerp(FastColor(1.0f, 1.0f, 0.0f, 1.0f), FastColor(0.0f, 0.0f, 1.0f, 1.0f), (t - 0.33f) * 3.0f);
    } else {
      colour = FastColor::Lerp(FastColor(0.0f, 0.0f, 1.0f, 1.0f), FastColor(1.0f, 0.0f, 0.0f, 1.0f), (t - 0.66f) * 3.0f);
    }

    gradientColors[i] = colour;
  }
}

FastColor GradientGen(int index)
{
  return gradientColors[index];
}


MAKE_AUTO_HOOK_MATCH(GameplayCoreInstaller_InstallBindings, &GameplayCoreInstaller::InstallBindings, void, GameplayCoreInstaller *self)
{
  GameplayCoreInstaller_InstallBindings(self);
  PrecomputeGradientColors();

  bPos = getModConfig().BombGradientOffset.GetValue();
  lPos = getModConfig().LeftGradientOffset.GetValue();
  rPos = getModConfig().RightGradientOffset.GetValue();
  wPos = getModConfig().WallGradientOffset.GetValue();
}

MAKE_AUTO_HOOK_MATCH(AudioTimeSyncController_Update, &AudioTimeSyncController::Update, void, AudioTimeSyncController *self)
{
  AudioTimeSyncController_Update(self);
  // int songTime = self->get_songTime();

  if (getModConfig().ModToggle.GetValue() && getModConfig().TechniBombs.GetValue() == "Gradient")
  {
    // Bomb Colour
    FastColor Bomb = GradientGen(bPos);
    Chroma::BombAPI::setGlobalBombColorSafe(Bomb);
    bPos++;
    if (bPos > 255)
      bPos = 0;
  }

  if (getModConfig().ModToggle.GetValue() && getModConfig().TechniNotes.GetValue() == "Gradient")
  {
    // Left & Right Colour
    FastColor LeftColour = GradientGen(lPos);
    FastColor RightColour = GradientGen(rPos);

    Chroma::NoteAPI::setGlobalNoteColorSafe(LeftColour, RightColour);
    Chroma::SaberAPI::setGlobalSaberColorSafe(SaberType::SaberA, LeftColour);
    Chroma::SaberAPI::setGlobalSaberColorSafe(SaberType::SaberB, RightColour);
    lPos++;
    rPos++;
    if (lPos > 255)
      lPos = 0;
    if (rPos > 255)
      rPos = 0;
  }

  if (getModConfig().ModToggle.GetValue() && getModConfig().TechniWalls.GetValue() == "Gradient")
  {
    // Wall Colour
    FastColor Wall = GradientGen(wPos);
    FastColor wallColour;

    Chroma::ObstacleAPI::setAllObstacleColorSafe(wallColour);
    wPos++;
    if (wPos > 255)
      wPos = 0;
  }
}
