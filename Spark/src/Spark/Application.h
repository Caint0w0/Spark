#pragma once

#include "Core.h"
#include "Window.h"
#include "Events/ApplicationEvent.h"

#include "Spark/LayerStack.h"
#include "Spark/ImGui/ImGuiLayer.h"

#include "Spark/Renderer/Shader.h"
#include "Spark/Renderer/Buffer.h"
#include "Spark/Renderer/VertexArray.h"
namespace Spark {
	class SPARK_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void Tick();

		void OnEvent(Event& e);
		
		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		inline static Application& Get() { return *s_Instance; }
		inline Window& GetWindow() { return *m_Window; }

	private:
		bool OnWindowResize(WindowResizeEvent& e);
		bool OnWindowClose(WindowCloseEvent& e);
		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;

		LayerStack m_LayerStack;

		std::shared_ptr<Shader> m_Shader;
		std::shared_ptr<VertexArray> m_VertexArray;

		std::shared_ptr<Shader> m_BlueShader;
		std::shared_ptr<VertexArray> m_SquareVA;
	private:
		static Application* s_Instance;
	};

	// To be defined in CLIENT
	Application* CreateApplication();
}
