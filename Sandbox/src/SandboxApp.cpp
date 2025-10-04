#include <Spark.h>

#include <stdio.h>
class Sandbox : public Spark::Application {
public:
	Sandbox() {

	}

	~Sandbox() {

	}
};

Spark::Application* Spark::CreateApplication() {
	return new Sandbox();
}