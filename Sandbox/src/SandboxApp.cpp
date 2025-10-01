#include <Spark.h>

#include <stdio.h>
class Sandbox : public Spark::Application {
public:
	Sandbox() {

	}

	~Sandbox() {

	}

	void Run()override {
		int i = 0;
		while (true) {
			i++;
			if (i >= 1000000000) {
				printf("Running\n");
				i = 0;
			}
		}
	}
};

Spark::Application* Spark::CreateApplication() {
	return new Sandbox();
}