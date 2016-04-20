/*
 * Defines class timer for measuring computing times. Implemented
 * using the standard clock function from ctime.
 * */

/*
 *  * Copyright (c) 1997 Rensselaer Polytechnic Institute
 *   */

#ifndef COMPLEXITY_TIMER_HPP
#define COMPLEXITY_TIMER_HPP

#include <vector>
#include <ctime>

class timer
{

	protected:
		double start, finish;

	public:
		std::vector<double> times;

		void record() {
			times.push_back(time());
		}
		void reset_vectors() {
			times.erase(times.begin(), times.end());
		}
		void restart() { start = clock(); }
		void stop() { finish = clock(); }
		double time() const { return ((double)(finish - start))/CLOCKS_PER_SEC; }

};

#endif
