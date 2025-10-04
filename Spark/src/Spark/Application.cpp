#include "skpch.h"
#include "Application.h"

#include "Events/ApplicationEvent.h"
#include "Log.h"
namespace Spark {
	Application::Application()
	{
		m_Window =std::unique_ptr<Window>(Window::Create(WindowProps()));
	}

	Application::~Application()
	{
	}

	void Application::Run() {
		while (m_Running) {
			m_Window->OnUpdate();
		};
	}
}