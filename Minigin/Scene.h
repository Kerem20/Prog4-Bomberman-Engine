#pragma once
#include <memory>
#include <string>
#include <vector>

namespace dae
{
	class Scene final
	{
	public:
		void FixedUpdate();
		void Update();
		void Render() const;

		~Scene() = default;
		Scene(const Scene& other) = delete;
		Scene(Scene&& other) = delete;
		Scene& operator=(const Scene& other) = delete;
		Scene& operator=(Scene&& other) = delete;

	private:
		friend class SceneManager;
		explicit Scene() = default;
	};

}