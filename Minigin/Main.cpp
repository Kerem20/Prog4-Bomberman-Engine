#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

#if _DEBUG && __has_include(<vld.h>)
#include <vld.h>
#endif

#include "Minigin.h"
#include "SceneManager.h"
#include "ResourceManager.h"
#include "TextObject.h"
#include "Scene.h"
#include "Font.h"

#include <filesystem>
#include <GameObject.h>
#include <RenderComponent.h>
#include <FPSComponent.h>
namespace fs = std::filesystem;

/// <summary>
/// This function is passed to the engine
/// Is Called exactly once, in the engine's Run() function.
/// Here you construct the first scene and populate it with some game objects.
/// </summary>
static void load()
{
	dae::Clock::GetInstance().Init();

	auto& scene = dae::SceneManager::GetInstance().CreateScene();
	std::shared_ptr<dae::Font> font = dae::ResourceManager::GetInstance().LoadFont("Lingua.otf", 50);
	std::shared_ptr<dae::Font> titleFont = dae::ResourceManager::GetInstance().LoadFont("Lingua.otf", 36);

	// Add background object
	auto background = std::make_unique<GameObject>();
	background->AddComponent<RenderComponent>("background.png");
	background->AddComponent<FPSComponent>(font);

	scene.AddGameObject(std::move(background));

	// Add Logo object
	auto logo = std::make_unique<GameObject>();
	logo->AddComponent<RenderComponent>("logo.png");
	logo->m_transform.SetPosition(358, 180);
	
	scene.AddGameObject(std::move(logo));

	// Add Title object
	auto title = std::make_unique<GameObject>();
	title->AddComponent<TextComponent>("Programming 4 Assignment", titleFont);
	title->m_transform.SetPosition(292, 20);

	scene.AddGameObject(std::move(title));
}

int main(int, char*[]) {
#if __EMSCRIPTEN__
	fs::path data_location = "";
#else
	fs::path data_location = "./Data/";
	if(!fs::exists(data_location))
		data_location = "../Data/";
#endif
	// Create the engine, pass the filepath to the Data folder of assets.
	dae::Minigin engine(data_location);
	engine.Run(load);
    return 0;
}
