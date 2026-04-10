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
	std::shared_ptr<dae::Font> font = dae::ResourceManager::GetInstance().LoadFont("Lingua.otf",100);

	auto go = std::make_unique<GameObject>();
	go->AddComponent<Component>();
	go->RemoveComponent<Component>();

	go->AddComponent<RenderComponent>("background.png");
	go->AddComponent<FPSComponent>(font);

	scene.AddGameObject(std::move(go));

	//go->SetTexture("background.png");
	//scene.AddGameObject(std::move(go));

	//go = std::make_unique<dae::GameObject>();
	//go->SetTexture("logo.png");
	//go->SetPosition(358, 180);
	//scene.AddGameObject(std::move(go));

	//auto font = dae::ResourceManager::GetInstance().LoadFont("Lingua.otf", 36);
	//auto to = std::make_unique<dae::TextObject>("Programming 4 Assignment", font);
	//to->SetColor({ 255, 255, 0, 255 });
	//to->SetPosition(292, 20);
	//scene.AddGameObject(std::move(to));
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
