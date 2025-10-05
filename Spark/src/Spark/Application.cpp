#include "skpch.h"
#include "Application.h"

//#include <chrono>
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

	void Application::Tick() {
		glClearColor(1, 1, 1, 1);
		glClear(GL_COLOR_BUFFER_BIT);

		for (Layer* layer : m_LayerStack) {
			layer->OnUpdate();
		}

		m_Window->OnUpdate();
		
	}

	void Application::Run() {

		//using namespace std::chrono;
		//constexpr duration<double, std::milli> interval(1000.0 / 60.0); // 16.67ms
		//
		//auto next_start = steady_clock::now() + interval;
		//int counter = 0;
		while (m_Running) {
			/*auto start = steady_clock::now();

			counter++;*/

			Tick();
			//if (counter >= 60) {
			//	counter = 0;
			//	SK_CORE_INFO("OnTick");
			//}
		
			//// 计算并等待直到下一个时间点
			//next_start += interval;
			//std::this_thread::sleep_until(next_start);
		};
	}

	void Application::OnEvent(Event& e) {
		EventDispatcher dispatcher(e);
		
		if (e.GetEventType() == EventType::WindowResize) {
			dispatcher.Dispatch<WindowResizeEvent>(std::bind(&Application::OnWindowResize, this, std::placeholders::_1));
			//SK_CORE_TRACE("{0}", e);
		}
		else if (e.GetEventType() == EventType::WindowClose) {
			dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));
			//SK_CORE_TRACE("{0}", e);
		}

		for (auto it = m_LayerStack.end(); it != m_LayerStack.begin();) {//自顶向下传递事件
			(*--it)->OnEvent(e);
			if (e.Handled) {//若标记为Handled，则拦截事件的传递
				break;
			}
		}
	}

	void Application::PushLayer(Layer* layer)
	{
		m_LayerStack.PushLayer(layer);
	}

	void Application::PushOverlay(Layer* layer)
	{
		m_LayerStack.PushOverlay(layer);
	}

	bool Application::OnWindowResize(WindowResizeEvent& e) {

		return true;
	}

	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		m_Running = false;
		return true;
	}

}