#include <Spark.h>

#include <stdio.h>

class ExampleLayer : public Spark::Layer {
public:
	ExampleLayer(): Layer("Example")
	{

	}

	void OnUpdate() override {
		//SK_INFO("ExampleLayer::Update");
	}

	void OnEvent(Spark::Event& event) override {
		//SK_TRACE("{0}", event);
	}
};
class Sandbox : public Spark::Application {
public:
	Sandbox() {
		PushLayer(new ExampleLayer());
		PushOverlay(new Spark::ImGuiLayer());
	}

	~Sandbox() {

	}
};

Spark::Application* Spark::CreateApplication() {
	return new Sandbox();
}