
#ifndef GAMETEST_SRC_GUI_GUI_H_
#define GAMETEST_SRC_GUI_GUI_H_

#include <SFML/Graphics.hpp>
#include "SFML/Window/Joystick.hpp"

#include <imgui-SFML.h>
#include <imgui.h>

class Gui
{
public:
	Gui(const Gui&) = delete;
	auto operator=(const Gui&) = delete;

	Gui() = default;
public:

	static auto setupStyle() -> void
	{

	}

	auto init() -> void
	{
		ImGuiWindowFlags flags = ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove |
			ImGuiWindowFlags_NoTitleBar;

		ImGui::SetNextWindowSize(ImVec2(2560, 10));
		ImGui::SetNextWindowPos(ImVec2(0, 0));
		ImGui::Begin("Inform Panel", nullptr, flags);

		ImGui::Text("Cursor Position: { x:%d, y:%d }",sf::Mouse::getPosition().x,
			sf::Mouse::getPosition().y);

		ImGui::SetCursorPos(ImVec2(2160, 10));
		ImGui::Text("Joystick is");
		if (!sf::Joystick::isConnected(0))
		{
			ImGui::SetCursorPos(ImVec2(2250, 10));
			ImGui::TextColored(ImVec4(1.0, 0.0, 0.0, 1.0), "not connected");
		}
		else
		{
			ImGui::SetCursorPos(ImVec2(2245, 10));
			ImGui::TextColored(ImVec4(0.0, 1.0, 0.0, 1.0), "connected");
		}
		ImGui::SetCursorPos(ImVec2(2460, 10));
		ImGui::Text("fps: %.2f", this->fps);
		ImGui::End();
	}

	auto setFps(const double& frames) -> void { this->fps = frames; }
private:
	double fps{0.0};

} gui;

#endif //GAMETEST_SRC_GUI_GUI_H_
