#pragma once

#include <stdlib.h>
#include <ctime>
#include <sys/time.h>

class Rnd
{
    public:
		static inline void randomize() {

            struct timeval t1;
            gettimeofday(&t1, NULL);
            srand(t1.tv_usec * t1.tv_sec);

		}
		static inline void randomize(unsigned int seed) {

			srand(seed);
			rand();

		}

	public:
        static inline bool _bool() {
            return static_cast<bool>(Rnd::_int(1));
        }
		static inline int _int(int max) {

			return rand() % (max + 1);

		}
		static inline int _int(int min, int max) {

			return min + rand() % (max + 1 - min) ;

		}
		static inline double _double() {

			return ((double)rand() / (double)RAND_MAX);
        }
};


/* Utilisation
/start code
    Rnd::randomize(unsigned int seed) // pour avoir toujours le même rnd
    Rnd::ranomize(); Pour qu'il soit toujours different
    Rnd::_int(3)                renvoie un int entre 0 et 3
    Rnd::_int(-4,4);           renvoie un int entre -4 et 4
    Rnd::_double()          renvoie un double entre 0 et 1
/end code
*/

