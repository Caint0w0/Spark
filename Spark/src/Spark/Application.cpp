#include "skpch.h"
#include "Application.h"


#include "Log.h"

#include <GLFW/glfw3.h>
namespace Spark {

#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)
	Application::Application()
	{
		m_Window =std::unique_ptr<Window>(Window::Create(WindowProps()));
		m_Window->SetEventCallback(std::bind(&Application::OnEvent, this, std::placeholders::_1));
	}

	Application::~Application()
	{
	}

	void Application::OnEvent(Event& e) {
		EventDispatcher dispatcher(e);
		
		if (e.GetEventType() == EventType::WindowResize) {
			dispatcher.Dispatch<WindowResizeEvent>(std::bind(&Application::OnWindowResize, this, std::placeholders::_1));
			SK_CORE_TRACE("{0}", e);
		}
		else if (e.GetEventType() == EventType::WindowClose) {
			dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));
			SK_CORE_TRACE("{0}", e);
		}
	}

	bool Application::OnWindowResize(WindowResizeEvent& e) {

		return true;
	}

	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		m_Running = false;
		return true;
	}

	void Application::Run() {
		while (m_Running) {
			glClearColor(1, 1, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			m_Window->OnUpdate();
		};
	}
}