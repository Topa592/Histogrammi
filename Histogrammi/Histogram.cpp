#include "HistogramBase.h"
#include "Histogram.h"
#include <algorithm>

namespace Hist {
	HistogramBase::HistogramBase(std::unique_ptr<Logger> log) {
		m_log = std::move(log);
	}

	HistogramBase::HistogramBase(const HistogramBase& hist) {
		
	}

	HistogramBase::HistogramBase(HistogramBase&& hist) {
		
	}

	HistogramBase::~HistogramBase() {

	}

	Histogram::Histogram(std::unique_ptr<Logger> log) : HistogramBase(std::move(log)) {

	}

	Histogram::Histogram(const Histogram& hist) : HistogramBase(hist) {
		this->eIntegers = hist.eIntegers;
	}

	Histogram::Histogram(Histogram&& hist) : HistogramBase(hist) {
		this->eIntegers = hist.eIntegers;
	}
	
	Histogram::~Histogram() {

	}

	void Histogram::add(EInteger e) {
		eIntegers.push_back(e);
	}

	EInteger Histogram::getMode() const {
		if (eIntegers.empty()) throw "empty";
		std::vector<EInteger> copy = eIntegers;
		std::sort(std::begin(copy), std::end(copy));
		EInteger current = copy.front();
		int currentCount = 0;
		EInteger mostCommon = copy.front();
		int mostCommonCount = 0;
		for (int i = 0; i < copy.size(); i++) {
			EInteger e = copy[i];
			if (e == current) {
				currentCount++;
				continue;
			}
			if (currentCount > mostCommonCount) {
				mostCommonCount = currentCount;
				mostCommon = current;
			}
			current = e;
			currentCount = 1;
		}

		return mostCommon;
	}

	EInteger Histogram::getMinValue() const {
		if (eIntegers.empty()) throw "empty";
		EInteger smallest = EInteger::Four;
		for (const EInteger& e : eIntegers) {
			if (e < smallest) {
				smallest = e;
			}
		}
		return smallest;
	}

	EInteger Histogram::getMaxValue() const {
		if (eIntegers.empty()) throw "empty";
		EInteger largest = EInteger::Zero;
		for (const EInteger& e : eIntegers) {
			if (e > largest) {
				largest = e;
			}
		}
		return largest;
	}
}