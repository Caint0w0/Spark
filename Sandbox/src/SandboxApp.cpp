#include <Spark.h>

#include "imgui/imgui.h"

class ExampleLayer : public Spark::Layer {
public:
	ExampleLayer(): Layer("Example")
	{

	}

	void OnUpdate() override {
		//SK_INFO("ExampleLayer::Update");
		if (Spark::Input::IsKeyPressed(SK_KEY_TAB))
			SK_TRACE("Tab key is pressed (poll)!");
	}

	virtual void OnImGuiRender() override
	{
		/*ImGui::Begin("Test");
		ImGui::Text("Hello World"); 
		ImGui::End();  */
	}


	void OnEvent(Spark::Event& event) override {
		//SK_TRACE("{0}", event);
		if (event.GetEventType() == Spark::EventType::KeyPressed)
		{
			Spark::KeyPressedEvent& e = (Spark::KeyPressedEvent&)event;
			if (e.GetKeyCode() == SK_KEY_TAB)
				SK_TRACE("Tab key is pressed (event)!");
			SK_TRACE("{0}", (char)e.GetKeyCode());
		}
	}
};

class Sandbox : public Spark::Application {
public:
	Sandbox() {
		PushLayer(new ExampleLayer());
	}
	~Sandbox() {

	}
};

Spark::Application* Spark::CreateApplication() {
	return new Sandbox();
}