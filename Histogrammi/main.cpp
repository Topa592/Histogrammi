#include "Histogram.h"
#include "RandomEintegerGenerator.h"
#include <iostream>

void print(Hist::Histogram& hist) {
	for (Hist::EInteger e : hist.eIntegers) {
		std::cout << e << " ";
	}
	std::cout << std::endl;
}

int main() {
	std::unique_ptr<Hist::Logger> logPointer = std::make_unique<Hist::Logger>();
	Hist::Histogram hist(std::move(logPointer));
	Hist::RandomEintegerGenerator gen;
	for (int i = 0; i < 20; i++) {
		hist.add(gen());
	}
	print(hist);

	std::cout << "Mode: " << hist.getMode() << "\nMin: " << hist.getMinValue() << "\nMax: " << hist.getMaxValue() << std::endl;
}