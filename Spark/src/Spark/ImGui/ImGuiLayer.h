#pragma once

#include "Spark/Layer.h"

#include  "Spark/Events/KeyEvent.h"
#include "Spark/Events/MouseEvent.h"
#include "Spark/Events/ApplicationEvent.h"
namespace Spark {

	class SPARK_API ImGuiLayer : public Layer {
	public:
		ImGuiLayer();
		~ImGuiLayer();

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnImGuiRender() override;

		void Begin();
		void End();
	private:
		float m_Time = 0.0f;
	};
}
